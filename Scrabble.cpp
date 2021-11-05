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

void Scrabble::Run() {
    srand (time(NULL));
    //std::cout << m_words[rand() % m_words.size()] << std::endl;

    //for (int i = 0; i < 100; i++) {
    //    std::cout << RandChar() << std::endl;
    //}

    while (true) {
        std::string given_letters = "";
        for (int i = 0; i < 7; i++) {
            given_letters += RandChar();
        }
        //given_letters = "qvmyair";

        /*int chosen = 0;
        while (true) {
            try {
                std::cout << "Given letters: " << given_letters;
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
            std::cout << "Given letters: " << given_letters << std::endl;
            std::cout << "               1234567\n";
            std::cout << "Word: ";

            std::string word_guess;
            std::cin >> word_guess;
            bool not_word = true;

            try {
                int i_reroll = std::stoi(word_guess);
                given_letters[i_reroll] = RandChar();
                //std::cout << "int\n";
            }
            catch(int e) {
                //std::cout << "not int\n";
            }

            if (std::count(m_words.begin(), m_words.end(), word_guess)) {
                //std::cout << "Is word!\n";
                //break;
                std::string remaining_letters = given_letters;
                for (int i = 0; i < word_guess.length(); i++) {
                    not_word = true;
                    for (int j = 0; j < remaining_letters.length(); j++) {
                        if (word_guess[i] == remaining_letters[j]) {
                            //std::cout << remaining_letters << std::endl;
                            remaining_letters.erase(j, 1);
                            //std::cout << remaining_letters << std::endl << std::endl;
                            not_word = false;
                            break;
                        }
                    }
                    if ((remaining_letters == "") || (false)) {
                        not_word = false;
                        break;
                    }
                    if (not_word) {
                        break;
                    }
                }

                if (not_word) {
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
    std::cout << "Done.\n";
}