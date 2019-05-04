/**********************************************************************************************
 * Program Name: Project1_printAntBoard.cpp
 * Author:       Tanya Yeu
 * Date:         4/14/2019
 * Description:  This is the source file for printing the ant on the board
 **********************************************************************************************/
#include "printAntBoard.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

/**********************************************************************************************
 * void printAntBoard(Board* b, Ant a)
 * This function takaes a pointer to the board and the ant object. It will print out a copy of 
 * the board with the ant on it without replacing the actual space on the board for the ant.
 * It will dispaly the ant instead of the space
 **********************************************************************************************/
void printAntBoard(Board* b, Ant a)
{
	const char ANT = '*';
	int antRow = a.getRow();
	int antCol = a.getColumn();
	int numRows = b->getRows();
	int numColumns = b->getColumns();

	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numColumns; j++)
		{
			//if ants coords match the index
			if (i == antRow && j == antCol)
			{
				cout << ANT << " ";
			}
			else
			{
				cout << b->getColor(i, j) << " ";
			}
		}
		cout << endl;
	} 
}

/**********************************************************************************************
 * string printAntDirection(d)
 * This function returns a string based on the ant's direction. It is used for readability
 * purposes. 
 **********************************************************************************************/
string printAntDirection(int d)
{
        string dir;
	if(d == 1)
	{
		dir = "up";
	}
	if(d == 2)
	{
		dir = "right";
	}
	if(d == 3)
	{
		dir = "down";
	}
	if(d == 4)
	{
		dir = "left";
	}
        return dir;
}     
