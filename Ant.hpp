
/**********************************************************************************************
 * Program Name: Project1_ant.hpp
 * Author:       Tanya Yeu
 * Date:         4/14/2019
 * Description:  This is the header file for the Ant class. This class will hold the ant's
 *               direction and location. It also contains functions to move the ant.
 **********************************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP
#include "Board.hpp"


class Ant
{
private:
	Board* board;
	int antRow, antColumn, direction;
	const int UP = 1;
	const int RIGHT = 2;
	const int DOWN = 3;
	const int LEFT = 4;
	const char BLACK = '#';
	const char WHITE = ' ';

public:
	Ant(Board*, int, int);
	int getRow();
	int getColumn();
	void moveAnt(int, int);
    int getDirection();
	void turnRight();
	void turnLeft();
	void moveForward();
};

#endif
