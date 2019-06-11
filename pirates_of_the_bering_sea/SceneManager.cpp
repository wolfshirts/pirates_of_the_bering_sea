#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include "SceneManager.h"
#include "MainMenu.h"
#include "OpenOcean.h"

/*
* The SceneManager class handles changing scenes and tracking what to display.
* The actual scenes are handled by the Scene abstract class.
*/

SceneManager::SceneManager(ALLEGRO_DISPLAY* display)
{
	this->display = display;
	this->previousScene = nullptr;
	SceneManager* sceneManPtr = this;
	//MainMenu *mainMenu = new MainMenu(sceneManPtr);
	//mainMenu->load_content();
	OpenOcean* openOcean = new OpenOcean(sceneManPtr);
	openOcean->load_content();
	this->currentState = GameState::AtSea;
	this->currentScene = openOcean;
}


void SceneManager::handle_input(ALLEGRO_EVENT &event)
{
	if (this->currentState == GameState::Menu) {
		MainMenu* menuPtr = static_cast<MainMenu*>(currentScene);
		menuPtr->handle_events(event);
	}

	if (this->currentState == GameState::AtSea) {
		OpenOcean* ocean = static_cast<OpenOcean*>(currentScene);
		ocean->handle_events(event);
	}
}

void SceneManager::game_logic()
{
	if (this->currentState == GameState::Menu) {
		MainMenu *menuPtr = static_cast<MainMenu*>(currentScene);
		menuPtr->game_logic();
	}

	if (this->currentState == GameState::AtSea) {
		static_cast<OpenOcean*>(currentScene)->game_logic();
	}
}

void SceneManager::draw()
{
	if (this->currentState == GameState::Menu) {
		MainMenu *menuPtr = static_cast<MainMenu*>(currentScene);
		menuPtr->draw();
	}

	if (this->currentState == GameState::AtSea) {
		static_cast<OpenOcean*>(currentScene)->draw();
	}
	al_flip_display(); //flip display makes buffer visible to user.
}

void SceneManager::change_scene(GameState newGameState)
{
	switch (currentState)
	{
	case SceneManager::Menu:
		this->previousScene = this->currentScene; //move the old scene to previous scene.
		MainMenu* menuPtr = static_cast<MainMenu*>(previousScene); //cast to main menu since we know it is menu.
		menuPtr->unload_content(); //call unload content, even though it's handled in destructor when we delete.
		delete menuPtr; //get rid of the menu, we don't need it anymore.
		break;
	}

	switch (newGameState)
	{
	case SceneManager::Menu:
		//handle instantiation logic.
		break;
	case SceneManager::AtSea:
		break;
	case SceneManager::Transition:
		break;
	case SceneManager::None:
		break;
	default:
		break;
	}
}
