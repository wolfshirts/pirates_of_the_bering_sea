#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include "SceneManager.h";

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
	
	~OpenOcean();
private:
	SceneManager* manager;
	int boatX = 10;
	int boatY = 10;
	int boatVelocityX = 0;
	int boatVelocityY = 0;
	int boatThrust = 0;
	ALLEGRO_BITMAP* boatGraphic = nullptr;
};

