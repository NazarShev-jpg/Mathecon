#pragma once

struct ParsedTurn
{
    bool valid;
    char op;
    int value;
};

ParsedTurn readTurn();