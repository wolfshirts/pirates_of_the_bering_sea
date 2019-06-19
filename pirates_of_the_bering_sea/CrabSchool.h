#pragma once
#include<vector>
class CrabSchool
{
public:
	CrabSchool(int x, int y, int width, int height, int crabs); //Set rect size of school and number of crab.
	void update();
	void remove_crab(int crab);
	void change_crab_direction(int x, int y);
	int get_school_size();
	std::vector<int> get_crab_location();
	~CrabSchool();
private:
	int crabsInSchool = 0;
	int crabTopX = 0;
	int crabTopY = 0;
	int crabBottomX = 0;
	int crabBottomY = 0;
	int crabMovementX = 0;
	int crabMovementY = 0;
	uint64_t setTime = 0;
};

