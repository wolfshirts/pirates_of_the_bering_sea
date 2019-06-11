#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include "SceneManager.h"

class MainMenu
{
public: 
	MainMenu(SceneManager *sceneManager);
	bool free_after_use = true;
	void load_content();
	void unload_content();
	void handle_events(ALLEGRO_EVENT &e);
	void game_logic();
	void draw();
	~MainMenu();
private:
	//our pirate font.
	ALLEGRO_FONT* pirateFont = nullptr;
	ALLEGRO_BITMAP* oceanOne = nullptr;
	ALLEGRO_BITMAP* oceanTwo = nullptr;
	ALLEGRO_BITMAP* oceanThree = nullptr;
	ALLEGRO_BITMAP* oceanFour = nullptr;

	ALLEGRO_BITMAP* backGround[4]; //Pointers to our backgrounds!@#!
	int backgroundCounter = 0;
	//link back to the manager to change scenes.
	SceneManager* manager = nullptr;

	//updateCounter counts number of times this class has been called.
	//if it overflows, it doesn't matter.
	int updateCounter = 0;
	//updateCounter % playSpeed 60 = once per second.
	int playSpeed = 30; 

	//Different menu selection types.
	enum MenuSelection {
		Start,
		Continue,
	};
	
	struct MenuNode {
		MenuSelection selection;
		MenuNode* next;
		int red;
		int green;
		int blue;
		int defaultRed = 10;
		int defaultGreen = 10;
		int defaultBlue = 10;
	};
	
	MenuNode StartNode;
	MenuNode ContinueNode;
	MenuNode* currentNode;
};

