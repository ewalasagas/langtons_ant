/*********************************************************************
** Program name: Project 1
** Author: Elaine Alasagas
** Date: 1/21/2018
** Description: CS162_400_WINTER2019 - Ant.hpp program
*********************************************************************/
#ifndef ANT_H
#define ANT_H

class Ant
{
private:
	int x;
	int y;
	int dir;

public:
	Ant(int x, int y);
	int Get_x();
	int Get_y();
	int get_direction();

	void turnLeft();
	void turnRight();
	void moveForward();
	void antPosition(char **&board);
};

#endif 