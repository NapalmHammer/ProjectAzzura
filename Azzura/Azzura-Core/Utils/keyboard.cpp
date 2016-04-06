#include "keyboard.h"

namespace azzure
{
	Keyboard::Keyboard(void)
	{
		if (!al_is_keyboard_installed()) {
			al_install_keyboard();
		}
		keys_down = new bool[ALLEGRO_KEY_MAX];
		keys_pressed = new bool[ALLEGRO_KEY_MAX];
		for (int x = 0; x < ALLEGRO_KEY_MAX; x++) {
			keys_down[x] = keys_pressed[x] = false;
		}
	}


	Keyboard::~Keyboard(void)
	{
		delete[] keys_down;
		delete[] keys_pressed;
	}

	bool Keyboard::poll(ALLEGRO_EVENT ev) 
	{
		{
			switch (ev.type) 
			{
			case ALLEGRO_EVENT_KEY_DOWN:
				keys_pressed[ev.keyboard.keycode] = keys_down[ev.keyboard.keycode] = true;
				break;
			case ALLEGRO_EVENT_KEY_UP:
				keys_pressed[ev.keyboard.keycode] = keys_down[ev.keyboard.keycode] = false;
				break;
			}
			return true;
		}
	}

	/**
	*Check if a key is down.
	*@return Whether the key is down.
	**/
	bool Keyboard::key_down(int key) {
		if (key >= ALLEGRO_KEY_MAX || key < 0) {
			return false;
		}
		else 
		{
			return keys_down[key];
		}
	}

	/**
	*Check whether a key is pressed.
	*Note that a key that was returned as pressed will not be returned as pressed until it is released and pressed again.
	*@return whether the key was pressed.
	**/
	bool Keyboard::key_pressed(int key) {
		if (key >= ALLEGRO_KEY_MAX || key < 0) {
			return false;
		}
		else 
		{
			
			bool val = keys_pressed[key];
			keys_pressed[key] = false;
			return val;
		}
	}
}