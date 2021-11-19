#pragma once

#include "Game.h"

class Hangman : public Game{
    public:
        Hangman(){}
            
        virtual void Run() override;
};