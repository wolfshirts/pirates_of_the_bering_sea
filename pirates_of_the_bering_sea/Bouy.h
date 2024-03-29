#pragma once
#include <allegro5/allegro.h>
#include <vector>
#include"ClockObjectSingleton.h"

class Bouy
{
	//Bouy is tied to the ship, it contains a vector of bouys.
	//Which is initially empty. Bouy gets co-ords where it's set.
public:
	Bouy(float x, float y);
	void add_crab(int crab); //add crab to pot.
	void draw();
	int get_x();
	int get_y();
	bool can_add_crab();
	std::vector<int> get_bouy_rect();
	~Bouy();
private:
	//bouy x, y co-ords
	float bouy_x = 0;
	float bouy_y = 0;
	//gets loaded up on instantiation
	ALLEGRO_BITMAP* bouyGraphic = nullptr;
	//what image are we on?
	int imageCounter = 0;
	//bouy vector.
	std::vector<ALLEGRO_BITMAP*> bouyVector;
	int playSpeed = 60;
	int updateCounter = 0;
	int crabCount = 0;
	int setTime = 0;
};

