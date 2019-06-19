#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <vector>
#include "SceneManager.h"
#include "PlayerShip.h"
#include "Bouy.h"
#include"CrabSchool.h"

class OpenOcean
{
public:
	OpenOcean(SceneManager* sceneManager);
	bool free_after_use = false;
	void load_content();
	void unload_content();
	void handle_events(ALLEGRO_EVENT& e);
	void game_logic();
	void draw();
	void add_bouy();
	
	~OpenOcean();
private:
	SceneManager* manager;
	int player_x = 400;
	int player_y = 400;
	PlayerShip* player = new PlayerShip(player_x, player_y, this);
	ALLEGRO_FONT* hudFont = nullptr;
	std::vector<Bouy*> bouy_vector;
	CrabSchool* crabs = nullptr;
};

