#include "GemGame.h"

#include <iostream>
#include <string>

using namespace std;

void GemGame::Run(){
    int player_gems = 5;
    int comp_gems = 5;
    while(true){
        bool input_valid = true;
        cout << "\nYou have " << player_gems << " gems, and your opponent has " << comp_gems << " gems." << endl;

        if(player_gems >= 10 && comp_gems < 10){
            cout << "You win!\n" << endl;
            break;
        }else if(player_gems < 10 && comp_gems >= 10){
            cout << "You lose...\n" << endl;
            break;
        }else if(player_gems >= 10 && comp_gems >= 10){
            cout << "You tie.\n" << endl;
            break;
        }

        cout << "1 - draw one gem\n2 - steal two gems from your opponent\n3 - counter your opponent's steal" << endl;
        int comp_choice = rand() % 3;
        string a;
        getline(cin, a);
        if(a == "1"){
            player_gems++;
            cout << "You draw a gem. ";
        }else if(a == "2"){
            if(comp_choice == 2){
                player_gems -= 2;
                comp_gems += 2;
                cout << "You tried to steal, but the opponent countered and stole two gems from you." << endl;
            }else if(comp_gems >= 2){
                player_gems += 2;
                comp_gems -= 2;
                cout << "You stole two gems from the opponent. ";
            }else{
                cout << "You tried to steal, but the opponent didn't have enough gems. ";
            }
        }else if(a == "3"){
            if(comp_choice == 1){
                player_gems += 2;
                comp_gems -= 2;
                cout << "The opponent tried to steal, but you countered and stole two gems instead." << endl;
            }else{
                cout << "You tried to counter, but nothing happened. ";
            }
        }else{
            cout << "Please input something valid." << endl;
            input_valid = false;

        }
        if(input_valid){
            if(comp_choice == 0){
                comp_gems++;
                cout << "The opponent drew a gem." << endl;
            }else if(comp_choice == 1 && a != "3"){
                if(player_gems >= 2){
                    player_gems -= 2;
                    comp_gems += 2;
                    cout << "The opponent stole two gems from you." << endl;
                }else{
                    cout << "The opponent tried to steal, but you didn't have enough gems." << endl;
                }
            }else if(comp_choice == 2 && a != "2"){
                cout << "The opponent tried to counter, but nothing happened." << endl;
            }
        }
    }
}