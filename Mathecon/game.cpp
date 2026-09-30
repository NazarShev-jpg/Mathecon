#include "game.h"
#include <iostream>
using namespace std;

// ---- Эффекты операций ----

static bool opAdd(int& number, int value)
{
    number += value;
    return true;
}

static bool opSubtract(int& number, int value)
{
    number -= value;
    return true;
}

static bool opMultiply(int& number, int value)
{
    number *= value;
    return true;
}

static bool opDivide(int& number, int value)
{
    if (value == 0)
    {
        return false;
    }
    number /= value;
    return true;
}

static bool opModulo(int& number, int value)
{
    if (value == 0)
    {
        return false;
    }
    number %= value;
    return true;
}

// ---- Таблица операций: новая операция = новая строка ----

static const Operation operations[] = {
    // знак, эффект,    сообщение при отказе,                    цена, уровень
    {'+', opAdd,        nullptr,                                 0,    1},
    {'-', opSubtract,   nullptr,                                 0,    1},
    {'*', opMultiply,   nullptr,                                 0,    1},
    {'/', opDivide,     "Nelzya delit na nol! Hod propushchen.", 0,    1},
    {'%', opModulo,     "Nelzya delit na nol! Hod propushchen.", 0,    1},
};

static const Operation* findOperation(char symbol)
{
    for (const Operation& operation : operations)
    {
        if (operation.symbol == symbol)
        {
            return &operation;
        }
    }
    return nullptr;
}

// ---- Состояние игры ----

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
    const Operation* operation = findOperation(op);

    if (operation == nullptr)
    {
        cout << "Neizvestnyi znak! Hod propushchen.\n";
        return;
    }

    if (!operation->apply(state.enemyNumber, value))
    {
        cout << operation->failMessage << "\n";
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