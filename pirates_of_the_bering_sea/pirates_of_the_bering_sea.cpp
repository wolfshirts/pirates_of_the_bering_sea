// pirates_of_the_bering_sea.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include<allegro5/allegro_image.h>

#include "SceneManager.h"

int main()
{
	al_init(); //init allegro and allegro extras.
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();
	
	//Init display
	ALLEGRO_DISPLAY* display = al_create_display(800, 600);
	
	//Get the keyboard running
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	al_install_keyboard();
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));

	//Set up the timer
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_start_timer(timer);

	SceneManager sceneManager = SceneManager(display); //init our scenemanager with a pointer to our display.
	bool gameOver = false;
	
	while (!gameOver) {
		ALLEGRO_EVENT event; //get event
		
		//Handle the events here, if there are no events continue running.
		//if (!al_is_event_queue_empty(queue)) {
			al_wait_for_event(queue, &event);
			if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				gameOver = true;
			}
			else if (event.type == ALLEGRO_EVENT_TIMER) {
				sceneManager.game_logic();
				sceneManager.draw();
			}
			else //(event.type == ALLEGRO_KEY_LEFT) 
			{
				//Send the keydown to the scenemanager
				sceneManager.handle_input(event);
			}
		//}
		//sceneManager.handle_input();
		//sceneManager.game_logic();
		//sceneManager.draw();
		al_flip_display(); //flip display makes buffer visible to user.
	}
	
	//kill the game. May need additional clean up.
	al_destroy_display(display);
	al_uninstall_keyboard();
	al_destroy_timer(timer);
	return 0;
}