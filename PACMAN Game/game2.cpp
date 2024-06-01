                       //PACMAN Game
#include <iostream>
#include <fstream>
#include <time.h>
#include <cmath>
#include <windows.h>
using namespace std;

// Global Variable

int PX = 9;  // X Coordinate of Pacman
int PY = 31; // Y Coordinate of Pacman
int score = 0;
int chances = 3;
int GX = 19;  // X Coordinate of Ghost1
int GY = 25;  // Y Coordinate of Ghost1
char previousItem = ' ';

int G2X = 14;  // X Coordinate of Ghost2
int G2Y = 22;   // Y Coordinate of Ghost2
char previousItem2 = ' ';

int G3X = 16;   // X Coordinate of Ghost3
int G3Y = 56;  // Y Coordinate of Ghost3
char previousItem3 = ' ';

// ---------------follower Ghost--------------
int G4X = 11;   // X Coordinate of Ghost4
int G4Y = 62;   // Y Coordinate of Ghost4
char previousItem4 = ' ';

fstream file;

//Prototypes
void read_maze();
void display_maze();
void Score();
void printScore();
void movePLeft();
void movePRight();
void movePUp();
void movePDown();
bool ghostMovement();
bool ghostMovement2();
bool ghostMovement3();
int ghostDirection();
void gotoxy(int x, int y);
void FollowingGhost();
void game_over();
void printLives();


char maze[24][71]; 
main()
{
    system("cls");
    read_maze();
    display_maze();
    gotoxy(PY, PX);
    cout<<"P";
    
    while(chances != 0)
    {
         bool gameRunning = true;
        
        Sleep(200);
        ghostMovement();
        ghostMovement2();
        ghostMovement3();
        FollowingGhost();
        printScore();
        printLives();
        if (GetAsyncKeyState(VK_LEFT))
        {
            
            movePLeft(); // Function call to move Pacman towards left
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movePRight(); // Function call to move Pacman towards right
        }
        if (GetAsyncKeyState(VK_UP))
        {
            movePUp();// Function call to move Pacman towards up
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movePDown(); // Function call to move Pacman towards down
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            gameRunning = false; // Stop the game
        }
        game_over();
        printLives();
    }
}
//Functions
void Score()
{
    score = score + 1;
}
void printScore()
{
    gotoxy(85, 15);
    cout << "Score: " << score;
}
void printLives()
{
    gotoxy(85, 20);
    cout << "Lives: " << chances;

}
void movePLeft()
{
    if (maze[PX][PY - 1] == ' ' || maze[PX][PY - 1] == '.')
    {
        gotoxy(PY, PX);
        cout<<" ";
        PY = PY - 1;
        gotoxy(PY, PX);
        cout<<"P";
        if (maze[PX][PY] == '.')
        {
            Score();
        }
        
    }
  
}
void movePRight()
{
    if (maze[PX][PY + 1] == ' ' || maze[PX][PY + 1] == '.')
    {
        gotoxy(PY, PX);
        cout<<" ";
        PY = PY + 1;
        gotoxy(PY, PX);
        cout<<"P";
        if (maze[PX][PY] == '.')
        {
            Score();
        }
        
    }
}
void movePUp()
{

    if (maze[PX - 1][PY] == ' ' || maze[PX - 1][PY] == '.')
    {
        gotoxy(PY, PX);
        cout<<" ";
        PX = PX - 1;
        gotoxy(PY, PX);
        cout<<"P";
        if (maze[PX][PY] == '.')
        {
            Score();
        }
        
    }
 
}
void movePDown()
{
    if (maze[PX + 1][PY] == ' ' || maze[PX + 1][PY] == '.')
    {
        gotoxy(PY, PX);
        cout<<" ";
        PX = PX + 1;
        gotoxy(PY, PX);
        cout<<"P";
        if (maze[PX][PY] == '.')
        {
            Score();
        }
    }
  }
void read_maze()
{
    file.open("Maze.txt", ios :: in);
    for(int i = 0; i < 24; i++)
    {
        string temp;
        getline(file , temp);
        for(int j = 0; j < 71; j++)
        {
            maze[i][j] = temp[j];
        }
    }
}

void display_maze()
{
    for(int i = 0; i < 24; i++)
    {
        for(int j = 0; j < 71; j++)
        {
            cout<< maze[i][j];
        }
        cout<<endl;
    }
}
int ghostDirection()
{
    srand(time(0));
    int result = 1 + (rand() % 4);
    return result;
}
bool ghostMovement()
{
    int value = ghostDirection();
    if (value == 1)
    {
        if (maze[GX][GY - 1] == ' ' || maze[GX][GY - 1] == '.' || maze[GX][GY - 1] == 'P')
        {
            gotoxy(GY, GX);
            cout<<previousItem;
            GY = GY - 1;
             previousItem = maze[GX][GY];
             gotoxy(GY, GX);
            cout<<"G";
            if (previousItem == 'P')
            {
                return 0;
            }
            
        }
    }
    else if (value == 2)
    {
        if (maze[GX][GY + 1] == ' ' || maze[GX][GY + 1] == '.' || maze[GX][GY + 1] == 'P')
        {
            
            gotoxy(GY, GX);
            cout<<previousItem;
            GY = GY + 1;
            previousItem = maze[GX][GY];
             gotoxy(GY, GX);
             cout<<"G";
            if (previousItem == 'P')
            {
                return 0;
            }
            
        }
    }
    else if (value == 3)
    {
        if (maze[GX - 1][GY] == ' ' || maze[GX - 1][GY] == '.' || maze[GX - 1][GY] == 'P')
        {
            gotoxy(GY, GX);
            cout<<previousItem;
            GX = GX - 1;
            previousItem = maze[GX][GY];
            gotoxy(GY, GX);
             cout<<"G";
            if (previousItem == 'P')
            {
                return 0;
            }
        }
    }
    else if (value == 4)
    {
        if (maze[GX + 1][GY] == ' ' || maze[GX + 1][GY] == '.' || maze[GX + 1][GY] == 'P')
        {
            gotoxy(GY, GX);
            cout<<previousItem;
            GX = GX + 1;
            previousItem = maze[GX][GY];
            gotoxy(GY, GX);
             cout<<"G";

            if (previousItem == 'P')
            {
                return 0;
            }
        }
    }
    return 1;
}
bool ghostMovement2()
{
    int value = ghostDirection();
    if (value == 1)
    {
        if (maze[G2X][G2Y - 1] == ' ' || maze[G2X][G2Y - 1] == '.' || maze[G2X][G2Y - 1] == 'P')
        {
            gotoxy(G2Y, G2X);
            cout<<previousItem;
            G2Y = G2Y - 1;
             previousItem = maze[G2X][G2Y];
             gotoxy(G2Y, G2X);
            cout<<"G";
            if (previousItem == 'P')
            {
                return 0;
            }
            
        }
    }
    else if (value == 2)
    {
        if (maze[G2X][G2Y + 1] == ' ' || maze[G2X][G2Y + 1] == '.' || maze[G2X][G2Y + 1] == 'P')
        {
            
            gotoxy(G2Y, G2X);
            cout<<previousItem;
            G2Y = G2Y + 1;
            previousItem = maze[G2X][G2Y];
             gotoxy(G2Y, G2X);
             cout<<"G";
            if (previousItem == 'P')
            {
                return 0;
            }
            
        }
    }
    else if (value == 3)
    {
        if (maze[G2X - 1][G2Y] == ' ' || maze[G2X - 1][G2Y] == '.' || maze[G2X - 1][G2Y] == 'P')
        {
            gotoxy(G2Y, G2X);
            cout<<previousItem;
            G2X = G2X - 1;
            previousItem = maze[G2X][G2Y];
            gotoxy(G2Y, G2X);
             cout<<"G";
            if (previousItem == 'P')
            {
                return 0;
            }  
        }
    }
    else if (value == 4)
    {
        if (maze[G2X + 1][G2Y] == ' ' || maze[G2X + 1][G2Y] == '.' || maze[G2X + 1][G2Y] == 'P')
        {
            gotoxy(G2Y, G2X);
            cout<<previousItem;
            G2X = G2X + 1;
            previousItem = maze[G2X][G2Y];
            gotoxy(G2Y, G2X);
             cout<<"G";

            if (previousItem == 'P')
            {
                return 0;
            }
        }
    }
    return 1;
}
bool ghostMovement3()
{
    int value = ghostDirection();
    if (value == 1)
    {
        if (maze[G3X][G3Y - 1] == ' ' || maze[G3X][G3Y - 1] == '.' || maze[G3X][G3Y - 1] == 'P')
        {
            gotoxy(G3Y, G3X);
            cout<<previousItem;
            G3Y = G3Y - 1;
             previousItem = maze[G3X][G3Y];
             gotoxy(G3Y, G3X);
            cout<<"G";
            if (previousItem == 'P')
            {
                return 0;
            }
            
        }
    }
    else if (value == 2)
    {
        if (maze[G3X][G3Y + 1] == ' ' || maze[G3X][G3Y + 1] == '.' || maze[G3X][G3Y + 1] == 'P')
        {
            
            gotoxy(G3Y, G3X);
            cout<<previousItem;
            G3Y = G3Y + 1;
            previousItem = maze[G3X][G3Y];
             gotoxy(G3Y, G3X);
             cout<<"G";
            if (previousItem == 'P')
            {
                return 0;
            }
            
        }
    }
    else if (value == 3)
    {
        if (maze[G3X - 1][G3Y] == ' ' || maze[G3X - 1][G3Y] == '.' || maze[G3X - 1][G3Y] == 'P')
        {
            gotoxy(G3Y, G3X);
            cout<<previousItem;
            G3X = G3X - 1;
            previousItem = maze[G3X][G3Y];
            gotoxy(G3Y, G3X);
             cout<<"G";
            if (previousItem == 'P')
            {
                return 0;
            }
        }
    }
    else if (value == 4)
    {
        if (maze[G3X + 1][G3Y] == ' ' || maze[G3X + 1][G3Y] == '.' || maze[G3X + 1][G3Y] == 'P')
        {
            gotoxy(G3Y, G3X);
            cout<<previousItem;
            G3X = G3X + 1;
            previousItem = maze[G3X][G3Y];
            gotoxy(G3Y, G3X);
             cout<<"G";

            if (previousItem == 'P')
            {
                return 0;
            }    
        }
    }
    return 1;
}
void gotoxy(int x, int y) 
{ 
 COORD coordinates; 
 coordinates.X = x; 
 coordinates.Y = y; 
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void FollowingGhost()
{
   int FollowDirection[4] = {10000, 10000, 10000, 10000};
   // index 0 for right
   // index 1 for left
   //index 2 for up
   //index 3 for down
   if(!(maze[G4X][G4Y + 1] == '|' || maze[G4X][G4Y + 1] == '#' || maze[G4X][G4Y + 1] == '%'))
   {
    FollowDirection[0] = (pow(((G4Y + 1) - PY) , 2) + pow((G4X - PX) , 2));
   }
   if(!(maze[G4X][G4Y - 1] == '|' || maze[G4X][G4Y - 1] == '#' || maze[G4X][G4Y - 1] == '%'))
   {
    FollowDirection[1] = (pow(((G4Y - 1) - PY) , 2) + pow((G4X - PX) , 2));
   }
   if(!(maze[G4X - 1][G4Y] == '|' || maze[G4X - 1][G4Y] == '#' || maze[G4X - 1][G4Y] == '%'))
   {
    FollowDirection[2] = (pow(((G4Y) - PY) , 2) + pow(((G4X - 1) - PX) , 2));
   }
   if(!(maze[G4X + 1][G4Y] == '|' || maze[G4X + 1][G4Y] == '#' || maze[G4X + 1][G4Y] == '%'))
   {
    FollowDirection[3] = (pow(((G4Y) - PY) , 2) + pow(((G4X + 1) - PX) , 2));
   }         
//SHORTEST DISTANCE
int small_index = 0;
int exm = FollowDirection[0];
for(int i = 1; i < 4; i++)
{
    if(!(exm < FollowDirection[i]))
    {
        exm = FollowDirection[i];
        small_index = i;
    }
}
if(small_index == 0 && (G4Y - PY) != 0)
{
    gotoxy(G4Y, G4X);
    cout<<previousItem4;
    G4Y = G4Y + 1;
    previousItem4 = maze[G4X][G4Y];
    gotoxy(G4Y, G4X);
    cout<<"G";
}
else if(small_index == 1 && (G4Y - PY) != 0)
{
    gotoxy(G4Y, G4X);
    cout<<previousItem4;
    G4Y = G4Y - 1;
    previousItem4 = maze[G4X][G4Y];
    gotoxy(G4Y, G4X);
    cout<<"G";
}
else if(small_index == 2 && (G4X - PX) != 0)
{
    gotoxy(G4Y, G4X);
    cout<<previousItem4;
    G4X = G4X - 1;
    previousItem4 = maze[G4X][G4Y];
    gotoxy(G4Y, G4X);
    cout<<"G";    
}
else if(small_index == 3 && (G4X - PX) != 0)
{
    gotoxy(G4Y, G4X);
    cout<<previousItem4;
    G4X = G4X + 1;
    previousItem4 = maze[G4X][G4Y];
    gotoxy(G4Y, G4X);
    cout<<"G"; 

 }
}
void game_over()
{
    int a = 0;
    if((PY == GY && PX == GX) || (GY == PY && GX == PX))
    {
        a = 1;
        chances = chances - 1;
    }
    else if((PY == G2Y && PX == G2X) || (G2Y == PY && G2X == PX))
    {
        a = 1;
        chances = chances - 1;
    }
    else if(PY == G3Y && PX == G3X || (G3Y == PY && G3X == PX))
    {
        a = 1;
        chances = chances - 1;
    }
    else if(PY == G4Y && PX == G4X || (G4Y == PY && G4X == PX))
    {
        a = 1;
        chances = chances - 1;
    }
    if(a)
    {
        gotoxy(PY, PX);
        cout<<" ";
        PX = 9; 
        PY = 31;
        gotoxy(PY, PX);
        cout<<"P";
    }
}

