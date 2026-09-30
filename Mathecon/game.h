#pragma once

struct GameState
{
    int level;
    int score;
    int enemyNumber;
    int distance;
};

// Одна операция игры: знак, эффект и данные для будущего магазина
struct Operation
{
    char symbol;
    bool (*apply)(int& number, int value); // false = операцию применить нельзя
    const char* failMessage;               // что показать, если вернулось false
    int cost;                              // цена в магазине (пока не используется)
    int unlockLevel;                       // с какого уровня доступна (пока не используется)
};

GameState createInitialState();
void printStatus(const GameState& state);
void applyOperation(GameState& state, char op, int value);
void advanceLevel(GameState& state);
bool isWin(const GameState& state);
bool isGameOver(const GameState& state);