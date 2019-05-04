/**********************************************************************************************
 * Program Name: Project1_ant.cpp
 * Author:       Tanya Yeu
 * Date:         4/14/2019
 * Description:  This is source file for Ant class. It has functions to move the ant and return
 *               it's location.
 **********************************************************************************************/
#include "Ant.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/**********************************************************************************************
 * Ant::Ant(Board* b, int r, int c)
 * This function takes a pointer to the board object, and ints for the row and column of the ant.
 * It sets the ant's starting location and initial direction as up.
 **********************************************************************************************/
Ant::Ant(Board* b, int r, int c)
{
	board = b;
	antRow = r;
	antColumn = c;
	direction = UP;
}

int Ant::getRow()
{
	return antRow;
}

int Ant::getColumn()
{
	return antColumn;
}

int Ant::getDirection()
{
	return direction;
}
/**********************************************************************************************
 * void Ant::turnRight()
 * This will function changes the ant's direction to right based on it's current direction.
 * It will move the direction clockwise. 
 **********************************************************************************************/
void Ant::turnRight()
{
	if(direction == LEFT)
	{
		direction = UP;
	}
	else 
	{
		direction++;
	}
}

/**********************************************************************************************
 * void Ant::turnRight()
 * This will function changes the ant's direction to left based on it's current direction.
 * It will move the direction counterclockwise. 
 **********************************************************************************************/
void Ant::turnLeft()
{
	if(direction == UP)
    {
        direction = LEFT;
    }
    else
    {
        direction--;
    }
}

/**********************************************************************************************
 * void Ant::moveForward()
 * This function moves the ant's location 1 space based on the direction it is currently facing
 **********************************************************************************************/
void Ant::moveForward()
{
	if(direction == RIGHT)
	{
		antColumn++;
	}
	if(direction == DOWN)
	{
		antRow++;
	}
	if(direction == UP)
	{
		antRow--;
	}
	if(direction == LEFT)
	{
		antColumn--;
	}	
}

/**********************************************************************************************
 * void Ant::moveAnt(int r, int c)
 * This function uses the ant's current location and gets the color of the space it is
 * currently on to determine whether it will turn right or left. Afterwards it will move the ant
 * forward one space. If the ant goes off the board, it will loop back to the other side of 
 * the board and continue in the same path.
 **********************************************************************************************/
void Ant::moveAnt(int r, int c)
{
	//if the space is white
    if (board->getColor(r, c) == WHITE)
    {	
        turnRight();
    } 

	//if the space is black
	else 
	{
		turnLeft();
	}

	board->changeColor(r, c);

	moveForward();
	//if it goes off the board, wrap it around the other side
	if(antColumn > (board->getColumns() - 2))
	{
		antColumn  = 1;
	}
	if(antColumn  < 1)
	{
		antColumn = (board->getColumns()-2);
	}
	if(antRow > (board->getRows() - 2))
	{
		antRow  = 1;
	}
	if(antRow  < 1)
	{
		antRow = (board->getRows()-2);
	}

	
}
