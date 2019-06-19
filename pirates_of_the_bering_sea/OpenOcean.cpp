#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include<string>
#include<vector>
#include<iostream>
#include "OpenOcean.h"
#include "ClockObjectSingleton.h"


OpenOcean::OpenOcean(SceneManager* sceneManager)
{
	this->manager = sceneManager;
	this->load_content();
	crabs = new CrabSchool(400, 400, 400, 400, 400);
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
	crabs->update();
	std::vector<int> crabRect = crabs->get_crab_location();
	//Check for crab collision in pots. This code isn't very clear. It might make sense to
	//Make a rect struct for this stuff.
	if (!bouy_vector.empty()) {
		for (Bouy* x : bouy_vector)
		{	
			std::vector<int> bouyRect = x->get_bouy_rect();
			if (bouyRect[0] < crabRect[0] + crabRect[2] &&
				bouyRect[0] + bouyRect[2] > crabRect[0] &&
				bouyRect[1] < crabRect[1] + crabRect[3] &&
				bouyRect[1] + bouyRect[3] > crabRect[1] &&
				x->can_add_crab()) {
				int schoolRemoval = rand() % crabs->get_school_size();
				if (crabs->get_school_size() - schoolRemoval <= 0) {
					schoolRemoval = crabs->get_school_size();
					delete crabs;
					crabs = new CrabSchool(400, 400, 400, 400, 400);
				}
				else {
					x->add_crab(schoolRemoval);
				}
			}

		}
	}
}

void OpenOcean::draw()
{
	al_clear_to_color(al_map_rgb(0, 50, 255));
	if (!bouy_vector.empty()) {
		for (Bouy* x : bouy_vector) {
			x->draw();
		}
	}
	player->draw();

	//al_draw_text(hudFont, al_map_rgb(0, 0, 0), 0, 0, 0, "Pirates of the Bering Sea");
	std::string time = ClockObjectSingleton::ClockInstance()->get_game_time();
	std::string days = "Day: " + ClockObjectSingleton::ClockInstance()->get_game_day();
	std::string coords = "x: " + std::to_string(player->get_ship_x()) + " y: " + std::to_string(player->get_ship_y());
	al_draw_text(hudFont, al_map_rgb(255, 255, 255), 0, 0, 0, time.c_str());
	al_draw_text(hudFont, al_map_rgb(255, 255, 255), 0, 20, 0, days.c_str());
	al_draw_text(hudFont, al_map_rgb(255, 255, 255), 0, 40, 0, coords.c_str());
}

void OpenOcean::add_bouy()
{
	Bouy* myBouy = new Bouy(player->get_ship_x() + 15, player->get_ship_y());
	bouy_vector.push_back(myBouy);
}

OpenOcean::~OpenOcean()
{
}
