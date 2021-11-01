#pragma once

#include <vector>
#include <string>

#include "Game.h"

class Scrabble : public Game {
    private:
        std::vector<std::string> m_words;
        //std::string words;
    public:
        Scrabble(){}
        virtual void Run() override;
    protected:
        //
};