/**********************************************************************************************
 * Program Name: Project1_main.cpp
 * Author:       Tanya Yeu
 * Date:         4/14/2019
 * Description:  Langston's Ant simulation will prompt the user to play the game or quit.
 *               It will then prompt the user for number of rows and columns for the board
 *               and either a random position for the ant starting positon or a user set
 *               one. It will prompt for the number of steps, and loop through until
 *               it has reached the total number of steps. The ant will move right at a white
 *               square, and left at black square. It will prompt the user if they want to play
 *               again.
 **********************************************************************************************/
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
#include "getInput.hpp"
#include "Board.hpp"
#include "Ant.hpp"
#include "printAntBoard.hpp"

int main()
{
    const int MAX_SIZE = 50; //setting max size for the board so that it doesn't go off screen
    const int MIN_SIZE = 2;
    const int MIN_STEPS = 2;
    const int MAX_STEPS = 2000; //limiting number of steps 
    int input, numRows, numColumns, antRow, antColumn, randChoice;
    int steps = 0;

    cout << "Welcome to Langston's Ant Simulation!" << endl;
    displayMenu();
    input = getInput();
    while (!isValid(input, 1, 2))
    {
        cout << "Please enter 1 or 2." << endl;
        input = getInput();
    }
    while (input == 1)
    {
        cout << "Would you like to use a random starting location for the ant?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        randChoice = getInput();
        while (!isValid(randChoice, 1, 2))
        {
            cout << "Please enter 1 or 2." << endl;
            randChoice = getInput();
        }
        if(randChoice ==1) //if the user has chosen a random location, generate it after geting board inputs
        {   cout << "**EXTRA CREDIT EDITION**" << endl;
            cout << "A random location will be chosen for you after you have decided the board size." << endl;
        }

        cout << "\nHow big would you like the board to be?" << endl;
        cout << "Please choose a number between " << MIN_SIZE << " and " << MAX_SIZE << endl;
        cout << "Number of rows: ";
        numRows = getInput() + 2; //adding 2 to make room for borders
        while (!isValid(numRows, MIN_SIZE, MAX_SIZE + 2))
        {
            cout << "Please enter a valid number." << endl;
            numRows = getInput() + 2;
        }

        cout << "Number of columns: ";
        numColumns = getInput() + 2; 
        while (!isValid(numColumns, MIN_SIZE, MAX_SIZE + 2)) //max size must also increase for borders
        {
            cout << "Please enter a valid number." << endl;
            numColumns = getInput() + 2;
        }

        cout << endl;
        if(randChoice == 1) //generate random location here
        {
            cout << "A random location has been chosen for you." << endl;
            antRow = rand() % ((numRows-2)-1)+1;
            antColumn = rand()% ((numColumns-2) +1) -1;
            cout << "The ant's starting position will be (" << antRow << ", "<< antColumn << ")" << endl;
        }

        //if user chose not to have a random location, prompt for inputs
        if (randChoice == 2)
        {
            cout << "\nChoose the location for the ant." << endl;
            cout << "Pick a row number between 1 and " << numRows - 2 << endl;
            cout << "Row number: ";
            antRow = getInput();
            while (!isValid(antRow, 1, numRows - 2)) //these will be numbers between the borders
            {
                cout << "Please enter a row on the board." << endl;
                antRow = getInput();
            }

            cout << "Please pick a column number between 1 and " << numColumns - 2 << endl;
            antColumn = getInput();
            while (!isValid(antColumn, 1, numColumns - 2))
            {
                cout << "Please enter a column on the board.";
                cout << "Column number: ";
                antColumn = getInput();
            }
        }
        
        
        cout << "\nHow many steps should the ant take?" << endl;
        cout << "Please enter a number between " << MIN_STEPS << " and " << MAX_STEPS << ".\n";
        cout << "Steps: ";
        steps = getInput();
        while (!isValid(steps, MIN_STEPS, MAX_STEPS))
        {
            cout << "Please enter a number between " << MIN_STEPS << " and " << MAX_STEPS << ".\n";
            steps = getInput();
        }

        //dynamically allocate memory for the 2d array
        char **arrBoard = new char *[numRows];
        for (int row = 0; row < numRows; row++)
            arrBoard[row] = new char[numColumns];

        //new Board and Ant objects using the 2D array,

        Board *board = new Board(arrBoard, numRows, numColumns);
        Ant ant(board, antRow, antColumn);
        //loop through to moveant
        for (int stepCounter = 1; stepCounter <= steps; stepCounter++)
        {

            //int variables to hold the ants location before it moves
            int aRow = ant.getRow();
            int aCol = ant.getColumn();
            
            ant.moveAnt(aRow, aCol);
            //prints a board with an ant on it
            cout << "Step: " << stepCounter << endl;
            //print the direction the ant went during this step
            cout << "Ant went " << printAntDirection(ant.getDirection()) << endl;
            //print out current location
            cout << "The ant's coordinates are (" << ant.getRow() << ", " << ant.getColumn() << ")." << endl;
            printAntBoard(board, ant);

            //wait for user input to continue
            cout << "Please hit enter for next step." << endl;
            cin.get();
        }

        cout << "Would you like to play again?" << endl;
        displayMenu();
        input = getInput();
        while (!isValid(input, 1, 2))
        {
            cout << "Please enter 1 or 2." << endl;
            input = getInput();
        }

        //free up the memory
        for (int row = 0; row < numRows; row++)
        {
            delete[] arrBoard[row];
        }
        delete[] arrBoard;
        delete board;
    }

    //if the user hits Quit on the menu, program terminates
    if (input == 2)
    {
        return 0;
    }
}

/*
source for random numbers
https://stackoverflow.com/questions/12657962/how-do-i-generate-a-random-number-between-two-variables-that-i-have-stored/12658029
*/