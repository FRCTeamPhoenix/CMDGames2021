#include "Life.h"

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

const int width = 80;
const int height = 40;
char board[height][width] = {0};
char nextBoard[height][width];

const char alive = '#';
const char dead = ' ';

int CountAdjacent(int x, int y){
    int adjacentAlive = 0;
    if(x > 0 && board[y][x-1] == alive){
        adjacentAlive++;
        //cout << '1' << endl;
    }
    if(y > 0 && board[y-1][x] == alive){
        adjacentAlive++;
        //cout << '2' << endl;
    }
    if(x < width - 1 && board[y][x+1] == alive){
        adjacentAlive++;
        //cout << '3' << endl;
    }
    if(y < height - 1 && board[y+1][x] == alive){
        adjacentAlive++;
        //cout << '4' << endl;
    }
    if(x > 0 && y > 0 && board[y-1][x-1] == alive){
        adjacentAlive++;
        //cout << '5' << endl;
    }
    if(x > 0 && y < height - 1 && board[y+1][x-1] == alive){
        adjacentAlive++;
        //cout << '6' << endl;
    }
    if(x < width - 1 && y > 0 && board[y-1][x+1] == alive){
        adjacentAlive++;
        //cout << '7' << endl;
    }
    if(x < width - 1 && y < height - 1 && board[y+1][x+1] == alive){
        adjacentAlive++;
        //cout << '8' << endl;
    }
    if(adjacentAlive == 3){
        //cout << "3 at " << x << ", " << y << endl;
    }
    if(adjacentAlive != 0){
        //cout << "--------------------------" << endl;
    }
    return adjacentAlive;
}

void Simulate(){
    nextBoard[height][width] = {dead};
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int numAdj = CountAdjacent(j, i);
            if(board[i][j] == alive && (numAdj < 2 || numAdj > 3)){
                nextBoard[i][j] = dead;
                //cout << "Alive, adj: " << numAdj << ", died." << endl;
            }else if(board[i][j] == alive){
                nextBoard[i][j] = alive;
                //cout << "Alive, adj: " << numAdj << ", persisted." << endl;
            }else if(numAdj == 3){
                nextBoard[i][j] = alive;
                //cout << "Dead, adj: " << numAdj << ", born." << endl;
            }
        }
    }
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            board[i][j] = nextBoard[i][j];
        }
    }
}

void PrintArray(char a[][width]){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
}

void Life::Run(){
    srand(time(0));
    string choice;
    while(true){
        cout << "Choose a default board type or type 0 to pick your own starting cells. Type x while running to end program.\n1 - 1x3 line, centered\n2 - random" << endl;
        getline(cin, choice);
        if(choice == "1"){
            board[height/2][width/2] = alive;
            board[height/2][width/2 - 1] = alive;
            board[height/2][width/2 + 1] = alive;
            break;
        }
        if(choice == "2"){
            for(int i = 0; i < height; i++){
                for(int j = 0; j < width; j++){
                    int number = rand() % 3;
                    if(number == 0){
                        board[i][j] = alive;
                    }
                }
            }
            break;
        }
    }
    while(true){
        cout << "_________________" << endl;
        PrintArray(board);
        Simulate();
        string x;
        getline(cin, x);
        if(x == "x"){
            break;
        }
    }
    PrintArray(board);
}