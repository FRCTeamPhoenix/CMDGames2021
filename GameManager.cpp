#include "GameManager.h"
#include "Hangman.h"
#include "ExampleGame.h"
#include "higherorlower.h"
#include "Scrabble.h"
#include "Minesweeper.h"
#include "RockPaperScissor.h"
#include "GemGame.h"
#include "Life.h"

#include "TicTacToe.h"

#include <iostream>
#include <string>

GameManager::GameManager(){

}

void GameManager::Run(){
    AddGames();

    //using the game map, try to get input from the user repeatedly
    string input = "";
    while(input != "exit"){
        cout << "Please type a game to play or type \'exit\'\nGames:" << endl;
        //print out the games
        for(auto it = m_games.begin(); it != m_games.end(); it++){
            cout << it->first << endl;
        }

        getline(cin, input);
        //find the game and check if its in it
        auto it = m_games.find(input);
        if(it != m_games.end()){
            cout << "Running \'" + input + "\'..." << endl;
            it->second->Run();
        }
    }

    //delete all the pointers
    for(auto it = m_games.begin(); it != m_games.end(); it++){
        delete it->second;
    }
}

void GameManager::AddGames(){
    //insert your game below like the example line
    ExampleGame* eg = new ExampleGame();
    m_games.insert(make_pair("example", eg));
    TicTacToe* tt = new TicTacToe();
    m_games.insert(make_pair("tic tac toe", tt));
    Hangman* hm = new Hangman();
    m_games.insert(make_pair("hangman", hm));
    HigherOrLower* hl = new HigherOrLower();
    m_games.insert(make_pair("Higher or Lower", hl));
    Scrabble* scrabble = new Scrabble();
    m_games.insert(make_pair("scrabble", scrabble));
    Minesweeper* ms = new Minesweeper();
    m_games.insert(make_pair("minesweeper", ms));
    RockPaperScissor* rps = new RockPaperScissor();
    m_games.insert(make_pair("rock paper scissor", rps));
    GemGame* gg = new GemGame();
    m_games.insert(make_pair("gem", gg));
    Life* l = new Life();
    m_games.insert(make_pair("life", l));
}