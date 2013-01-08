using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fplcs
{
    public partial class LexicalAnalyzer<TTokenType>
    {
        public enum RegexOptions
        {
            None = 0,
            IgnoreCase = 1,
        }

        class RegexParser
        {
            public enum AstNodeType
            {
                Default,
                Char,
                Or,
                ZeroOrMore,
                OneOrMore,
                ZeroOrOne,
            }

            public class AstNode
            {
                public AstNodeType Type;
                public List<AstNode> Children = new List<AstNode>();
                public AstNode(AstNodeType type = AstNodeType.Default)
                {
                    Type = type;
                }
            }

            public class CharAstNode : AstNode
            {
                public char Char;
                public CharAstNode(char c)
                    : base(AstNodeType.Char)
                {
                    Char = c;
                }
            }

            public class OrAstNode : AstNode
            {
                public AstNode Left { get { return Children[0]; } }
                public AstNode Right { get { return Children[1]; } }
                public OrAstNode(AstNode left, AstNode right)
                    : base(AstNodeType.Or)
                {
                    Children.Add(left);
                    Children.Add(right);
                }
            }

            public class ExpressionAstNode : AstNode
            {
                public AstNode Expression { get { return Children[0]; } }
                public ExpressionAstNode(AstNodeType type, AstNode expression)
                    : base(type)
                {
                    Children.Add(expression);
                }
            }

            public class ZeroOrMoreAstNode : ExpressionAstNode
            {
                public ZeroOrMoreAstNode(AstNode expression)
                    : base(AstNodeType.ZeroOrMore, expression)
                {
                }
            }

            public class OneOrMoreAstNode : ExpressionAstNode
            {
                public OneOrMoreAstNode(AstNode expression)
                    : base(AstNodeType.OneOrMore, expression)
                {
                }
            }

            public class ZeroOrOneAstNode : ExpressionAstNode
            {
                public ZeroOrOneAstNode(AstNode expression)
                    : base(AstNodeType.ZeroOrOne, expression)
                {
                }
            }

            string input;
            int inputPos, parenLevel;

            public AstNode Parse(string input)
            {
                this.input = input;
                inputPos = parenLevel = 0;
                return parseExpression();
            }

            AstNode parseExpression()
            {
                AstNode node = new AstNode();

                while (inputPos < input.Length)
                {
                    bool specialReturn = false;
                    char currentChar = peekChar();
                    switch (currentChar)
                    {
                        case '(':
                            inputPos++;
                            parenLevel++;
                            node.Children.Add(parseExpression());
                            if (inputPos >= input.Length || peekChar() != ')') throw new Exception("Expected ')'");
                            inputPos++;
                            parenLevel--;
                            continue;

                        case ')':
                            if (parenLevel <= 0) throw new Exception("')' found with no preceeding '('");
                            specialReturn = true;
                            break;

                        case '|':
                            inputPos++;
                            node = new OrAstNode(node, parseExpression());
                            continue;

                        case '*':
                        case '+':
                        case '?':
                            {
                                if (node.Children.Count() == 0) throw new Exception("'" + currentChar + "' found with no preceeding expression");
                                inputPos++;
                                AstNode expression = node.Children[node.Children.Count - 1];
                                node.Children.RemoveAt(node.Children.Count - 1);
                                AstNode newNode;
                                switch (currentChar)
                                {
                                    case '*': newNode = new ZeroOrMoreAstNode(expression); break;
                                    case '+': newNode = new OneOrMoreAstNode(expression); break;
                                    case '?':
                                    default:
                                        newNode = new ZeroOrOneAstNode(expression); break;
                                }
                                node.Children.Add(newNode);
                                continue;
                            }

                        case '[':
                            {
                                inputPos++;
                                int startPos = inputPos;

                                bool negated = false;

                                List<char> chars = new List<char>();
                                bool complete = false;
                                for (; inputPos < input.Length && !complete; inputPos++)
                                {
                                    char c = peekChar();
                                    switch (c)
                                    {
                                        case ']':
                                            complete = true;
                                            break;

                                        case '-':
                                            {
                                                if (inputPos < input.Length - 1)
                                                {
                                                    inputPos++;
                                                    char startChar = chars[chars.Count - 1];
                                                    char endChar = peekChar();
                                                    if (endChar > startChar)
                                                    {
                                                        for (int i = startChar + 1; i <= endChar; i++)
                                                        {
                                                            if (!chars.Contains((char)i)) chars.Add((char)i);
                                                        }
                                                        break;
                                                    }
                                                }
                                                throw new Exception("Invalid character run");
                                            }

                                        case '\\':
                                            chars.Add(parseEscapeSequence(true));
                                            break;

                                        case '^':
                                            if (inputPos == startPos)
                                            {
                                                negated = true;
                                            }
                                            else
                                            {
                                                chars.Add(c);
                                            }
                                            break;

                                        default:
                                            chars.Add(c);
                                            break;
                                    }
                                }
                                if (!complete) throw new Exception("Expected ']'");
                                if (chars.Count == 0) throw new Exception("Cannot use empty character classes");

                                // TODO: Make special state type to handle character classes
                                List<AstNode> charNodes = new List<AstNode>();
                                if (negated)
                                {
                                    for (int i = 1; i < 256; i++)
                                    {
                                        if (!chars.Contains((char)i)) charNodes.Add(new CharAstNode((char)i));
                                    }
                                }
                                else
                                {
                                    for (int i = 0; i < chars.Count; i++) charNodes.Add(new CharAstNode(chars[i]));
                                }
                                AstNode classNode = charNodes[0];
                                for (int i = 1; i < charNodes.Count; i++) classNode = new OrAstNode(classNode, charNodes[i]);
                                node.Children.Add(classNode);
                                continue;
                            }

                        case '\\':
                            node.Children.Add(new CharAstNode(parseEscapeSequence()));
                            inputPos++;
                            continue;

                        case '.':
                            {
                                // TODO: See character node todo
                                inputPos++;
                                AstNode dotNode = new CharAstNode((char)1);
                                for (int i = 2; i < 256; i++) dotNode = new OrAstNode(dotNode, new CharAstNode((char)i));
                                node.Children.Add(dotNode);
                                continue;
                            }

                        default:
                            node.Children.Add(new CharAstNode(getNextChar()));
                            continue;
                    }
                    if (specialReturn) break;
                }

                if (node.Children.Count == 0) throw new Exception("Cannot use empty expressions");
                return node;
            }

            char parseEscapeSequence(bool inCharacterClass = false)
            {
                inputPos++;
                if (inputPos < input.Length)
                {
                    char c = peekChar();
                    switch (c)
                    {
                        case '\\':
                            return c;

                        case 't': return '\t';
                        case 'r': return '\r';
                        case 'n': return '\n';
                    }

                    if (inCharacterClass)
                    {
                        switch (c)
                        {
                            case ']':
                            case '-':
                                return c;
                        }
                    }
                    else
                    {
                        switch (c)
                        {
                            case '(':
                            case ')':
                            case '|':
                            case '*':
                            case '+':
                            case '?':
                            case '$':
                            case '[':
                            case '.':
                                return c;
                        }
                    }
                }
                if (!inCharacterClass) throw new Exception("Invalid character escape sequence");
                throw new Exception("Invalid character escape sequence in character class");
            }

            char peekChar(int offset = 0)
            {
                return input[inputPos + offset];
            }

            char getNextChar()
            {
                char ret = input[inputPos];
                inputPos++;
                return ret;
            }
        }
    }
}
