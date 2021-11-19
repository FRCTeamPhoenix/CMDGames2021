#include "TicTacToe.h"

#include <iostream>
#include <string>

using namespace std;

//Array for the board
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//Variable Declaration
int choice;
int row,column;
char turn = 'X';
bool tie = false;

//make board
void TicTacToe::Board(){
    cout<< "Player One- X Player Two- O" <<endl;
    cout<< "      |      |      " <<endl;
    cout<< board[0][0]  << "      |   " << board[0][1] << "   |  "<< board[0][2] <<endl;
    cout<< "------|------|-------" <<endl;
    cout<< "      |      |      " <<endl;
    cout<< board[1][0]  << "      |   " << board[1][1] << "   |  " << board[1][2] <<endl;
    cout<< "------|------|-------" <<endl;
    cout<< "      |      |      " <<endl;
    cout<< board[2][0]  << "      |   " << board[2][1] << "   |  " << board[2][2] <<endl;
    cout<< "      |      |      " <<endl;
   
};
//take turns
void TicTacToe::Play(){
    // say players turn
    if(turn == 'X'){
        cout<<"Player - 1 [X] turn : ";
    }
    else if(turn == 'O'){
        cout<<"Player - 2 [O] turn : ";
    }
    //take in players turn
    cin >> choice;

    //update board
    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }

    //pick characte rto update board
    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'X' symbol if
        //it is not already occupied
        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'O' symbol if
        //it is not already occupied
        board[row][column] = 'O';
        turn = 'X';
    }else {
        //if input position already filled
        cout<< "Box already filled!n Please choose another!!";
        Play();
    }

};
//check win
bool TicTacToe::Win(){
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    //Checking the if game already draw
    tie = true;
    return false;
};

//start game
void TicTacToe::Run(){

    cout<<"T I C  -- T A C -- T O E -- G A M E"<<endl;
    cout<<"FOR 2 PLAYERS"<<endl;

    while(Win()){
        Board();
        Play();
        Win();
    }
    if(turn == 'O' && tie == false){
        cout<<"Congratulations! Player with 'X' has won the game"<<endl;
    }
    else if(turn == 'X' && tie == false){
        cout<<"Congratulations! Player with 'O' has won the game"<<endl;
    }
    else
    cout<<"Game Tie!!!"<<endl;
}