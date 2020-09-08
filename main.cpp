/*********************************************************************
** Program name: Project 1
** Author: Elaine Alasagas
** Date: 1/21/2018
** Description: CS162_400_WINTER2019 - Main program that executes 
	Langton's Ant. I had a hard time finding the correct input 
	validation but found the following StackOverflow site and used
	their way of validating -
	https://stackoverflow.com/questions/2075898/good-input-validation-loop-using-cin-c/2076144#2076144 
*********************************************************************/
#include <iostream>
#include <stdlib.h>
#include <limits>
#include "Ant.hpp"
using namespace std;

int main()
{
	int choice;		//Select from menu
	int steps;			//how many steps
	int boardRow;
	int boardCol;

	int **board_ant;
	int antX;		//ant coordinates 
	int antY;		//ant coordinates 

	int dir = 0;	//direction of ant
	int up = 0;
	int right = 1;
	int down = 2;
	int left = 3;

	//Menu
while (true)
{
	std::cout << "Langton's Ant Program\n" << endl;
	std::cout << "Please type in 1 or 2" << endl;
	std::cout << "1. Start program" << endl;
	std::cout << "2. Quit" << endl;
	std::cout << "Choice: ";
	//Input validation of choice
	if (std::cin >> choice && (choice == 1 || choice == 2))	
	{
		break;
	}
	else
	{
		cout << "Please enter a valid choice" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}
		if (choice == 1)
		{
			std::cout << "Please select the size of the board." << std::endl;
			while (true)
			{
				std::cout << "Number of rows: ";
				//Input validation of rows
				if (std::cin >> boardRow && (boardRow > 1))
				{
					break;
				}
				else
				{
					cout << "Please enter a number of rows" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			while (true)
			{
				std::cout << "Number of columns: ";
				//Input validation of columns
				if (std::cin >> boardCol && (boardCol > 1))
				{
					break;
				}
				else
				{
					cout << "Please enter a number of columns" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			while (true)
			{
				//Input validation of steps
				std::cout << "Number of steps: ";
				if (std::cin >> steps && (steps > 0))
				{
					break;
				}
				else
				{
					cout << "Please enter a number of steps" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			while (true)
			{
				//Input validation of ant x
				std::cout << "Starting row of ant: ";
				if (std::cin >> antX && (antX > 0 && antX < boardRow))
				{
					break;
				}
				else
				{
					cout << "Please enter a valid starting row (must be less than board size)." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			while (true)
			{
				//Input validation of ant y
				std::cout << "Starting column of ant: ";
				if (std::cin >> antY && (antY > 0 && antY < boardCol))
				{
					break;
				}
				else
				{
					cout << "Please enter a valid starting column (must be less than board size)." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			//Initialize class
			Ant *ant = new Ant(antX, antY);

			//Parameters to initialize board
			char **board = new char*[boardRow];
			char **board_ant = new char*[boardRow];
			for (int i = 0; i < boardRow; i++)
			{
				board[i] = new char[boardCol];
				board_ant[i] = new char[boardCol];
			}

			//board white spaces set to blank
			for (int i = 0; i < boardRow; i++)
			{
				for (int j = 0; j < boardCol; j++)
				{
					board[i][j] = ' ';
				}
			}

			//Ant movement Starts
			for (int n = 0; n < steps; n++)
			{
				if (board[ant->Get_x()][ant->Get_y()] == ' ')
				{
					ant->turnRight();
					board[ant->Get_x()][ant->Get_y()] = '#';
				}
				else if (board[ant->Get_x()][ant->Get_y()] == '#')
				{
					//turn left
					ant->turnLeft();
					board[ant->Get_x()][ant->Get_y()] = ' ';
				}
				else {
					std::cout << "Error. Please restart program." << std::endl;
					std::terminate();
				}

				//Ant moves forward
				ant->moveForward();

				//Copy ant-board to board
				for (int y = 0; y < boardRow; y++)
				{
					for (int x = 0; x < boardCol; x++)
					{
						board_ant[x][y] = board[x][y];
					}
				}
				//Print ant
				ant->antPosition(*&board_ant);

				//output display
				for (int y = 0; y < boardRow; y++)
				{
					for (int x = 0; x < boardCol; x++)
					{
						std::cout << board_ant[x][y];
					}
					std::cout << std::endl;
				}
				//FLUSH BOARD
				//system("CLS");	//run for windows
				system ("clear");	//run for unix
			}
		}
		else if (choice == 2) {

			std::cout << "End program\n";
			return 0;
		}
		return 0;
	}


