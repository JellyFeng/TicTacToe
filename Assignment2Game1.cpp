#include <iostream>
#include "windows.h"
#include <ctime>
#include <string>

using namespace std;

//! global variables
const int GRIDSIZE = 3;
char grid[GRIDSIZE][GRIDSIZE]; //! 2D array size of 3 row 3 columns
int gridToMark = 0;
char currentTurnChar = 'X';//! X player O player
int isXWin = 0;
bool isXTurn=true;
bool winAchieved = false;
bool draw = false;
void InitalizedGrid()
{
	for(int i=0; i<GRIDSIZE; i++)
	{
		for(int j=0; j<GRIDSIZE; j++ )
		{
			grid[i][j]= '#';
		}
	}
}
void DrawGrid()//Dislay board
{
	for(int i=0; i<GRIDSIZE; i++)
	{
		for(int j=0; j<GRIDSIZE; j++ )
		{
			cout<<grid[i][j];
		}
		cout<<endl;
	}
		
}
/* 
1 2 3
4 5 6
7 8 9 legend
*/
void GetInput()
{
	cout<<endl<<"please enter grid number 1-9 to mark: ";
	cin>>gridToMark;
}

void MarkInput(int row, int col)
{
	
	//1. determinethe player turn(X oR O)
	if(isXTurn==true)
	{
		currentTurnChar ='X';
	}
	else
	{
		currentTurnChar ='O';
	}
	//2. Check the selected slot availability --> with # value
	//3. if available replace the # with the player symbol
	//	 else display error message.
	if (grid[row][col] == '#')
	{
		grid[row][col] = currentTurnChar;
		if(isXTurn == true)
		{
			isXTurn = false;
		}
		else
		{
			isXTurn = true;
		}
	}
	else
	{
		cout<<"Error: please input available slots only!"<<endl;
		system("PAUSE");
	}
}

void CheckInput()
{
	if(gridToMark>=1 && gridToMark<=9)
	{
		if(gridToMark==1)
		{
			MarkInput(0,0);
		}
		else if(gridToMark==2)
		{
			MarkInput(0,1);
		}
		else if(gridToMark==3)
		{
			MarkInput(0,2);
		}
		else if(gridToMark==4)
		{
			MarkInput(1,0);
		}
		else if(gridToMark==5)
		{
			MarkInput(1,1);
		}
		else if(gridToMark==6)
		{
			MarkInput(1,2);
		}
		else if(gridToMark==7)
		{
			MarkInput(2,0);
		}
		else if(gridToMark==8)
		{
			MarkInput(2,1);
		}
		else if(gridToMark==9)
		{
			MarkInput(2,2);
		}
	}
}

void CheckWiningCondition()
{
	//! 8 winning direction 3 Horizontal, 3 verticals, 2 diagonals
	//! no winner -> "DRAW GAME"
	if(grid[0][0]== currentTurnChar && grid[0][1]== currentTurnChar &&grid[0][2]== currentTurnChar)
	{
		winAchieved = true;
	}
	else if(grid[1][0]== currentTurnChar && grid[1][1]== currentTurnChar &&grid[1][2]== currentTurnChar)
	{
		winAchieved = true;
	}
	else if(grid[2][0]== currentTurnChar && grid[2][1]== currentTurnChar &&grid[2][2]== currentTurnChar)
	{
		winAchieved = true;
	}
	else if(grid[0][0]== currentTurnChar && grid[1][0]== currentTurnChar &&grid[2][0]== currentTurnChar)
	{
		winAchieved = true;
	}
	else if(grid[0][1]== currentTurnChar && grid[1][1]== currentTurnChar &&grid[2][1]== currentTurnChar)
	{
		winAchieved = true;
	}
	else if(grid[0][2]== currentTurnChar && grid[1][2]== currentTurnChar &&grid[2][2]== currentTurnChar)
	{
		winAchieved = true;
	}
	else if(grid[0][0]== currentTurnChar && grid[1][1]== currentTurnChar &&grid[2][2]== currentTurnChar)
	{
		winAchieved = true;
	}
	else if(grid[2][0]== currentTurnChar && grid[1][1]== currentTurnChar &&grid[0][2]== currentTurnChar)
	{
		winAchieved = true;
	}
	else if (grid[0][0]!= '#' && grid[0][1]!= '#' &&grid[0][2]!= '#' &&
			 grid[1][0]!= '#' && grid[1][1]!= '#' &&grid[1][2]!= '#' &&
			 grid[2][0]!= '#' && grid[2][1]!= '#' &&grid[2][2]!= '#' )
    {
    	winAchieved = true;
    	draw = true;
	}
	else
	{
		winAchieved=false;
	}
	if(winAchieved)
	{
		if(isXTurn)
		{
			isXWin = 2;
		}
		else if(draw)
		{
			isXWin = 3;
		}
		else if (isXTurn=true)
		{
			isXWin = 1;
		}
	}
	else
	{
		isXWin = 0;
	}
}

int main()
{
	bool isExit= false;
	char option=' ';
	do
	{
	InitalizedGrid();
	do
	{
		cout<<currentTurnChar<< " Player Turn." << endl << endl;
		DrawGrid();
		cout<<endl<<"123"<<endl<<"456"<<endl<<"789"<<endl;
		GetInput();
		CheckInput();
		CheckWiningCondition();
		system("CLS");
		cout<<endl;
		
	}while(isXWin == 0);
	DrawGrid();
	//! display winner
	if(isXWin == 1)
	{
		cout<<endl<<endl<<"Player X WIN!"<<endl;
	}
	else if (isXWin == 2)
	{
		cout<<endl<<endl<<"Player O WIN!"<<endl;
	}
	else if (isXWin == 3)
	{
		cout<<endl<<endl<<"No WINNERS!"<<endl;
	}
			if (option== 'y' || option=='Y')
	{
		isExit= false;
	}
	else
	{
		isExit= true;
	}

	cout<<"Do You want to Continue? Y/N"<<endl;
	cin>>option;
	if (option=='y'||option=='Y')
	{
		isXTurn = true;
		isExit = false;
		system ("CLS");
	}
	else
	{
		isExit = true;
	}
	}while(not isExit);
	cout<<endl<<endl;
		system ("PAUSE");
	return 0;
}
