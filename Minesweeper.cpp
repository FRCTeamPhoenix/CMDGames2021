#include "Minesweeper.h"

#include <bits/stdc++.h>
#include <iostream>
#include <cstring>

using namespace std;
 
#define Beginner 0
#define Intermediate 1
#define Advanced 2
#define Custom 3
#define maxside 10
#define maxmines 99
#define movesize 526
 
int side; 
int mines;

bool IsValid(int row, int column) {
    if ((row >= 0) && (row < side) && (column >= 0) && (column < side)) {
        return true;
    } 
    else return false;
}

bool IsMine(int row, int column, char board[][maxside]) {
    if (board[row][column] == '*') return true;
    else return false;
}

void DoTurn(int *x, int *y) {
    printf("Enter your move (x, y): \n");
    scanf("%d %d", y, x);
}

void DisplayBoard (char board[][maxside]) {
    int i;
    int j;

    printf("    ");
    
    for (i = 0; i < side; i++) printf("%d ", i);
    
    printf("\n\n");
    
    for (i = 0; i < side; i++) {
        printf ("%d   ", i);

        for (j = 0; j < side; j++) printf("%c ", board[i][j]);

        printf("\n");
    }
    
    return;
}

int CountMines(int row, int col, int mineboard[][2], char realBoard[][maxside]) {
    int i;
    int mines = 0;

    if (IsValid (row - 1, col) == true)
    {
        if (IsMine (row - 1, col, realBoard) == true) mines++;
    }

    if (IsValid (row + 1, col) == true)
    {
        if (IsMine (row + 1, col, realBoard) == true) mines++;
    }

    if (IsValid (row, col + 1) == true)
    {
        if (IsMine (row, col + 1, realBoard) == true) mines++;
    }

    if (IsValid (row, col - 1) == true)
    {
        if (IsMine (row, col - 1, realBoard) == true) mines++;
    }

    if (IsValid (row - 1, col + 1) == true)
    {
        if (IsMine (row - 1, col + 1, realBoard) == true) mines++;
    }

    if (IsValid (row - 1, col - 1) == true)
    {
        if (IsMine (row - 1, col - 1, realBoard) == true) mines++;
    }

    if (IsValid (row + 1, col + 1) == true)
    {
        if (IsMine (row + 1, col + 1, realBoard) == true) mines++;
    }

    if (IsValid (row + 1, col - 1) == true)
    {
        if (IsMine (row + 1, col - 1, realBoard) == true) mines++;
    }

    return mines; 
}

void PlaceMines(int mineboard[][2], char realBoard[][maxside]) {
    bool mark[maxside * maxside];

    memset (mark, false, sizeof(mark));

    for (int i = 0; i < mines; ) {
        int random = rand() % (side * side);
        int x = random / side;
        int y = random % side;

        if (mark[random] == false) {
            mineboard[i][0] = x;
            mineboard[i][1] = y;

            realBoard[mineboard[i][0]][mineboard[i][1]] = '*';

            mark[random] = true;

            i++;
        }
    }

    return;
}

void Init(char realBoard[][maxside], char board[][maxside]) {
    srand(time (NULL));

    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            board[i][j] = realBoard[i][j] = '-';
        }
    }

    return;
}

void ReplaceMine (int row, int col, char board[][maxside]) {
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            if (board[i][j] != '*') {
                board[i][j] = '*';
                board[row][col] = '-';
                return;
            }
        }  
    }

    return;
}

bool PlayUtil(char gameboard[][maxside], char realboard[][maxside], int mineboard[][2], int row, int col, int *movesLeft) {
    if(gameboard[row][col] != '-') return false;
    
    int i;
    int j;

    if (realboard[row][col] == '*') {
        gameboard[row][col] = '*';

        for (i = 0; i < mines; i++) gameboard[mineboard[i][0]][mineboard[i][1]] = '*';
        DisplayBoard(gameboard);
        
        printf("\nYou Lose!\n");
        
        return true;
    }
    else {
        int count = CountMines(row, col, mineboard, realboard);
        
        (*movesLeft)--;
        
        gameboard[row][col] = count + '0';
        
        if (!count) {
            if (IsValid(row - 1, col) == true) {
                if (IsMine(row - 1, col, realboard) == false) {
                    PlayUtil(gameboard, realboard, mineboard, row - 1, col, movesLeft);
                }
            }

            if (IsValid(row - 1, col) == true) {
                if (IsMine(row + 1, col, realboard) == false) {
                    PlayUtil(gameboard, realboard, mineboard, row + 1, col, movesLeft);
                }
            }

            if (IsValid(row - 1, col) == true) {
                if (IsMine(row, col + 1, realboard) == false) {
                    PlayUtil(gameboard, realboard, mineboard, row, col + 1, movesLeft);
                }
            }

            if (IsValid(row - 1, col) == true) {
                if (IsMine(row, col - 1, realboard) == false) {
                    PlayUtil(gameboard, realboard, mineboard, row, col - 1, movesLeft);
                }
            }

            if (IsValid(row - 1, col) == true) {
                if (IsMine(row - 1, col + 1, realboard) == false) {
                    PlayUtil(gameboard, realboard, mineboard, row - 1, col + 1, movesLeft);
                }
            }

            if (IsValid(row - 1, col) == true) {
                if (IsMine(row - 1, col - 1, realboard) == false) {
                    PlayUtil(gameboard, realboard, mineboard, row - 1, col - 1, movesLeft);
                }
            }

            if (IsValid(row - 1, col) == true) {
                if (IsMine(row + 1, col + 1, realboard) == false) {
                    PlayUtil(gameboard, realboard, mineboard, row + 1, col + 1, movesLeft);
                }
            }

            if (IsValid(row - 1, col) == true) {
                if (IsMine(row + 1, col - 1, realboard) == false) {
                    PlayUtil(gameboard, realboard, mineboard, row + 1, col - 1, movesLeft);
                }
            } 
        }  

        return false;
    }
}

void Play() {
    bool over = false;
    char realBoard[maxside][maxside], gameBoard[maxside][maxside];
    int movesLeft = side * side - mines, x, y;
    int mineboard[maxmines][2];

    Init(realBoard, gameBoard);
    PlaceMines(mineboard, realBoard);

    int movenum = 0;

    while (!over) {
        printf("Current board: \n");

        DisplayBoard(gameBoard);

        DoTurn(&x, &y);
        if (movenum == 0) {
            if (IsMine (x, y, realBoard) == true) {
                ReplaceMine(x, y, realBoard);
            }
        }

        movenum++;

        over = PlayUtil(gameBoard, realBoard, mineboard, x, y, &movesLeft);
        
        if ((!over) && (movesLeft == 0)) {
            DisplayBoard(gameBoard);
            printf("\nYou won!\n");
            over = true;
        }
    }

    return;
}

void ChooseDiff (int diff) {

    if (diff == Beginner) {
        cout << ">>> BEGINNER BOARD SELECTED <<<" << endl;
        side = 10;
        mines = 10;
    }
 
    if (diff == Intermediate) {
        cout << ">>> INTERMEDIATE BOARD SELECTED <<<" << endl;
        side = 10;
        mines = 20;
    }
 
    if (diff == Advanced) {
        cout << ">>> ADVANCED BOARD SELECTED <<<" << endl;
        side = 10;
        mines = 25;
    }

    if (diff == Custom) {
        cout << ">>> CUSTOM BOARD SELECTED <<<" << endl;
        cout << "What do you want the side length to be? (0-10)" << endl;
        cin >> side;
        cout << "How many mines do you want there to be? (0-99)" << endl;
        cin >> mines;
    }
 
    return;
}

void Minesweeper::Run() {

    cout << "||||||||||||||||||||||||||||" << endl
    <<      "|| WELCOME TO MINESWEEPER ||" << endl
    <<      "||||||||||||||||||||||||||||" << endl 
    << endl;

    int difficulty = 0;

    cout << "Select your difficulty: " << endl
    << "0 = BEGINNER (10 Mines)" << endl
    << "1 = INTERMEDIATE (20 Mines)" << endl
    << "2 = ADVANCED (25 Mines)" << endl
    << "3 = CUSTOM (You choose parameters)" << endl;
    cin >> difficulty;

    switch(difficulty) {
        case (0):
            ChooseDiff(Beginner);
        break;
        case (1):
            ChooseDiff(Intermediate);
        break;
        case (2):
            ChooseDiff(Advanced);
        break;
        case (3):
            ChooseDiff(Custom);
        break;
    }
    
    Play();

    cout << "|||||||||||||||||||||||||||" << endl
    <<      "||  THANKS FOR PLAYING!  ||" << endl
    <<      "|||||||||||||||||||||||||||" << endl 
    << endl;

    // Exit code
    string a;
    getline(cin, a);
}