/**********************************************************************************************
 * Program Name: Project1_printAntBoard.hpp
 * Author:       Tanya Yeu
 * Date:         4/14/2019
 * Description:  This is the header file to printing the ant on the board
 **********************************************************************************************/
#ifndef PRINT_ANT_BOARD_HPP
#define PRINT_ANT_BOARD_HPP
#include "Ant.hpp"
#include "Board.hpp"
#include <string>
using std::string;

void printAntBoard(Board*, Ant);
string printAntDirection(int);

#endif