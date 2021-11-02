#include <vector>
#include <string>
#include <iostream>
#include "scrabble.h"
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <climits>

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

    std::string given_letters = "";
    for (int i = 0; i < 7; i++) {
        given_letters += RandChar();
    }

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
        std::cout << "Word: ";

        std::string word_guess;
        std::cin >> word_guess;

        if (std::find(m_words.begin(), m_words.end(), word_guess)) {
            std::cout << "Is word!\n";
            break;
        }
    }

    std::cout << "Done.\n";
}