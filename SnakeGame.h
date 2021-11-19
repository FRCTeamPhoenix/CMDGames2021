#pragma once

#include "Game.h"

class SnakeGame : public Game{
    public:
        SnakeGame(){}

        virtual void Run() override;
        
    private:
    
        void Initialization();
        void DrawGrid();
        void DataInput();
        void Things();
};