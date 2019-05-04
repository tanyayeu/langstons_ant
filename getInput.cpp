/**********************************************************************************************
 * Program Name: Project1_getInput.cpp
 * Author:       Tanya Yeu
 * Date:         4/14/2019
 * Description:  This is the source file for the helper functions to get input
 **********************************************************************************************/
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::stoi;
using std::string;

/**********************************************************************************************
 *int getInput()
 This function takes the user entry as a string and validates whether it is an integer.
 It will reject floats, doubles, and strings leading integers. It then converts it to an int
 and returns it. It will also reject null entries
 **********************************************************************************************/
int getInput()
{
    string strNumber;
    int iNumber;
    do
    {

        getline(cin, strNumber); //getline
        while (cin.fail() || cin.eof() || strNumber.find_first_not_of("0123456789") != string::npos)
        {
            cout << "Please enter a valid number." << endl;
            if (strNumber.find_first_not_of("0123456789") == string::npos)
            {
                cin.clear();
                cin.ignore(1000, '\n');
            }
            std::getline(cin, strNumber);
        }
        if(strNumber.empty())
        {
            cout << "Please enter a valid number." << endl;
        }
    } while (strNumber.empty());

    string::size_type st;
    iNumber = stoi(strNumber, &st);
    return iNumber;
}

/*
source: https://stackoverflow.com/questions/18728754/checking-cin-input-
\stream-produces-an-integer
*/
/**********************************************************************************************
 *bool isVaildMen(int input)
 This function validates whether the user has entered a valid number
 **********************************************************************************************/
bool isValidMenu(int input)
{
    if (input < 1 || input > 2)
    {
        return false;
    }
    else
    {
        return true;
    }
}
/**********************************************************************************************
 *bool isVaild(int input, int min, int max)
 This function returns false if the input is out of boundaries.
 **********************************************************************************************/
bool isValid(int input, int min, int max)
{
    if (input < min || input > max)
    {
        return false;
    }
    else
        return true;
}
/**********************************************************************************************
 *bool displayMenu()
 This function displays the menu items.
 **********************************************************************************************/
void displayMenu()
{
    cout << "1. Play Ant Simulator." << endl;
    cout << "2. Quit." << endl;
}
