#pragma once
#include "allegro5\allegro.h"

namespace azzure
{
	class Mouse
	{


	public:
		Mouse(void);
		~Mouse(void);
		ALLEGRO_MOUSE_STATE state;
		bool poll(ALLEGRO_EVENT ev);
		bool button_down(int button);
		bool button_pressed(int button);
	private:
		bool* buttons_down;
		bool* buttons_pressed;
	};
}