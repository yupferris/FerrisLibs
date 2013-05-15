using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fplcs
{
    public partial class LexicalAnalyzer<TTokenType>
    {
        class NfaFragment
        {
            public State Start = null;
            public List<State> Ends = new List<State>();

            public void ConnectEnds(State state)
            {
                foreach (State end in Ends) end.AddEpsilonTransition(state);
            }
        }

        NfaFragment compileRegexParserAstNode(RegexParser.AstNode node, RegexOptions regexOptions)
        {
            var fragment = new NfaFragment();

            switch (node.Type)
            {
                case RegexParser.AstNodeType.Default:
                    for (int i = 0; i < node.Children.Count; i++)
                    {
                        var childFragment = compileRegexParserAstNode(node.Children[i], regexOptions);
                        if (i == 0)
                        {
                            fragment.Start = childFragment.Start;
                        }
                        else
                        {
                            fragment.ConnectEnds(childFragment.Start);
                        }
                        fragment.Ends = childFragment.Ends;
                    }
                    break;

                case RegexParser.AstNodeType.Char:
                    {
                        fragment.Start = CreateState();
                        var end = CreateState();
                        var c = (node as RegexParser.CharAstNode).Char;
                        fragment.Start.AddTransition(c, end);
                        if ((regexOptions & RegexOptions.IgnoreCase) != RegexOptions.None) fragment.Start.AddTransition(char.IsUpper(c) ? char.ToLower(c) : char.ToUpper(c), end);
                        fragment.Ends.Add(end);
                        break;
                    }

                case RegexParser.AstNodeType.Or:
                    {
                        fragment.Start = CreateState();
                        var orNode = (node as RegexParser.OrAstNode);
                        var leftFragment = compileRegexParserAstNode(orNode.Left, regexOptions);
                        var rightFragment = compileRegexParserAstNode(orNode.Right, regexOptions);
                        fragment.Start.AddEpsilonTransition(leftFragment.Start);
                        fragment.Start.AddEpsilonTransition(rightFragment.Start);
                        fragment.Ends = new List<State>();
                        fragment.Ends.AddRange(leftFragment.Ends);
                        fragment.Ends.AddRange(rightFragment.Ends);
                        break;
                    }

                case RegexParser.AstNodeType.ZeroOrMore:
                    fragment = compileRegexParserAstNode((node as RegexParser.ExpressionAstNode).Expression, regexOptions);
                    fragment.ConnectEnds(fragment.Start);
                    fragment.Ends.Add(fragment.Start);
                    break;

                case RegexParser.AstNodeType.OneOrMore:
                    fragment = compileRegexParserAstNode((node as RegexParser.ExpressionAstNode).Expression, regexOptions);
                    fragment.ConnectEnds(fragment.Start);
                    break;

                case RegexParser.AstNodeType.ZeroOrOne:
                    fragment = compileRegexParserAstNode((node as RegexParser.ExpressionAstNode).Expression, regexOptions);
                    fragment.Ends.Add(fragment.Start);
                    break;
            }

            return fragment;
        }
    }
}
