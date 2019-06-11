#include "MainMenu.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include "SceneManager.h"

MainMenu::MainMenu(SceneManager* manager){
	this->manager = manager;
	//configure our nodes for menu management.
	StartNode.selection = MenuSelection::Start;
	StartNode.red = 255;
	StartNode.green = 0;
	StartNode.blue = 0;
	//point to continue
	MenuNode* cont = &ContinueNode;
	StartNode.next = cont;

	ContinueNode.selection = MenuSelection::Continue;
	ContinueNode.red = 255;
	ContinueNode.green = 0;
	ContinueNode.blue = 0;
	//point back to our start menu item.
	MenuNode* startPtr = &StartNode;
	ContinueNode.next = startPtr;

	//set the default mode
	currentNode = &StartNode;
}


void MainMenu::load_content(){
	this->pirateFont = al_load_ttf_font("Assets/Treamd.ttf", 64, 0);
	this->oceanOne = al_load_bitmap("Assets/water1.png");
	this->oceanTwo = al_load_bitmap("Assets/water2.png");
	this->oceanThree = al_load_bitmap("Assets/water3.png");
	this->oceanFour = al_load_bitmap("Assets/water4.png");
	backGround[0] = oceanOne;
	backGround[1] = oceanTwo;
	backGround[2] = oceanThree;
	backGround[3] = oceanFour;
}

//In this case the class is disposable. So it's fine to use the destructor.
//Instead of unload content. In fact it should be used instead.
//In non-destroyable classes we will probably want a load an unload to
//reduce memory footprint.
void MainMenu::unload_content()
{
	al_destroy_font(pirateFont); //clear the pirate font.
}

void MainMenu::handle_events(ALLEGRO_EVENT &e)
{
	if (e.keyboard.keycode == ALLEGRO_KEY_LEFT || e.keyboard.keycode == ALLEGRO_KEY_RIGHT ||
		e.keyboard.keycode == ALLEGRO_KEY_DOWN || e.keyboard.keycode == ALLEGRO_KEY_UP) {
		currentNode = currentNode->next;
	}
}

void MainMenu::game_logic()
{
	updateCounter += 1;
	if (updateCounter % playSpeed == 0) {
		if (backgroundCounter + 1 > 3) {
			backgroundCounter = 0;
		}
		else {
			backgroundCounter += 1;
		}
	}
}

void MainMenu::draw()
{
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_draw_bitmap(backGround[backgroundCounter], 0, 0, 0);
	al_draw_text(pirateFont, al_map_rgb(0, 0, 0), 0, 0, 0, "Pirates of the Bering Sea");
	if (currentNode->selection == MenuSelection::Start) {
		al_draw_text(pirateFont, al_map_rgb(currentNode->red, currentNode->green, currentNode->blue), 20, 60, 0, "New Game");
		
		al_draw_text(pirateFont, al_map_rgb(currentNode->defaultRed, currentNode->defaultGreen, currentNode->defaultBlue), 
			20, 120, 0, "Continue");
	}

	if (currentNode->selection == MenuSelection::Continue) {
		al_draw_text(pirateFont, al_map_rgb(currentNode->defaultRed, currentNode->defaultGreen, currentNode->defaultBlue), 
			20, 60, 0, "New Game");
		
		al_draw_text(pirateFont, al_map_rgb(currentNode->red, currentNode->green, currentNode->blue), 20, 120, 0, "Continue");
	}
}

MainMenu::~MainMenu()
{
	al_destroy_font(pirateFont); //clear the pirate font.
	int backgroundArraySize = sizeof(backGround) / sizeof(ALLEGRO_BITMAP*);
	for (size_t i = 0; i < backgroundArraySize; i++)
	{
		al_destroy_bitmap(backGround[i]);
	}
}



