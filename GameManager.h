#pragma once

#include "Game.h"
#include <unordered_map>

using namespace std;

class GameManager{
    public:
        GameManager();

        void Run();

    private:
        void AddGames();

        unordered_map<string, Game*> m_games;
};