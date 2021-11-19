#include "HigherOrLower.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void HigherOrLower::Run(){
    //Creates int guess, which is later used to store user input
    int guess;
    //Creates int num, which is set to the random number the user needs to guess
    int num = rand() % 1000 +1;
    //Creates string userInput, which is later used for user input
    string userInput;
    //Defines int yes, which is set to 0 until the user guesses the number stored in num
    int yes = 0;
    //Creates x, which is later used to keep track of the number of guesses the user has.
    int x = 7;

    //Asks for a guess, takes in the guess and stores it in guess. 
    do{
        cout << "Guess a number 1-1000: ";
        getline(cin, userInput);
        stringstream(userInput) >> guess;
        //If the guess is over 1000 or negative, it asks for another guess until it gets a valid answer.
        while (guess > 1000 || guess < 1) {
            cout << "Please guess a number 1-1000: ";
            getline(cin, userInput);
            stringstream(userInput) >> guess;
        }
        //Prints if the user should guess higher or lower or if they've guessed it. Changes yes to 1 if the user had guessed it.
        if (num > guess && x > 1) {
            cout << "Guess higher \n";
        } else if (num < guess && x > 1) {
            cout << "Guess lower \n" ;
        } else if (num == guess){
            cout << "You've guessed it! :D \n";
            yes = 1;
        }
        x--;
    }
    //Keeps asking for new guesses and giving feedback while they have not guessed it and they have not guessed seven times.
    while(yes != 1 && x > 0);
    //Tells the user what the number was if they exceeded seven tries.
    if(x == 0) {
        cout << "The number was " << num << "\n";
    }
} 
