// Personal game/animation project

#include "Game/window.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "Game/game.h"
#include "Utils/mouse.h"
#include "Graphics\map.h"

int main(int argc, char** argv)
{	
	//Using the azzure namespace - kind of confused with how namespaces work still
	using namespace azzure;
	//Seeding the rand() generator
	srand(time(NULL));

	//Globals
	float SCREEN_W = 1600.0f;
	float SCREEN_H = 900.0f;
	int curFrame = 0;
	int frameDelay = 6;
	int frameCount = 0;
	int mouseX = 0;
	int mouseY = 0;
	//int xoff = 0, yoff = 0;


	int gameState = 1;

	bool redraw = true;
	bool doexit = false;
	bool left_down = false;

	enum GameStates
	{
		MAIN_MENU,
		PLAYING_GAME
	};


	//Allegro init
	al_init();

	//Display object initialized with event queue, timer, and FPS.
	Window window(SCREEN_W, SCREEN_H, 60.0f);
	//Install/Init items
	window.installs();
	//Register event sources
	window.registerEventSources();

	//loading the font to be used
	ALLEGRO_FONT *font = NULL;
	font = al_load_ttf_font("../Dependencies/fonts/slkscr.ttf", 48, 0);

	//Creating Keyboard & Mouse objects
	Keyboard keyboard;
	Mouse mouse;

	//Creating the camera
	Vec2 camXY(0, 0);
	Camera camera(camXY);

	//Creating tile sets and level
	Tile tile("../Dependencies/bmp/testTile.bmp", 100, 50);
	Tile tileTwo("../Dependencies/bmp/testTile2.bmp", 100, 55);

	Level level("../Dependencies/maps/homepage.txt");

	//Main character place-holder sprite class
	Sprite megaman("../dependencies/bmp/megaman-mod.png", 25, 25, level);
	Sprite YMD("../Dependencies/bmp/YMDtest2.bmp", 32, 64, 10, 10, 2, level);


	//Started the timer. Not good to put anything past here except in the primary game loop
	al_start_timer(window.m_Timer);

	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(window.m_EventQueue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN || ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			keyboard.poll(ev);
			std::cout << ev.keyboard.keycode << std::endl;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			mouseX = ev.mouse.x;
			mouseY = ev.mouse.y;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN || ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			mouse.poll(ev);
		}

		if (redraw && al_is_event_queue_empty(window.m_EventQueue))
		{
			al_clear_to_color(al_map_rgb(0, 0, 0));


			if (gameState == MAIN_MENU)
			{
				Game::mainMenu(font, mouseX, mouseY, SCREEN_W, SCREEN_H, mouse, gameState, left_down);
			}

			else if (gameState == PLAYING_GAME)
			{
				level.drawLevel(camera.m_CamX, camera.m_CamY, 3.0, SCREEN_W, SCREEN_H, tileTwo);
				YMD.UpdateSprite(camera, keyboard, level, SCREEN_W, SCREEN_H);
				megaman.UpdateSprite(curFrame, camera, keyboard, SCREEN_W, SCREEN_H, level);

				//if (keyboard.key_down(82))
				//	xoff -= 1;
				//	//camera.m_CamX -= 1;
				//if (keyboard.key_down(83))
				//	xoff += 1;
				//	//camera.m_CamX += 1;
				//if (keyboard.key_down(84))
				//	yoff -= 1;
				//	//camera.m_CamY -= 1;
				//if (keyboard.key_down(85))
				//	yoff += 1;
				//	//camera.m_CamY += 1;

				//std::cout << "Xoff : " << xoff << " Yoff : " << yoff << std::endl;

				if (++frameCount >= frameDelay)
				{
					curFrame++;
					if (curFrame >= 5)
						curFrame = 0;

					frameCount = 0;
				}
			}

			redraw = false;
			al_flip_display();
		}
	}

	return 0;
}