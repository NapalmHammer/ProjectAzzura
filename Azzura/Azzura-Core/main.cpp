// Personal game/animation project

#include "sprite.h"
#include "window.h"
#include <time.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	using namespace azzure;
	srand(time(NULL));

	//Globals
	const float FPS = 60.0;

	int SCREEN_W = 1600;
	int SCREEN_H = 900;
	int curFrame = 0;
	int frameDelay = 6;
	int frameCount = 0;

	bool key[4] = { false, false, false, false };
	bool redraw = true;
	bool doexit = false;
	bool playingSound = false;

	//Allegro Variables
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_SAMPLE *sample = NULL;

	//Allegro inits
	al_init();
	al_init_image_addon();
	al_init_acodec_addon();
	al_init_primitives_addon();
	al_init_image_addon();

	//Object varriables
	Window window(SCREEN_W, SCREEN_H);
	Sprite megaman("../dependencies/bmp/megaman-mod.png", window.m_ScreenWidth, window.m_ScreenHeight);

	//Allegro installs
	al_install_keyboard();
	al_install_audio();

	al_reserve_samples(1);
	
	timer = al_create_timer(1.0 / FPS);
	event_queue = al_create_event_queue();
	sample = al_load_sample("../Dependencies/sound/internettheme.ogg");

	//Register event sources
	al_register_event_source(event_queue, al_get_display_event_source(window.m_Display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);

	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				key[megaman.KEY_UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				key[megaman.KEY_DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				key[megaman.KEY_LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[megaman.KEY_RIGHT] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				key[megaman.KEY_UP] = false;
				curFrame = 0;
				break;
			case ALLEGRO_KEY_DOWN:
				key[megaman.KEY_DOWN] = false;
				curFrame = 0;
				break;
			case ALLEGRO_KEY_LEFT:
				key[megaman.KEY_LEFT] = false;
				curFrame = 0;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[megaman.KEY_RIGHT] = false;
				curFrame = 0;
				break;
			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue))
		{
			al_clear_to_color(al_map_rgb(0, 0, 0));

			Tile::drawGrid(((float)(SCREEN_W / 2) + 0.5f), SCREEN_H / 6 + 0.5f, 15, 15, 5.6f);
			megaman.UpdateSprite(key, curFrame);

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

	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);

	return 0;
}