#pragma once

#include "Game.h"

#define Beginner 0
#define Intermediate 1
#define Advanced 2
#define Custom 3
#define maxside 10
#define maxmines 99
#define movesize 526

class Minesweeper : public Game{
    public:
        Minesweeper(){}

        virtual void Run() override;
    private:
        bool IsValid(int row, int column);
        bool IsMine(int row, int column, char board[][maxside]);
        void DoTurn(int *x, int *y);
        void DisplayBoard (char board[][maxside]);
        int CountMines(int row, int col, int mineboard[][2], char realBoard[][maxside]);
        void PlaceMines(int mineboard[][2], char realBoard[][maxside]);
        void Init(char realBoard[][maxside], char board[][maxside]);
        void ReplaceMine (int row, int col, char board[][maxside]);
        bool PlayUtil(char gameboard[][maxside], char realboard[][maxside], int mineboard[][2], int row, int col, int *movesLeft);
        void Play();
        void ChooseDiff (int diff);

};