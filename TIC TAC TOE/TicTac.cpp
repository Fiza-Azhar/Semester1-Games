#include<iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int choice;
char turn = 'X';
bool draw = false;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
void display_game()
{
  system("cls");
  cout << "\t\t***************" << endl;
  cout << "\t\t* TIC TAC TOE *" << endl;
  cout << "\t\t***************" << endl;
  cout << " Player1[X]" << endl;
  cout << " Player2[O]" << endl;
  cout << "\t\t     |     |     " << endl;
  cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
  cout << "\t\t_____|_____|_____" << endl;
  cout << "\t\t     |     |     " << endl;
  cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
  cout << "\t\t_____|_____|_____" << endl;
  cout << "\t\t     |     |     " << endl;
  cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
}

 void Choice(int choice )
     {
    if (choice == 1 && board[0][0] != 'X' && board[0][0] != 'O')
    {
        board[0][0] = turn;
      }

    else if (choice == 2 && board[0][1] != 'X' && board[0][1] != 'O')
      {
        board[0][1] = turn;
        
      }
    else if (choice == 3 && board[0][2] != 'X' && board[0][2] != 'O')
    {
        board[0][2] = turn;
      }

    else if (choice == 4 && board[1][0] != 'X' && board[1][0] != 'O')
      {
        board[1][0] = turn;
      }
    else if (choice == 5 && board[1][1] != 'X' && board[1][1] != 'O')
      {
        board[1][1] = turn;
      }
    else if (choice == 6 && board[1][2] != 'X' && board[1][2] != 'O')
      {
        board[1][2] = turn;
      }
    else if (choice == 7 && board[2][0] != 'X' && board[2][0] != 'O')
      {
        board[2][0] = turn;
      }

    else if (choice == 8 && board[2][1] != 'X' && board[2][1] != 'O')
      {
        board[2][1] = turn;
      }
    else if (choice == 9 && board[2][2] != 'X' && board[2][2] != 'O')
      {
        board[2][2] = turn;
      }
    else
    {
      cout << "Box is already filled..TRY AGAIN" << endl;
      cout << "Enter your choice: " << endl;
      cin >> choice;
    }
    
     }
     void player_turn()
{
     if(turn == 'X')
     {
    cout << "Player1 [X] turn...." << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;
    Choice(choice);
    turn = 'O';
     }
     else if(turn == 'O')
     {
     cout << "Player2 [O] turn...." << endl;
     cout << "Enter your choice: " << endl;
     cin >> choice; 
     Choice(choice);
     turn = 'X';       
     }

} 


bool game_over() 
{
    //checking win
   for(int i = 0; i < 3; i++)
   {
       if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]){
           return false;
       }
   }
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        return false;
    }

  //checking all the boxes are fill or not
   for(int i = 0; i < 3; i++)
   {
     for(int j = 0; j < 3; j++)
     {
       if(board[i][j] != 'X' && board[i][j] != 'O')
       {
         return true;
       }
     }
   }
   draw = true;
   return false;

}
main()
{
    while(game_over())
    {

    display_game();
    player_turn();
}
if(turn == 'X' && draw == false)
{
    display_game();
    cout<<"Player[O] is the WINNER!! CONGRATULATIONS!"<<endl;
}
else if(turn == 'O' && draw == false)
{
    display_game();
    cout<<"Player[X] is the WINNER!! CONGRATULATIONS!"<<endl;
}
else{
    cout<<"DRAW"<<endl;
}
}