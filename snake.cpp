#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x,y, fruitX,fruitY,score;
enum eDirection{STOP = 0 , LEFT,RIGHT,UP,DOWN};
eDirection dir;
int tailX[100];
int tailY[100];
int nTail;
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
    for (int i=0;i < width+2 ; i++)
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
            {
                bool print = false; 
                for(int k= 0 ; k <nTail; k++)
                {
                    if(tailX[k] == j && tailY[k]== x )
                    {
                        cout << "o"; 
                        print = true;
                    }  
                }
                if(!print)
                    cout << " ";

            }   
                if(j== width-1)
                    cout << "#" ;
        }

        cout<< endl;
    }
        for ( int i =0; i< width+2; i++)
            cout << "#";
        cout << endl;
        cout << "Score:"  << score << endl;
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
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X,prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for(int i = 1 ; i < nTail ; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;  
    }

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
            if(y==0)
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
    for (int i = 0; i< nTail;i++)
    {
        if(tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }


    }
            if(x==fruitX && y== fruitY)
        {
            score +=10;
            fruitX = rand() % width;
            fruitY = rand() % height;
            nTail++;
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
        Sleep(10);
    }
}


