#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include<allegro5/allegro_image.h>
#include<allegro5/fixed.h>
#include<cmath>
#include<iostream>
#include"Bouy.h"
#include "PlayerShip.h"

PlayerShip::PlayerShip(int x, int y)
{
	this->load_assets();
	this->ship_x = x;
	this->ship_y = y;
	this->ship_x_center = al_get_bitmap_width(boatGraphic) / 2;
	this->ship_y_center = al_get_bitmap_height(boatGraphic) / 2;
	//this->shipBouys.push_back(new Bouy(ship_x + 1, ship_y));
}

ALLEGRO_BITMAP* PlayerShip::get_boat_graphic()
{
	return boatGraphic;
}

void PlayerShip::load_assets()
{
	this->boatGraphic = al_load_bitmap("Assets/boat.png");
}

void PlayerShip::unload_assets()
{
	al_destroy_bitmap(this->boatGraphic);
	//offload bouy assets. need to write that into bouys.
}

void PlayerShip::handle_input(ALLEGRO_EVENT& e)
{
	if (e.keyboard.keycode == ALLEGRO_KEY_SPACE) {
		if (canLaunchBouy == true && shipBouys.size() < maxBouys) {
			Bouy* myBouy = new Bouy(ship_x + 15, ship_y);
			shipBouys.push_back(myBouy);
			canLaunchBouy = false;
			bouyTimer = 0;
		}
	}
	if (e.keyboard.keycode == ALLEGRO_KEY_UP ) {
		player_velocity += 0.13f;
		if (player_velocity > max_velocity) {
			player_velocity = player_velocity;
		}
	}
	if (e.keyboard.keycode == ALLEGRO_KEY_LEFT) {
		player_angle -= 10.0f;
		if (player_angle <= 0.0f)
			player_angle = 360.0f;
	}
	if (e.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
		player_angle += 10.0f;
		if (player_angle >= 360.0f)
			player_angle = 0.0f;
			
	}
	if (e.keyboard.keycode == ALLEGRO_KEY_DOWN ){
		player_velocity -= .1;
		if ( player_velocity < 0.0f ) {
			player_velocity = 0.0f;
		}
	}
}

void PlayerShip::update()
{
	//count how many frames we've had.
	bouyTimer += 1; //called once per frame.

	if (bouyTimer >= bouyLaunchTime && canLaunchBouy == false) {
		canLaunchBouy = true;
		bouyTimer = 0;
	}
	float playerAngleInRad = (player_angle * 3.14159 / 180);
	ship_x_velocity =  player_velocity * sin(playerAngleInRad);
	ship_y_velocity = player_velocity * cos(playerAngleInRad);
	ship_x += ship_x_velocity;
	ship_y -= ship_y_velocity;
}

void PlayerShip::draw()
{
	if (!shipBouys.empty()) {
		for (Bouy* x : shipBouys) {
			x->draw();
		}
	}
	//Drawing rotated bitmap, from center of ship, putting it at ship_x, and ship_y, get radians float*pi/180, no flags.
	al_draw_rotated_bitmap(boatGraphic, ship_x_center, ship_y_center, ship_x, ship_y, (player_angle * 3.14159 / 180), 0);
}

float PlayerShip::get_ship_x()
{
	return ship_x;
}

float PlayerShip::get_ship_y()
{
	return ship_y;
}

int PlayerShip::get_ship_velocity_x()
{
	return ship_x_velocity;
}

int PlayerShip::get_ship_velocity_y()
{
	return ship_y_velocity;
}

void PlayerShip::add_velocity(int x, int y)
{
	this->ship_x_velocity += x;
	this->ship_y_velocity += y;
}

void PlayerShip::upgrade_ship_velocity(int amount)
{
	max_velocity += amount;
}
