#pragma once

struct GameState
{
    int level;
    int score;
    int enemyNumber;
    int distance;
};

GameState createInitialState();
void printStatus(const GameState& state);
void applyOperation(GameState& state, char op, int value);
void advanceLevel(GameState& state);
bool isWin(const GameState& state);
bool isGameOver(const GameState& state);