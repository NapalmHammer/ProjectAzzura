// Personal game/animation project

#include "window.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>

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

	bool key[4] = { false, false, false, false };
	bool redraw = true;
	bool doexit = false;
	bool playingSound = false;

	//Allegro init
	al_init();

	//Display object initialized with event queue, timer, and FPS.
	Window window(SCREEN_W, SCREEN_H, 60.0f);
	//Install/Init items
	window.installs();
	//Register event sources
	window.registerEventSources();

	//Creating Keyboard ogject
	Keyboard keyboard;
	//Creating the camera
	Vec2 camXY(0, 0);
	Camera camera(camXY);

	//Sound clip stuff to be sorted out
	ALLEGRO_SAMPLE *sample = NULL;
	al_reserve_samples(1);
	sample = al_load_sample("../Dependencies/sound/internettheme.ogg");

	Level level;

	//Main character place-holder sprite class
	Sprite megaman("../dependencies/bmp/megaman-mod.png", 25, 25, level);


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

		if (redraw && al_is_event_queue_empty(window.m_EventQueue))
		{
			al_clear_to_color(al_map_rgb(0, 0, 0));


			
			//Tile::drawGrid(camera.m_CamX, camera.m_CamY, 10, 10, 0.0f, SCREEN_W, SCREEN_H);
			level.drawLevel(camera.m_CamX, camera.m_CamY, 0.0, SCREEN_W, SCREEN_H);
			
			megaman.UpdateSprite(key, curFrame, camera, keyboard, SCREEN_W, SCREEN_H, level);
			

			if (!playingSound)
			{
				al_play_sample(sample, 0.1, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
				playingSound = true;
			}

			if (++frameCount >= frameDelay)
			{
				curFrame++;
				if (curFrame >= 5)
					curFrame = 0;

				frameCount = 0;
			}

			redraw = false;
			al_flip_display();
		}
	}

	return 0;
}