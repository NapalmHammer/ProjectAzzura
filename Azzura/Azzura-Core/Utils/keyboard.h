#pragma once
#include "allegro5\allegro.h"

namespace azzure
{
	class Keyboard
	{

	public:
		Keyboard(void);
		~Keyboard(void);
		bool poll(ALLEGRO_EVENT ev);
		bool key_down(int key);
		bool key_pressed(int key);
	private:
		bool* keys_down;
		bool* keys_pressed;
	};
}