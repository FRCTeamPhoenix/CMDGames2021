#include "RockPaperScissor.h"

#include <iostream>
#include <string>

using namespace std;

void RockPaperScissor::Run(){
    int userOption;
    cout << "Choose an option: \n[1]Rock\n[2]Paper\n[3]Scissor" << endl;
    cin >> userOption;
    int botOption = rand() % 3 + 1;
    if (userOption == 1)
    {
        if (botOption == 2)
        {
            cout << "You lose!!!!!!!!!!!" << endl;
        }
        else if (botOption == 3)
        {
            cout << "you won." << endl;
        }
        else{
            cout << "You tied";
        }
    }
    else if (userOption == 2)
    {
        if (botOption == 3)
        {
            cout << "You lose!!!!!!!!!!!" << endl;
        }
        else if (botOption == 1)
        {
            cout << "you won." << endl;
        }
        else{
            cout << "You tied";
        }
    }
    else{
        if (botOption == 1)
        {
            cout << "You lose!!!!!!!!!!!" << endl;
        }
        else if (botOption == 2)
        {
            cout << "you won." << endl;
        }
        else{
            cout << "You tied";
        }
    }
}