#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x,y, fruitX,fruitY,score;
enum eDirection{STOP = 0 , LEFT,RIGHT,UP,DOWN};
eDirection dir;

void Setup()
{
    gameOver= false;
    dir = STOP;
    x = width/2;
    y = height/2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw()
{
    system("cls");
    for (int i=0;i < width ; i++)
        cout << "#";
    cout << endl;
    

    for (int i=0;i <height;i++)
    {
        for (int j=0; j<width;j++)
        {
            if(j==0)
                cout << "#";
            if(i== y && j==x)
                cout << "0";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
                cout << " ";

                if(j== width-1)
                cout << "#" ;
        }

        cout<< endl;
    }
            for ( int i =0; i< width; i++)
        cout << "#";
        cout << endl;
}

void Input()
{
    if (_kbhit()) //return bool, if keyboard is pressed or not
    {
        switch(_getch()) // return the ASCI value of the key pressed
        {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;

        }
    }
}
void Logic()
{
    switch(dir) 
    {
        case LEFT:
            if (x==1)
                break;
            
            x--;
            break;
        case RIGHT:
            if(x==19)
                break;
            x++;
            break;
        case UP:
            if(y==1)
            break;
            y--;
            break;
        case DOWN:
            if(y==19)
            break;
            y++;
            break;
        default:
            break;
        if(x==fruitX && y== fruitY)
        {
            score +=10;
            fruitX = rand() % width;
            fruitY = rand() % height;
        }
cout << endl;
cout << "Score:"  << score << endl;

    }
}

int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();

    }
}
