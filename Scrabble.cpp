#include <vector>
#include <string>
#include <iostream>
#include "scrabble.h"
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <climits>
#include <algorithm>

Scrabble::Scrabble() {
    //adds the dictionary txt to list
    std::ifstream f;
    f.open("words_alpha.txt");
    std::string line;

    if (f.is_open()) {
        while (std::getline(f, line)) {
            m_words.push_back(line);
        }
    }

    f.close();
}

char Scrabble::RandChar() {
    //randomly generates a letter (ascii values 97 to 122)
    return (char)(rand() % (122 - 97 + 1) + 97);
}

bool Scrabble::IsInt(std::string str) {
    //checks if a string is an integer
    for (int i = 0; i < str.length();i++) {
        int asciiValue = (int)str[i] - 48;
        if ((asciiValue >= 0) && (asciiValue <= 9)) {

        }
        else {return false;}
    }
    return true;
}

void Scrabble::Run() {
    //randomizes seed
    srand (time(NULL));

    //main game loop
    while (true) {
        //generates given letters
        std::string givenLetters = "";
        for (int i = 0; i < 7; i++) {
            givenLetters += RandChar();
        }

        //word quessing loop
        while (true) {
            std::cout << "Given letters: " << givenLetters << std::endl;
            std::cout << "               1234567\n";
            std::cout << "Word: ";

            std::string wordGuess;
            std::cin >> wordGuess;
            bool notWord = true;

            //checks if input was character to reroll or a word to guess
            if (IsInt(wordGuess)) {
                //reroll
                int iReroll = std::stoi(wordGuess) - 1;
                givenLetters[iReroll] = RandChar();
            }
            else {
                //searches for the list of words to check if the guess was a recognized word
                if (std::count(m_words.begin(), m_words.end(), wordGuess)) {
                    //checks if the guessed word is possible to make with the givin letters
                    std::string remainingLetters = givenLetters;
                    for (int i = 0; i < wordGuess.length(); i++) {
                        notWord = true;
                        for (int j = 0; j < remainingLetters.length(); j++) {
                            if (wordGuess[i] == remainingLetters[j]) {
                                remainingLetters.erase(j, 1);
                                notWord = false;
                                break;
                            }
                        }
                        if ((remainingLetters == "") || (false)) {
                            notWord = false;
                            break;
                        }
                        if (notWord) {
                            break;
                        }
                    }

                    if (notWord) {
                        std::cout << "Invalid\n";
                    }
                    else {
                        break;
                    }
                }
                else {
                    std::cout << "Invalid\n";
                }
            }
        }
        std::cout << "You found a word.\n\n";
    }
    std::cout << "Done.\n";
}