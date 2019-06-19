#include "Bouy.h"
#include <allegro5/allegro.h>

Bouy::Bouy(float x, float y)
{
	this->bouy_x = x;
	this->bouy_y = y;
	bouyGraphic = al_load_bitmap("Assets/bouy.png");
	int graphicWidth = al_get_bitmap_width(bouyGraphic);
	int graphicHeight = al_get_bitmap_height(bouyGraphic);
	ALLEGRO_BITMAP* firstAnimation = al_create_sub_bitmap(bouyGraphic, 0, 0, (graphicWidth / 2), (graphicHeight / 2));
	ALLEGRO_BITMAP* secondAnimation = al_create_sub_bitmap(bouyGraphic, (graphicWidth / 2), 0, (graphicWidth / 2), (graphicHeight / 2));
	ALLEGRO_BITMAP* thirdAnimation = al_create_sub_bitmap(bouyGraphic, 0, (graphicWidth / 2), (graphicWidth / 2), (graphicHeight / 2));
	ALLEGRO_BITMAP* fourthAnimation = al_create_sub_bitmap(bouyGraphic, (graphicWidth / 2), 0, (graphicWidth / 2), (graphicHeight / 2));
	bouyVector.push_back(firstAnimation);
	bouyVector.push_back(secondAnimation);
	bouyVector.push_back(thirdAnimation);
	bouyVector.push_back(fourthAnimation);
}

void Bouy::add_crab(int crab)
{
	crabCount += crab;
}

void Bouy::draw() {
	//Updating logic and draw in the draw method. At the moment there's no reason to decouple it.
	updateCounter++;
	if (imageCounter >= 3)
		imageCounter = 0;

	if (updateCounter % playSpeed == 0) {
		imageCounter += 1;
	}

	al_draw_bitmap(bouyVector[imageCounter], bouy_x, bouy_y, 0);
}

Bouy::~Bouy()
{
	for (ALLEGRO_BITMAP* x : bouyVector) {
		al_destroy_bitmap(x);
	}
	al_destroy_bitmap(bouyGraphic);
}
