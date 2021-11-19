#include <iostream>
#include "SnakeGame.h"
#include <conio.h>

using namespace std;

// Hella Scuffed...

// Map Width
const int WIDTH = 40;
// Map Length
const int HEIGHT = 20;

// Coordinate declations for Player and Target.
// Score declaration
int x, y, fruitX, fruitY, score;

// Coordinates of the snake
int tailX[100], tailY[100];

// Number of cells that trail the snake's core
int nTail;

// Directon indicator enums
enum eDirecton
{
    STRT = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
}; // Control enum for direction

eDirecton dir;

bool GameOver;

void SnakeGame::Initialization()
{
    GameOver = false;
    dir = STRT;
    x = WIDTH / 2;
    y = HEIGHT / 2;

    // Randomly creates the Fruit's Target position
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
}
void SnakeGame::DrawGrid()
{
    // "Really" advanced level of witchcraft here (level 12 stuff)
    // Uses the Input Output import above to clear the grid before every draw using the System function
    system("cls");

    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";

    cout << endl;

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (j == 0)
                cout << "#"; // Wall indicating charecters

            if (i == y && j == x)
                cout << "*"; // Snake indicating charecter

            else if (i == fruitY && j == fruitX)
                cout << "&"; // Fruit indicator charecter

            else
            {
                bool print = false;

                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "*";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
            if (j == WIDTH - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}
void SnakeGame::DataInput()
{
    if (_kbhit())
    {
        switch (_getch())
        {

        case 's':
            dir = DOWN;
            break;

        case 'a':
            dir = LEFT;
            break;

        case 'd':
            dir = RIGHT;
            break;

        case 'w':
            dir = UP;
            break;

        case 'x':
            GameOver = true;
            break;
        }
    }
}

void SnakeGame::Things()
{

    int previousX = tailX[0];

    int previousY = tailY[0];

    int previous2X, previous2Y;

    tailX[0] = x;

    tailY[0] = y;

    for (int i = 1; i < nTail; i++)
    {
        // Updates the position of the snake with its tail
        previous2X = tailX[i];
        previous2Y = tailY[i];
        tailX[i] = previousX;
        tailY[i] = previousY;
        previousX = previous2X;
        previousY = previous2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;

    case RIGHT:
        x++;
        break;

    case UP:
        y--;
        break;

    case DOWN:
        y++;
        break;

    default:
        break;
    }

    if (x >= WIDTH)
    {
        x = 0;
    }

    else if (x < 0)
    {
        x = WIDTH - 1;
    }

    if (y >= HEIGHT)
    {
        y = 0;
    }
    else if (y < 0)
    {
        y = HEIGHT - 1;
    }
    for (int i = 0; i < nTail; i++)
    {

        if (tailX[i] == x && tailY[i] == y)
        {
            GameOver = true;
        }
    }

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        nTail++;
    }
}

void SnakeGame::Run()
{

    Initialization();
    while (!GameOver)
    {
        DrawGrid();
        DataInput();
        Things();
    }
}
