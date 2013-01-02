using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fplcs
{
    public partial class LexicalAnalyzer<TTokenType>
    {
        class MatchList
        {
            public State[] States = null;

            int size;
            int count;

            public int Count { get { return count; } }

            public MatchList(int size)
            {
                this.size = size;
                States = new State[size];
                Clear();
            }

            public void Clear()
            {
                count = 0;
            }

            public void AddState(State state, int inputPos)
            {
                if (state.lastInputPos == inputPos) return;

                state.lastInputPos = inputPos;
                States[count] = state;
                count++;
                for (int i = 0; i < state.NextChars.Count; i++)
                {
                    if (state.NextChars[i] == '\0') AddState(state.NextStates[i], inputPos);
                }
            }
        }
    }
}
