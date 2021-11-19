#include "GemGame.h"

#include <iostream>
#include <string>

using namespace std;

void GemGame::Run(){
    int playerGems = 5;
    int compGems = 5;
    while(true){
        bool inputValid = true;
        cout << "\nYou have " << playerGems << " gems, and your opponent has " << compGems << " gems." << endl;

        if(playerGems >= 10 && compGems < 10){
            cout << "You win!\n" << endl;
            break;
        }else if(playerGems < 10 && compGems >= 10){
            cout << "You lose...\n" << endl;
            break;
        }else if(playerGems >= 10 && compGems >= 10){
            cout << "You tie.\n" << endl;
            break;
        }

        cout << "1 - draw one gem\n2 - steal two gems from your opponent\n3 - counter your opponent's steal" << endl;
        int compChoice = rand() % 3;
        string a;
        getline(cin, a);
        if(a == "1"){
            playerGems++;
            cout << "You draw a gem. ";
        }else if(a == "2"){
            if(compChoice == 2){
                playerGems -= 2;
                compGems += 2;
                cout << "You tried to steal, but the opponent countered and stole two gems from you." << endl;
            }else if(compGems >= 2){
                playerGems += 2;
                compGems -= 2;
                cout << "You stole two gems from the opponent. ";
            }else{
                cout << "You tried to steal, but the opponent didn't have enough gems. ";
            }
        }else if(a == "3"){
            if(compChoice == 1){
                playerGems += 2;
                compGems -= 2;
                cout << "The opponent tried to steal, but you countered and stole two gems instead." << endl;
            }else{
                cout << "You tried to counter, but nothing happened. ";
            }
        }else{
            cout << "Please input something valid." << endl;
            inputValid = false;

        }
        if(inputValid){
            if(compChoice == 0){
                compGems++;
                cout << "The opponent drew a gem." << endl;
            }else if(compChoice == 1 && a != "3"){
                if(playerGems >= 2){
                    playerGems -= 2;
                    compGems += 2;
                    cout << "The opponent stole two gems from you." << endl;
                }else{
                    cout << "The opponent tried to steal, but you didn't have enough gems." << endl;
                }
            }else if(compChoice == 2 && a != "2"){
                cout << "The opponent tried to counter, but nothing happened." << endl;
            }
        }
    }
}