#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include "OpenOcean.h"


OpenOcean::OpenOcean(SceneManager* sceneManager)
{
	this->manager = sceneManager;
}

void OpenOcean::load_content()
{
	
}

void OpenOcean::unload_content()
{
}

void OpenOcean::handle_events(ALLEGRO_EVENT& e)
{
	if (e.keyboard.keycode == ALLEGRO_KEY_LEFT) {
		player->handle_input(e);
	}
	if (e.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
		player->handle_input(e);
	}
	if (e.keyboard.keycode == ALLEGRO_KEY_UP) {
		player->handle_input(e);
	}
	if (e.keyboard.keycode == ALLEGRO_KEY_DOWN) {
		player->handle_input(e);
	}
}

void OpenOcean::game_logic()
{
	player->update();
}

void OpenOcean::draw()
{
	al_clear_to_color(al_map_rgb(0, 50, 255));
	player->draw();
}

OpenOcean::~OpenOcean()
{
}
