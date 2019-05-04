
/**********************************************************************************************
 * Program Name: Project1_board.cpp
 * Author:       Tanya Yeu
 * Date:         4/14/2019
 * Description:  This is the source file for the Board class. 
 **********************************************************************************************/
#include"Board.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/**********************************************************************************************
 * Board::Board(char* b, int r, int c)
 * This function takes the 2d array and the ints for the board row and columns as arguments.
 * It will then populate the inner part of the array with white and the edges with the
 * character held in EDGE
 **********************************************************************************************/
Board::Board(char** b, int r, int c)
{
	board = b;
	numRows = r;
	numColumns = c;

	for(int row = 1; row <= numRows -2; row++)
	{
		for (int column = 1; column <= numColumns -2; column++)
		{

			board[row][column] = WHITE;
		}
	} 

	  for(int row = 0; row < numRows; row++)
    {
        board[row][0] = EDGE;
        board[row][numColumns-1] = EDGE;
    }
    for(int column = 0; column < numColumns; column++)
    {
        board[0][column] = EDGE;
        board[numRows-1][column] = EDGE; 
    } 
}

//returns number of columns
int Board::getColumns()
{
	return numColumns;
}

//returns number of rows
int Board::getRows()
{
	return numRows;
}

/**********************************************************************************************
 *char Board::getColor(int r, int c)
 This function takes a row and a column as arguments and returns the current color of that
 space.
 **********************************************************************************************/
char Board::getColor(int r, int c)
{
	char color = board[r][c];

	return color;
}

/**********************************************************************************************
 *void Board::changeColor(int r, int c)
 This function takes a row and a column as arguments and changes the color from white to black
 or black to white depending on it's current color.
 **********************************************************************************************/
void Board::changeColor(int r, int c)
{
	char color = getColor(r, c);
	if (color == WHITE)
		board[r][c] = BLACK;
	else
		board[r][c] = WHITE;

}
