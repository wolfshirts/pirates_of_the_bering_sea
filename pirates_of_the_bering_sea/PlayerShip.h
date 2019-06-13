#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include<allegro5/fixed.h>
#include <vector>
#include"Bouy.h"

class PlayerShip
{
public:
	//create the ship and tell it where it is.
	PlayerShip(int x, int y);
	~PlayerShip();
	//Figure out our heading and rotate the boat accordingly.
	ALLEGRO_BITMAP* get_boat_graphic();
	
	void load_assets();
	void unload_assets();
	void handle_input(ALLEGRO_EVENT &e);
	void update();
	void draw();

	
	//get ship x co-ord
	float get_ship_x();
	//get ship y co-ord
	float get_ship_y();
	//get ship x velocity from weather effects
	int get_ship_velocity_x();
	//get ship y velocity from weather effects
	int get_ship_velocity_y();
	//add ship velocity: x, y for use with weather.
	void add_velocity(int x, int y);
	//upgrade ship velocity
	void upgrade_ship_velocity(int amount);
	
private:
	float ship_x = 0.0f;
	float ship_y = 0.0f;
	float ship_x_velocity = 0.0f;
	float ship_y_velocity = 0.0f;
	float player_velocity = 0.0f;
	float player_angle = 0.0f;
	ALLEGRO_BITMAP* boatGraphic = nullptr;
	float max_velocity = .1f;
	float ship_x_center;
	float ship_y_center;
	std::vector<Bouy*> shipBouys;
	int bouyTimer = 0;
	int bouyLaunchTime = 180; //one every three seconds, upgradable;
	int maxBouys = 10; //our max bouys, can be adjusted later via items.
	bool canLaunchBouy = true;
};

