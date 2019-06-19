#include "CrabSchool.h"
#include"ClockObjectSingleton.h"
#include<cstdlib>
#include<iostream>

CrabSchool::CrabSchool(int x, int y, int bottom_x, int bottom_y, int crabs)
{
	crabsInSchool = crabs;
	crabTopX = x;
	crabTopY = y;
	crabBottomX = bottom_x;
	crabBottomY = bottom_y;
	crabMovementX += rand() % 3;
	crabMovementY += rand() % 3;
	setTime = ClockObjectSingleton::ClockInstance()->get_ticks();
}

void CrabSchool::update()
{
	//if time has been 15 minutes this updates the crab.
	if (setTime % 9000 == 0) {
		std::cout << "Updating crab.";
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

std::vector<int> CrabSchool::get_crab_location()
{
	std::vector<int> crabRect = { crabTopX, crabTopY, crabBottomX, crabBottomY };
	return crabRect;
}

CrabSchool::~CrabSchool()
{
}
