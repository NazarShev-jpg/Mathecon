#include "game.h"
#include "input.h"
#include <iostream>
using namespace std;

int main()
{
    GameState state = createInitialState();

    cout << "=== MATHECON ===\n";
    cout << "Obnuli chislo do togo, kak vrag doidet do tebya!\n\n";

    while (true)
    {
        printStatus(state);

        if (isWin(state))
        {
            advanceLevel(state);
            continue;
        }

        if (isGameOver(state))
        {
            cout << "\nGAME OVER. Vrag dostig tebya.\n";
            cout << "Uroven: " << state.level << " | Itogovye ochki: " << state.score << "\n";
            break;
        }

        ParsedTurn turn = readTurn();
        if (turn.valid)
        {
            applyOperation(state, turn.op, turn.value);
            cout << "\n";
        }

        state.distance--;
    }

    return 0;
}