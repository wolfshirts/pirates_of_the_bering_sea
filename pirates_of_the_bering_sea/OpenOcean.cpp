#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include<string>
#include "OpenOcean.h"
#include "ClockObjectSingleton.h"


OpenOcean::OpenOcean(SceneManager* sceneManager)
{
	this->manager = sceneManager;
	this->load_content();
}

void OpenOcean::load_content()
{
	//this->hudFont = al_load_font("Assets/joystix_monospace.ttf", 70, 0);
	this->hudFont = al_load_ttf_font("Assets/joystix_monospace.ttf", 20, 0);
}

void OpenOcean::unload_content()
{
	al_destroy_font(this->hudFont);
}

void OpenOcean::handle_events(ALLEGRO_EVENT& e)
{
	//Some stuff gets passed to the player, other stuff
	//is handled by the ocean
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
	if (e.keyboard.keycode == ALLEGRO_KEY_SPACE) {
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
	//al_draw_text(hudFont, al_map_rgb(0, 0, 0), 0, 0, 0, "Pirates of the Bering Sea");
	std::string time = ClockObjectSingleton::ClockInstance()->get_game_time();
	std::string days = "Day: " + ClockObjectSingleton::ClockInstance()->get_game_day();
	al_draw_text(hudFont, al_map_rgb(255, 255, 255), 0, 0, 0, time.c_str());
	al_draw_text(hudFont, al_map_rgb(255, 255, 255), 0, 20, 0, days.c_str());
}

OpenOcean::~OpenOcean()
{
}
