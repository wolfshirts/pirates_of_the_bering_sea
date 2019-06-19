#include "CrabSchool.h"
#include"ClockObjectSingleton.h"
#include<cstdlib>
#include<ctime>
#include<iostream>

CrabSchool::CrabSchool(int x, int y, int bottom_x, int bottom_y, int crabs)
{
	crabsInSchool = crabs;
	crabTopX = x;
	crabTopY = y;
	crabBottomX = bottom_x;
	crabBottomY = bottom_y;
	srand(time(NULL));
	crabMovementX += rand() % 3;
	crabMovementY += rand() % 3;
	setTime = ClockObjectSingleton::ClockInstance()->get_ticks();
}

void CrabSchool::update()
{
	//if time has been 15 minutes this updates the crab.
	//But for now we'll update crab every 3 seconds
	if ((ClockObjectSingleton::ClockInstance()->get_ticks() - setTime) % 180 == 0) {
		crabMovementX = rand() % 3;
		crabMovementY = rand() % 3;
		std::cout << "Updating crabs."<<std::endl;
		std::cout << crabTopX << "," << crabTopY << std::endl;
		crabTopX += crabMovementX;
		crabTopY += crabMovementY;
	}
}

void CrabSchool::remove_crab(int crab)
{
	crabsInSchool -= crab;
}

void CrabSchool::change_crab_direction(int x, int y)
{
	crabMovementX += x;
	crabMovementY += y;
}

int CrabSchool::get_school_size()
{
	return crabsInSchool;
}

std::vector<int> CrabSchool::get_crab_location()
{
	std::vector<int> crabRect = { crabTopX, crabTopY, crabBottomX, crabBottomY };
	return crabRect;
}

CrabSchool::~CrabSchool()
{
}
