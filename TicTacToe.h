#pragma once

#include "Game.h"

class TicTacToe : public Game{
    public:
        TicTacToe(){}
        
        virtual void Run() override;
    private:
        void Board();
        void Play();
        bool Win();
};