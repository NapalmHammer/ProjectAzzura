#include "game.h"

namespace azzure
{	

	void Game::mainMenu(ALLEGRO_FONT *font, int mousex, int mousey, float &screenW, float &screenH, Mouse &mouse, int &gameState, bool &ld)
	{		
		int r = 0, g = 0, b = 0;

		if (mousex >= screenW * 0.39 && mousex <= screenW * 0.61 && mousey >= screenH * 0.45 && mousey <= screenH * 0.55)
		{
				r = 100, g = 100, b = 100;

				al_get_mouse_state(&mouse.state);
				if (mouse.state.buttons & 1)
				{
					ld = true;
				}	

				else if (ld && !al_mouse_button_down(&mouse.state, 1))
				{
					ld = false;
					gameState = 1;
				}

		}


		al_draw_filled_rectangle(screenW / 50, screenH / 50, screenW - screenW / 50, screenH - screenH / 50, al_map_rgb(35, 100, 250));
		al_draw_rectangle(screenW / 50, screenH / 50, screenW - screenW / 50, screenH - screenH / 50, al_map_rgb(100, 100, 230), 8);
		al_draw_filled_rectangle(screenW * 0.39, screenH * 0.45, screenW * 0.61, screenH * 0.55, al_map_rgb(100 + r, 100 + g, 100 + b));
		al_draw_rectangle(screenW * 0.39, screenH * 0.45, screenW * 0.61, screenH * 0.55, al_map_rgb(230,230,30), 4);
		al_draw_text(font, al_map_rgb(250, 100, 100), screenW / 2, screenH * 0.47, ALLEGRO_ALIGN_CENTRE, "START GAME");
	}
}