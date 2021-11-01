#include "ExampleGame.h"

#include <iostream>
#include <string>

using namespace std;

void ExampleGame::Run(){
    cout << "How was your day?" << endl;
    string a;
    getline(cin, a);
    cout << "Trolled" << endl;
}