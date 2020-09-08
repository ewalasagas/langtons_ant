/*********************************************************************
** Program name: Project 1
** Author: Elaine Alasagas
** Date: 1/21/2018
** Description: CS162_400_WINTER2019 - Ant.cpp file - shows location 
	and position ant.
*********************************************************************/
#include <iostream>
#include <stdlib.h>
#include <limits>
#include "Ant.hpp"
using namespace std;

Ant::Ant(int x_input, int y_input)
{
	x = x_input;
	y = y_input;
	dir = 0;
}

int Ant::get_direction()
{
	return dir;
}
int Ant::Get_x()
{
	return x;
}

int Ant::Get_y()
{
	return y;
}

void Ant::turnLeft()
{
	switch (dir)
	{
	case 0:	dir = 3;
		break;
	case 1:	dir = 0;
		break;
	case 2:	dir = 1;
		break;
	case 3:	dir = 2;
		break;
	}
}
void Ant::turnRight()
{
	switch (dir)
	{
	case 0:	dir = 1;
		break;
	case 1:	dir = 2;
		break;
	case 2:	dir = 3;
		break;
	case 3:	dir = 0;
		break;
	}
}
void Ant::moveForward()
{
	switch (dir)
	{
	case 0:	y--;
		break;
	case 1:	x++;
		break;
	case 2:	y++;
		break;
	case 3:	x--;
		break;
	}
}

void Ant::antPosition(char **&board)
{
	switch (dir)
	{
	case 0:
		board[x][y] = '^';
		break;
	case 1:
		board[x][y] = '>';
		break;
	case 2:
		board[x][y] = 'v';
		break;
	case 3:
		board[x][y] = '<';
		break;
	}
}
