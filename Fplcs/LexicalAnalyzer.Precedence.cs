using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fplcs
{
    public partial class LexicalAnalyzer<TTokenType>
    {
        class PrecedenceNode
        {
            public readonly TTokenType Type;
            public readonly List<PrecedenceNode> Parents = new List<PrecedenceNode>();
            public readonly List<PrecedenceNode> Children = new List<PrecedenceNode>();

            public PrecedenceNode(TTokenType type)
            {
                Type = type;
            }

            public static void Connect(PrecedenceNode parent, PrecedenceNode child)
            {
                parent.Children.Add(child);
                child.Parents.Add(parent);
            }

            public bool IsParent(PrecedenceNode pn)
            {
                foreach (PrecedenceNode parent in Parents)
                {
                    if (parent == pn || parent.IsParent(pn)) return true;
                }
                return false;
            }

            public bool IsChild(PrecedenceNode pn)
            {
                foreach (PrecedenceNode child in Children)
                {
                    if (child == pn || child.IsChild(pn)) return true;
                }
                return false;
            }
        }

        readonly Dictionary<TTokenType, PrecedenceNode> precedenceNodes = new Dictionary<TTokenType, PrecedenceNode>();

        PrecedenceNode createPrecedenceNode(TTokenType type)
        {
            var pn = new PrecedenceNode(type);
            precedenceNodes.Add(type, pn);
            return pn;
        }

        public void AddPrecedenceRule(TTokenType firstType, TTokenType secondType)
        {
            var first = precedenceNodes.ContainsKey(firstType) ? precedenceNodes[firstType] : null;
            var second = precedenceNodes.ContainsKey(secondType) ? precedenceNodes[secondType] : null;
            if (first == null || second == null)
            {
                first = first ?? createPrecedenceNode(firstType);
                second = second ?? createPrecedenceNode(secondType);
            }
            else
            {
                if (first.IsParent(second)) throw new Exception("Conflicting precedence rule detected");
                if (first.IsChild(second)) return;
            }
            PrecedenceNode.Connect(first, second);
        }
    }
}
