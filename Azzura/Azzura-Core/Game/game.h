#pragma once
#include "allegro5\allegro5.h"
#include "allegro5\allegro_font.h"
#include "allegro5\allegro_primitives.h"
#include "allegro5\allegro_ttf.h"
#include <iostream>
#include "../Utils/mouse.h"

namespace azzure
{	
	class Game
	{
	public:
		static int gameState;
		static void mainMenu(ALLEGRO_FONT *font, int mousex, int mousey, float &screenW, float &screenH, Mouse &mouse, int &gameState, bool &ld);
	};
}