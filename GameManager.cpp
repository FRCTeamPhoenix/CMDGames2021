#include "GameManager.h"

#include "ExampleGame.h"
#include "Scrabble.h"
#include "RockPaperScissor.h"
#include "GemGame.h"

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
    Scrabble* scrabble = new Scrabble();
    m_games.insert(make_pair("scrabble", scrabble));
    RockPaperScissor* rps = new RockPaperScissor();
    m_games.insert(make_pair("rock paper scissor", rps));
    GemGame* gg = new GemGame();
    m_games.insert(make_pair("gem", gg));
}