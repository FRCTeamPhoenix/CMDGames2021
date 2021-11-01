#include <vector>
#include <string>
#include <iostream>
#include "scrabble.h"
#include <fstream>
#include <stdlib.h>
#include <time.h>

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

    //Scrabble::words.push_back("");
}

void Scrabble::Run() {
    srand (time(NULL));
    std::cout << rand() % m_words.size();
}