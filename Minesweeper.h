#pragma once

#include "Game.h"

class Minesweeper : public Game{
    public:
        Minesweeper(){}

        virtual void Run() override;
};