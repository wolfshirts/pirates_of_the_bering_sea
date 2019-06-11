#pragma once
#include <allegro5/allegro.h>

/*
* The SceneManager class handles changing scenes and tracking what to display.
* The actual scenes are handled by the Scene abstract class.
*/


class SceneManager
{	
public:
	SceneManager(ALLEGRO_DISPLAY *display);
	void handle_input(ALLEGRO_EVENT &event);
	void game_logic();
	void draw();
	//The GameState determines what our current gamestate is,
	//
	enum GameState {
		Menu,   //Main game menu
		AtSea,      //Boating around
		Transition, //Maybe used for load screen.
		None,
	};
	void change_scene(GameState newGameState); //Change to the next scene.
private:
	ALLEGRO_DISPLAY *display;
	//Scenes can decide whether or not they want to persist state during changes via the free after use var.
	GameState currentState = GameState::Menu;
	GameState nextState = GameState::None; //The scene to transition to next.
	GameState previousState = GameState::None;
	//This ptr is of an unknown type. Doing things this way allows me
	//a more dynamic approach to management.
	void* currentScene;
	void* previousScene;
};

