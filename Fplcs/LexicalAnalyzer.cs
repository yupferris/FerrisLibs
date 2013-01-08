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
                RegexParser regexParser = new RegexParser();
                NfaFragment fragment = compileRegexParserAstNode(regexParser.Parse(kvp.Value.Regex), kvp.Value.RegexOptions);
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

        public List<Token> Process(string input)
        {
            if (!finalized) finalize();

            var tokens = new List<Token>();

            var matchList1 = new MatchList(states.Count);
            var matchList2 = new MatchList(states.Count);

            foreach (var state in states) state.lastInputPos = -1;

            for (int inputPos = 0; inputPos < input.Length; )
            {
                matchList1.Clear();
                matchList2.Clear();
                MatchList currentMatchList = matchList1;
                MatchList nextMatchList = matchList2;
                currentMatchList.AddState(startState, inputPos);

                int startPos = inputPos;
                for (; inputPos < input.Length; inputPos++)
                {
                    char c = input[inputPos];

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
                }

                State acceptingState = null;
                for (int i = 0; i < currentMatchList.Count; i++)
                {
                    var newState = currentMatchList.States[i];
                    if (newState.Accepting)
                    {
                        if (acceptingState != null &&
                            (!EqualityComparer<TTokenType>.Default.Equals(newState.AcceptingTokenType, acceptingState.AcceptingTokenType) &&
                            (!precedenceNodes.ContainsKey(acceptingState.AcceptingTokenType) ||
                            !precedenceNodes.ContainsKey(newState.AcceptingTokenType) ||
                            !precedenceNodes[acceptingState.AcceptingTokenType].IsParent(precedenceNodes[newState.AcceptingTokenType]))))
                        {
                            throw new Exception("Ambiguous token definitions found with no applicable precedence rule");
                        }
                        else
                        {
                            acceptingState = newState;
                        }
                    }
                }
                if (acceptingState != null)
                {
                    Token t = tokenDefinitions[acceptingState.AcceptingTokenType].TokenCallback != null ? tokenDefinitions[acceptingState.AcceptingTokenType].TokenCallback(input, startPos, inputPos - startPos) : new Token(acceptingState.AcceptingTokenType);
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
