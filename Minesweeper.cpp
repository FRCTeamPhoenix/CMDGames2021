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

// Checks if a space exists
bool Minesweeper::IsValid(int row, int column) {
    if ((row >= 0) && (row < side) && (column >= 0) && (column < side)) {
        // If the space exists, return true
        return true;
    } 
    else return false; // If the space doesn't exist, return false
}

// Checks if there is a mine at the specified location
bool Minesweeper::IsMine(int row, int column, char board[][maxside]) {
    if (board[row][column] == '*') return true; // If there is a mine at the location, return true
    else return false; // If there is no mine at the location, return false
}

// Gets the user's input for a turn
void Minesweeper::DoTurn(int *x, int *y) {
    printf("Enter your move (x, y): \n");
    scanf("%d %d", y, x);
}

// Displays the gameboard
void Minesweeper::DisplayBoard (char board[][maxside]) {
    int i;
    int j;

    printf("    ");
    
    for (i = 0; i < side; i++) printf("%d ", i); // Print the numbers for the positions along the top side
    
    printf("\n\n");
    
    // Print the numbers for the positions along the left side, as well as the board
    for (i = 0; i < side; i++) {
        printf ("%d   ", i); // Print the row number

        for (j = 0; j < side; j++) printf("%c ", board[i][j]); // Display a line of the board after printing the number

        printf("\n");
    }
    
    return;
}

// Counts the mines adjacent to a given space
int Minesweeper::CountMines(int row, int col, int mineboard[][2], char realBoard[][maxside]) {
    int i;
    int mines = 0;

    // Checks if a space is valid
    if (IsValid (row - 1, col) == true)
    {
        // If the space exists, check if the space has a mine
        if (IsMine (row - 1, col, realBoard) == true) mines++; // Increment "mines" if the space contains a mine
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

    return mines; // Return the number of mines
}

// Places mines randomly around the board
void Minesweeper::PlaceMines(int mineboard[][2], char realBoard[][maxside]) {
    bool mark[maxside * maxside];

    memset (mark, false, sizeof(mark));

    for (int i = 0; i < mines; ) {
        int random = rand() % (side * side);

        // Create a random x and y coordinate
        int x = random / side;
        int y = random % side;

        if (mark[random] == false) {
            // Store the random coordinate in a board
            mineboard[i][0] = x;
            mineboard[i][1] = y;

            realBoard[mineboard[i][0]][mineboard[i][1]] = '*'; // Place a mine on the real board (asterisks are mines)

            mark[random] = true;

            i++;
        }
    }

    return;
}

// Fills the board specified with dashes
void Minesweeper::Init(char realBoard[][maxside], char board[][maxside]) {
    srand(time (NULL));

    // Cycle through all of the spaces on the board
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            board[i][j] = realBoard[i][j] = '-'; // Fill space with a dash
        }
    }

    return;
}

// Removes a mine at the specified location and add a mine in the first vacant spot on the board
void Minesweeper::ReplaceMine (int row, int col, char board[][maxside]) {
    
    // Scan through the spaces on the board
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            if (board[i][j] != '*') {
                // If the space is not a mine, put a mine there
                board[i][j] = '*';
                board[row][col] = '-'; // Replace the initial point with an empty space
                return;
            }
        }  
    }

    return;
}

// Reveals large areas of empty spaces if the player doesn't select a mine, otherwise end the game with the player losing
bool Minesweeper::PlayUtil(char gameboard[][maxside], char realboard[][maxside], int mineboard[][2], int row, int col, int *movesLeft) {
    if(gameboard[row][col] != '-') return false; // If the space isn't hidden, return false
    
    int i;
    int j;

    // If the space is a mine, the game is over and the player loses
    if (realboard[row][col] == '*') {
        gameboard[row][col] = '*';

        for (i = 0; i < mines; i++) gameboard[mineboard[i][0]][mineboard[i][1]] = '*'; // Add all of the mines to the gameboard
        DisplayBoard(gameboard); // Display the new gameboard with the locations of the mines shown
        
        printf("\nYou Lose!\n");
        
        return true;
    }
    // If the space isn't hidden and it doesn't contain a mine, check for adjacent empty spaces and reveal them
    else {
        int count = CountMines(row, col, mineboard, realboard);
        
        (*movesLeft)--;
        
        gameboard[row][col] = count + '0'; // Set the position specified to the number of mines adjacent to it
        
        if (!count) {
            if (IsValid(row - 1, col) == true) {
                if (IsMine(row - 1, col, realboard) == false) {
                    PlayUtil(gameboard, realboard, mineboard, row - 1, col, movesLeft);
                }
            }

            if (IsValid(row + 1, col) == true) {
                if (IsMine(row + 1, col, realboard) == false) {
                    PlayUtil(gameboard, realboard, mineboard, row + 1, col, movesLeft);
                }
            }

            if (IsValid(row, col + 1) == true) {
                if (IsMine(row, col + 1, realboard) == false) {
                    PlayUtil(gameboard, realboard, mineboard, row, col + 1, movesLeft);
                }
            }

            if (IsValid(row, col - 1) == true) {
                if (IsMine(row, col - 1, realboard) == false) {
                    PlayUtil(gameboard, realboard, mineboard, row, col - 1, movesLeft);
                }
            }

            if (IsValid(row - 1, col + 1) == true) {
                if (IsMine(row - 1, col + 1, realboard) == false) {
                    PlayUtil(gameboard, realboard, mineboard, row - 1, col + 1, movesLeft);
                }
            }

            if (IsValid(row - 1, col - 1) == true) {
                if (IsMine(row - 1, col - 1, realboard) == false) {
                    PlayUtil(gameboard, realboard, mineboard, row - 1, col - 1, movesLeft);
                }
            }

            if (IsValid(row + 1, col + 1) == true) {
                if (IsMine(row + 1, col + 1, realboard) == false) {
                    PlayUtil(gameboard, realboard, mineboard, row + 1, col + 1, movesLeft);
                }
            }

            if (IsValid(row + 1, col - 1) == true) {
                if (IsMine(row + 1, col - 1, realboard) == false) {
                    PlayUtil(gameboard, realboard, mineboard, row + 1, col - 1, movesLeft);
                }
            } 
        }  

        return false;
    }
}

// Handles the overall flow of the game
void Minesweeper::Play() {
    bool over = false;
    char realBoard[maxside][maxside], gameBoard[maxside][maxside];
    int movesLeft = side * side - mines, x, y; // Determines the number of empty spaces left that don't contain a mine
    int mineboard[maxmines][2]; // A board that contain the locations of all the mines

    Init(realBoard, gameBoard); // Create the gameboard and fill it with dashes
    PlaceMines(mineboard, realBoard); // Randomly place mines around the board

    // Set the turn number to 0
    int movenum = 0;

    // Loops turns until the game is set to be over
    while (!over) {

        // Display the current state of the gameboard
        printf("Current board: \n");
        DisplayBoard(gameBoard);

        // Begin the turn
        DoTurn(&x, &y);

        // On the first turn, if the player selected a mine, replace it
        if (movenum == 0) {
            if (IsMine (x, y, realBoard) == true) {
                ReplaceMine(x, y, realBoard);
            }
        }

        // Increase the turn number
        movenum++;

        over = PlayUtil(gameBoard, realBoard, mineboard, x, y, &movesLeft); // Set the game to be over if the player selects a mine
        
        // If all empty spaces are uncovered and the game hasn't ended yet, the game ends and the player wins
        if ((!over) && (movesLeft == 0)) {
            DisplayBoard(gameBoard);
            printf("\nYou won!\n");
            over = true;
        }
    }

    return;
}

// Handles setting the variables for each difficulty
void Minesweeper::ChooseDiff (int diff) {

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

    // If the custom board was selected, ask the user for the parameters
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

    int difficulty = 0;

    // Startup message
    cout << "||||||||||||||||||||||||||||" << endl
    <<      "|| WELCOME TO MINESWEEPER ||" << endl
    <<      "||||||||||||||||||||||||||||" << endl 
    << endl;

    // Ask the user for the difficulty that they want
    cout << "Select your difficulty: " << endl
    << "0 = BEGINNER (10 Mines)" << endl
    << "1 = INTERMEDIATE (20 Mines)" << endl
    << "2 = ADVANCED (25 Mines)" << endl
    << "3 = CUSTOM (You choose parameters)" << endl;
    cin >> difficulty;

    // Set the variables for the game based on the difficulty selected
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
    
    // Start the game
    Play();

    // Exit message
    cout << "|||||||||||||||||||||||||||" << endl
    <<      "||  THANKS FOR PLAYING!  ||" << endl
    <<      "|||||||||||||||||||||||||||" << endl 
    << endl;

    // Exit code
    string a;
    getline(cin, a);
}