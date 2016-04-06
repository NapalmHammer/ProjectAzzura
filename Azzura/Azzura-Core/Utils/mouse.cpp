#include "mouse.h"

namespace azzure
{
	const int MAX_MOUSE_BUTTONS = 8;
	Mouse::Mouse(void)
	{
		if (!al_is_mouse_installed()) {
			al_install_mouse();
		}
		buttons_down = new bool[MAX_MOUSE_BUTTONS];
		buttons_pressed = new bool[MAX_MOUSE_BUTTONS];
		for (int x = 0; x < MAX_MOUSE_BUTTONS; x++) {
			buttons_down[x] = buttons_pressed[x] = false;
		}
	}


	Mouse::~Mouse(void)
	{
		delete[] buttons_down;
		delete[] buttons_pressed;
	}

	bool Mouse::poll(ALLEGRO_EVENT ev)
	{
		{
			switch (ev.type)
			{
			case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
				buttons_pressed[ev.mouse.button] = buttons_down[ev.mouse.button] = true;
				break;
			case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
				buttons_pressed[ev.mouse.button] = buttons_down[ev.mouse.button] = false;
				break;
			}
			return true;
		}
	}

	/**
	*Check if a key is down.
	*@return Whether the key is down.
	**/
	bool Mouse::button_down(int button) {
		if (button >= MAX_MOUSE_BUTTONS || button < 0) {
			return false;
		}
		else
		{
			return buttons_down[button];
		}
	}

	/**
	*Check whether a key is pressed.
	*Note that a key that was returned as pressed will not be returned as pressed until it is released and pressed again.
	*@return whether the key was pressed.
	**/
	bool Mouse::button_pressed(int button) {
		if (button >= MAX_MOUSE_BUTTONS || button < 0) {
			return false;
		}
		else
		{

			bool val = buttons_pressed[button];
			buttons_pressed[button] = false;
			return val;
		}
	}
}