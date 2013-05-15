using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fplcs
{
    public partial class LexicalAnalyzer<TTokenType>
    {
        class State
        {
            public bool Accepting;
            public readonly TTokenType AcceptingTokenType;

            public readonly List<char> NextChars = new List<char>();
            public readonly List<State> NextStates = new List<State>();

            public int lastInputPos;

            public State()
            {
                Accepting = false;
            }

            public State(TTokenType acceptingTokenType)
            {
                Accepting = true;
                AcceptingTokenType = acceptingTokenType;
            }

            public void AddTransition(char c, State state)
            {
                NextChars.Add(c);
                NextStates.Add(state);
            }

            public void AddEpsilonTransition(State state)
            {
                AddTransition('\0', state);
            }
        }

        readonly List<State> states = new List<State>();

        State CreateState()
        {
            var state = new State();
            states.Add(state);
            return state;
        }

        State CreateState(TTokenType acceptingTokenType)
        {
            var state = new State(acceptingTokenType);
            states.Add(state);
            return state;
        }
    }
}
