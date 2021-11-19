#pragma once

#include "Game.h"



class Minesweeper : public Game{
    public:
        Minesweeper(){}

        virtual void Run() override;
    private:
        const static int BEGINNER = 0;
        const static int INTERMEDIATE = 1;
        const static int ADVANCED = 2;
        const static int CUSTOM = 3;
        const static int MAXSIDE = 10;
        const static int MAXMINES = 99;
        const static int MOVESIZE = 526;

        bool IsValid(int row, int column);
        bool IsMine(int row, int column, char board[][MAXSIDE]);
        void DoTurn(int *x, int *y);
        void DisplayBoard (char board[][MAXSIDE]);
        int CountMines(int row, int col, int mineboard[][2], char realBoard[][MAXSIDE]);
        void PlaceMines(int mineboard[][2], char realBoard[][MAXSIDE]);
        void Init(char realBoard[][MAXSIDE], char board[][MAXSIDE]);
        void ReplaceMine (int row, int col, char board[][MAXSIDE]);
        bool PlayUtil(char gameboard[][MAXSIDE], char realboard[][MAXSIDE], int mineboard[][2], int row, int col, int *movesLeft);
        void Play();
        void ChooseDiff (int diff);

};