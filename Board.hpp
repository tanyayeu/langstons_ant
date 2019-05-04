/**********************************************************************************************
 * Program Name: Project1_board.hpp
 * Author:       Tanya Yeu
 * Date:         4/14/2019
 * Description:  This is the header file for the Board class. This holds the boards color
 *               and board dimensions.
 **********************************************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
  private:
	char **board;
	int numRows, numColumns;
	const char BLACK = '#';
	const char WHITE = ' ';
	const char EDGE = '.';
	const char ANT = '*';

  public:
	Board(char **, int, int);
	int getColumns();
	int getRows();
	char getColor(int, int);
	void changeColor(int, int);
};
#endif