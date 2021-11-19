#pragma once

#include <vector>
#include <string>

#include "Game.h"

class Scrabble : public Game {
    private:
        std::vector<std::string> m_words;
        char RandChar();
        bool IsInt(std::string str);
    public:
        Scrabble();
        virtual void Run() override;
    protected:
        //
};