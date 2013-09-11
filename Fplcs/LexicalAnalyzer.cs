using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fplcs
{
    public partial class LexicalAnalyzer<TTokenType>
    {
        bool finalized = false;

        State startState = null;

        void finalize()
        {
            startState = CreateState();
            foreach (var kvp in tokenDefinitions)
            {
                var regexParser = new RegexParser();
                var fragment = compileRegexParserAstNode(regexParser.Parse(kvp.Value.Regex), kvp.Value.RegexOptions);
                fragment.ConnectEnds(CreateState(kvp.Key));
                startState.AddEpsilonTransition(fragment.Start);
            }

            finalized = true;
        }

        void unfinalize()
        {
            finalized = false;
            startState = null;
            states.Clear();
        }

        public List<Token> Process(string input, string fileName)
        {
            if (!finalized) finalize();

            var tokens = new List<Token>();

            var matchList1 = new MatchList(states.Count);
            var matchList2 = new MatchList(states.Count);

            foreach (var state in states) state.lastInputPos = -1;

            int line = 1;
            int position = 1;

            for (int inputPos = 0; inputPos < input.Length; )
            {
                int startLine = line;
                int startPosition = position;

                matchList1.Clear();
                matchList2.Clear();
                var currentMatchList = matchList1;
                var nextMatchList = matchList2;
                currentMatchList.AddState(startState, inputPos);

                int startPos = inputPos;
                for (; inputPos < input.Length; inputPos++)
                {
                    var c = input[inputPos];

                    nextMatchList.Clear();
                    for (int i = 0; i < currentMatchList.Count; i++)
                    {
                        var currentState = currentMatchList.States[i];
                        for (int j = 0; j < currentState.NextChars.Count; j++)
                        {
                            if (currentState.NextChars[j] == c) nextMatchList.AddState(currentState.NextStates[j], inputPos + 1);
                        }
                    }

                    if (nextMatchList.Count == 0) break;

                    if (currentMatchList == matchList1)
                    {
                        currentMatchList = matchList2;
                        nextMatchList = matchList1;
                    }
                    else
                    {
                        currentMatchList = matchList1;
                        nextMatchList = matchList2;
                    }

                    if (c == '\n')
                    {
                        line++;
                        position = 1;
                    }
                    else
                    {
                        position++;
                    }
                }

                State acceptingState = null;
                for (int i = 0; i < currentMatchList.Count; i++)
                {
                    var newState = currentMatchList.States[i];
                    if (newState.Accepting)
                    {
                        if (acceptingState == null)
                        {
                            acceptingState = newState;
                        }
                        else
                        {
                            var acceptingType = acceptingState.AcceptingTokenType;
                            var newType = newState.AcceptingTokenType;
                            if (!EqualityComparer<TTokenType>.Default.Equals(newType, acceptingType))
                            {
                                PrecedenceNode acceptingNode;
                                PrecedenceNode newNode;
                                precedenceNodes.TryGetValue(acceptingType, out acceptingNode);
                                precedenceNodes.TryGetValue(newType, out newNode);
                                if (acceptingNode == null || newNode == null || !acceptingNode.IsParentOrChild(newNode))
                                {
                                    throw new Exception("Ambiguous token definitions found with no applicable precedence rule");
                                }
                                else if (acceptingNode.IsParent(newNode))
                                {
                                    acceptingState = newState;
                                }
                            }
                        }
                    }
                }
                if (acceptingState != null)
                {
                    var source = new Source(fileName, startLine, startPosition);
                    var t = tokenDefinitions[acceptingState.AcceptingTokenType].TokenCallback != null ? tokenDefinitions[acceptingState.AcceptingTokenType].TokenCallback(input, startPos, inputPos - startPos, source) : new Token(acceptingState.AcceptingTokenType, source);
                    if (t != null) tokens.Add(t);
                }
                else
                {
                    throw new Exception("Unrecognized token");
                }
            }

            return tokens;
        }
    }
}
