#include "Hangman.h"

#include <iostream>
#include <string>

using namespace std;

void Hangman::Run() {

    //declaring variables
    int inputLength = 0;
    int winTracker = 0; 
    int loseTracker = 0;

    //giving user stuff to do, get array length
    cout << "This game requires at least 2 players" << "\n";
    cout << "It is recommended you have a piece of paper at hand" << "\n";
    cout << "Please enter the number of letters within the word" << "\n";

    cin >> inputLength;
    char input [inputLength];
    char letterTracker [26];

    cout << "There are " << inputLength << " letters in the given word" << "\n";

    //getting actual characters for word
    for (int i = 0; i < inputLength; i++){
        cout << "Please enter the " << (i+1) << " letter of the word" << "\n";
        cin >> input[i];
    }

    //iterate through the array to convert it to a string for final print statement
    string wordString = "";
    for (int i = 0; i < inputLength; i++) {
        wordString = wordString + input[i];
    }

    //guessing
    cout << "The other players may now begin guessing" << "\n";

    char letterGuess;
    bool tracker = false;
    bool trueTracker = true;
    for (int a = 0; a <= 6;){
        cout << "Please enter the letter you would like to guess" << "\n";
        cin >> letterGuess;

        //iterate through the array, checking letter by letter
        for (int b = 0; b < inputLength; b++){

            if (letterGuess == input [b]) {
                cout << "Congratulations! The " << (b+1) << " letter of the word is " << letterGuess << "\n";
                tracker = trueTracker;
                winTracker++;
            } //if letter is not present in word
        }

        //adding limbs 
        if (tracker == false) {
            cout << "Sorry! The guessed letter was not found within the word! The guessed letter was " << letterGuess << "\n";
            a++;
            cout << "You have " << (6 - a) << " guesses remaining" << "\n";
            loseTracker++;
        }

        //if player guesses full word, end program
        if (winTracker == inputLength){
            cout << "Congratulations! You guessed the whole word! The word was " << wordString << "\n";
            return;
        }
        //if the player gets things wrong 6 times, end the program
        if (loseTracker == 6) {
            return;
        }

        //reset tracker for next loop
        tracker = false;
    

    } //for loop 1
}// main function