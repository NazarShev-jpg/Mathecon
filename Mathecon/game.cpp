#include "game.h"
#include <iostream>
using namespace std;

GameState createInitialState()
{
    GameState state;
    state.level = 1;
    state.score = 0;
    state.enemyNumber = 50;
    state.distance = 10;
    return state;
}

void printStatus(const GameState& state)
{
    cout << "Uroven: " << state.level << " | Ochki: " << state.score << "\n";
    cout << "Chislo: " << state.enemyNumber << " | Do stolknoveniya hodov: " << state.distance << "\n";
}

void applyOperation(GameState& state, char op, int value)
{
    switch (op)
    {
    case '+':
        state.enemyNumber += value;
        break;
    case '-':
        state.enemyNumber -= value;
        break;
    case '*':
        state.enemyNumber *= value;
        break;
    case '/':
        if (value == 0)
        {
            cout << "Nelzya delit na nol! Hod propushchen.\n";
        }
        else
        {
            state.enemyNumber /= value;
        }
        break;
    default:
        cout << "Neizvestnyi znak! Hod propushchen.\n";
        break;
    }
}

void advanceLevel(GameState& state)
{
    state.score += state.distance * 10;
    cout << "\nUroven " << state.level << " proiden! +" << state.distance * 10 << " ochkov.\n\n";

    state.level++;
    state.enemyNumber = 50 + (state.level - 1) * 20;
    state.distance = 10 + (state.level - 1) * 2;
}

bool isWin(const GameState& state)
{
    return state.enemyNumber == 0;
}

bool isGameOver(const GameState& state)
{
    return state.distance == 0;
}