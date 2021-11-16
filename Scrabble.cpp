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
    //97 to 122
    return (char)(rand() % (122 - 97 + 1) + 97);
}

bool Scrabble::IsInt(std::string str) {
    for (int i = 0; i < str.length();i++) {
        int asciiValue = (int)str[i] - 48;
        if ((asciiValue >= 0) && (asciiValue <= 9)) {

        }
        else {return false;}
    }
    return true;
}

void Scrabble::Run() {
    srand (time(NULL));
    //std::cout << m_words[rand() % m_words.size()] << std::endl;

    //for (int i = 0; i < 100; i++) {
    //    std::cout << RandChar() << std::endl;
    //}

    while (true) {
        std::string givenLetters = "";
        for (int i = 0; i < 7; i++) {
            givenLetters += RandChar();
        }
        //givenLetters = "qvmyair";

        /*int chosen = 0;
        while (true) {
            try {
                std::cout << "Given letters: " << givenLetters;
                std::cin >> chosen;
                break;
            }
            catch(int e) {
                
            }
            std::cin.clear();
            std::cin.ignore(INT_MAX);
            std::string h;
            std::cin >> h;
            
        }*/

        while (true) {
            std::cout << "Given letters: " << givenLetters << std::endl;
            std::cout << "               1234567\n";
            std::cout << "Word: ";

            std::string wordGuess;
            std::cin >> wordGuess;
            bool notWord = true;

            /*try {
                int iReroll = std::stoi(wordGuess);
                givenLetters[iReroll] = RandChar();
                //std::cout << "int\n";
            }
            catch(int e) {
                //std::cout << "not int\n";
            }*/

            if (IsInt(wordGuess)) {
                int iReroll = std::stoi(wordGuess) - 1;
                //std::cout << iReroll << "\n";
                givenLetters[iReroll] = RandChar();
                //std::cout << "ball\n";
            }
            else {
                if (std::count(m_words.begin(), m_words.end(), wordGuess)) {
                    //std::cout << "Is word!\n";
                    //break;
                    std::string remainingLetters = givenLetters;
                    for (int i = 0; i < wordGuess.length(); i++) {
                        notWord = true;
                        for (int j = 0; j < remainingLetters.length(); j++) {
                            if (wordGuess[i] == remainingLetters[j]) {
                                //std::cout << remainingLetters << std::endl;
                                remainingLetters.erase(j, 1);
                                //std::cout << remainingLetters << std::endl << std::endl;
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