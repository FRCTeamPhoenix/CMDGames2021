#include "LowerOrHigher.h"

#include <iostream>
#include <string>

using namespace std;

void LowerOrHigher::Run(){
    //generate random number for guessing
    int generatedNumber = rand () % 100 +1 ;
  
    //variable for guess values to be stored in
    int playerInput;

    //give the user intructions
    cout << "You may begin guessing the randomly generated number.";
    
    //get first guessed value
    cin >> playerInput;

    //while loop for forcing repetitive guessing of the number
    while (playerInput != generatedNumber) {

        cout << "Sorry! Incorrect input! Try again!";

        //check if input is lower
        if (playerInput < generatedNumber){

            cout << "Guess higher! Your answer was too low!";
        }
        //check if input is higher
        if (playerInput > generatedNumber) {

            cout << "Guess lower! Your answer was too high!";
        }
        //get user input again after informing if higher or lower
        cin >> playerInput;

    }
    
    //win statement
    cout << "Congratulations! You guessed the number! The number was " << generatedNumber << endl;

}