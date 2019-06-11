#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include "OpenOcean.h"


OpenOcean::OpenOcean(SceneManager* sceneManager)
{
	this->manager = sceneManager;
	boatX = 10;
	boatY = 10;
	boatVelocityX = 0;
}

void OpenOcean::load_content()
{
	this->boatGraphic = al_load_bitmap("Assets/boat.jpg");
	al_convert_mask_to_alpha(this->boatGraphic, al_map_rgb(255, 0, 255));
}

void OpenOcean::unload_content()
{
}

void OpenOcean::handle_events(ALLEGRO_EVENT& e)
{
	if (e.keyboard.keycode == ALLEGRO_KEY_UP) {
		boatThrust += 1;
	}
}

void OpenOcean::game_logic()
{
	boatX += boatVelocityX;
}

void OpenOcean::draw()
{
	al_clear_to_color(al_map_rgb(0, 50, 255));
	al_draw_bitmap(this->boatGraphic, boatX, boatY, 0);
}

OpenOcean::~OpenOcean()
{
}
