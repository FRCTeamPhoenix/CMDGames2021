#pragma once

#include "Game.h"

class Life : public Game{
    public:
        Life(){}

        virtual void Run() override;
    private:
        void Simulate();
        void PrintArray(char a[80][80]);
        int CountAdjacent(int x, int y);
};