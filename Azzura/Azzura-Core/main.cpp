// Mouse system

/*#include <iostream>
#include "allegro5\allegro5.h"

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;

int main(int argc, char** argv)
{

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;

	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
	bool redraw = true;

	if(!al_init())	
	{
		std::cerr << "Allegro failed to initialize!" << std::endl;
		return -1;
	}

	if (!al_install_mouse())
	{
		std::cerr << "Mouse failed to initialize!" << std::endl;
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer)
	{
		std::cerr << "Failed to create timer!" << std::endl;
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display)
	{
		std::cerr << "Display failed!" << std::endl;
		al_destroy_timer(timer);
		return -1;
	}

	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
	if (!bouncer)
	{
		std::cout << "Bouncer failed?" << std::endl;
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_set_target_bitmap(bouncer);
	al_clear_to_color(al_map_rgb(255, 0, 255));
	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();
	if (!event_queue)
	{
		std::cerr << "event Queue failed!" << std::endl;
		al_destroy_bitmap(bouncer);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	int r = 255;
	int g = 255;
	int b = 255;

	while (1)
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
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY)
		{
			bouncer_x = ev.mouse.x;
			bouncer_y = ev.mouse.y;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;
			al_clear_to_color(al_map_rgb(r, g, b));
			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
			al_flip_display();
		}
	}

	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}*/

//Keyboard system

/*#include <iostream>
#include "allegro5\allegro5.h"

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;

enum MYKEYS
{
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT
};

int main(int argc, char** argv)
{

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;

	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;

	bool key[4] = { false, false, false, false };
	bool redraw = true;
	bool doexit = false;

	if (!al_init())
	{
		std::cerr << "Allegro failed to initialize!" << std::endl;
		return -1;
	}

	if (!al_install_keyboard())
	{
		std::cerr << "Keyboard failed to initialize!" << std::endl;
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer)
	{
		std::cerr << "Failed to create timer!" << std::endl;
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display)
	{
		std::cerr << "Display failed!" << std::endl;
		al_destroy_timer(timer);
		return -1;
	}

	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
	if (!bouncer)
	{
		std::cout << "Bouncer failed?" << std::endl;
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_set_target_bitmap(bouncer);
	al_clear_to_color(al_map_rgb(255, 0, 255));
	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();
	if (!event_queue)
	{
		std::cerr << "Event Queue failed!" << std::endl;
		al_destroy_bitmap(bouncer);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	int r = 255;
	int g = 255;
	int b = 255;

	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			if (key[KEY_UP] && bouncer_y >= 4.0)
			{
				bouncer_y -= 4.0;
			}
			if (key[KEY_DOWN] && bouncer_y <= SCREEN_H - BOUNCER_SIZE - 4.0)
			{
				bouncer_y += 4.0;
			}
			if (key[KEY_LEFT] && bouncer_x >= 4.0)
			{
				bouncer_x -= 4.0;
			}
			if (key[KEY_RIGHT] && bouncer_x <= SCREEN_W - BOUNCER_SIZE - 4.0)
			{
				bouncer_x += 4.0;
			}

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
				key[KEY_UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;
			al_clear_to_color(al_map_rgb(r, g, b));
			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
			al_flip_display();
		}
	}

	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}*/

// Bitmap system

/*#include <iostream>
#include "allegro5\allegro.h"
#include "allegro5\allegro_image.h"
#include "allegro5\allegro_native_dialog.h"

int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *image = NULL;

	if (!al_init())
	{
		al_show_native_message_box(display, "Error", "Error", "Failed to init allegro!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	if (!al_init_image_addon())
	{
		al_show_native_message_box(display, "Error", "Error", "Failed to init Image Addon!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	display = al_create_display(800, 600);

	if (!display)
	{
		al_show_native_message_box(display, "Error", "Error", "Failed to init Display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	image = al_load_bitmap("../Dependencies/bmp/tank.bmp");
	
	if (!image)
	{
		al_show_native_message_box(display, "Error", "Error", "Failed to load Image!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}

	al_draw_bitmap(image, 100, 100, 0);

	image = al_load_bitmap("../Dependencies/bmp/tiger.png");

	if (!image)
	{
		al_show_native_message_box(display, "Error", "Error", "Failed to load Image!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}

	al_draw_bitmap(image, 350, 350, 0);

	al_flip_display();
	al_rest(5);

	al_destroy_display(display);
	al_destroy_bitmap(image);

	return 0;
}*/

// Threading tutorial: Quite complicated

/*#include <iostream>
#include "allegro5\allegro5.h"

class DATA
{

public:
	ALLEGRO_MUTEX *mutex;
	ALLEGRO_COND *cond;
	float posiX;
	float posiY;
	bool modi_X;
	bool ready;

	DATA() : mutex(al_create_mutex()), cond(al_create_cond()), posiX(0), posiY(0), modi_X(false), ready(false)
	{

	}

	~DATA()
	{
		al_destroy_mutex(mutex);
		al_destroy_cond(cond);
	}


};

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;
const int r = 255;
const int g = 255;
const int b = 255;

static void *Func_Thread(ALLEGRO_THREAD *thr, void *arg);

int main(int argc, char** argv)
{

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_THREAD *thread_1 = NULL;
	ALLEGRO_THREAD *thread_2 = NULL;

	bool redraw = true;

	if (!al_init())
	{
		std::cerr << "Allegro failed to initialize!" << std::endl;
		return -1;
	}

	if (!al_install_mouse())
	{
		std::cerr << "Mouse failed to initialize!" << std::endl;
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer)
	{
		std::cerr << "Failed to create timer!" << std::endl;
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display)
	{
		std::cerr << "Display failed!" << std::endl;
		al_destroy_timer(timer);
		return -1;
	}

	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
	if (!bouncer)
	{
		std::cout << "Bouncer failed?" << std::endl;
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_set_target_bitmap(bouncer);
	al_clear_to_color(al_map_rgb(255, 0, 255));
	al_set_target_bitmap(al_get_backbuffer(display));
	event_queue = al_create_event_queue();

	if (!event_queue)
	{
		std::cerr << "event Queue failed!" << std::endl;
		al_destroy_bitmap(bouncer);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	DATA data;

	thread_1 = al_create_thread(Func_Thread, &data);
	al_start_thread(thread_1);

	al_lock_mutex(data.mutex);
	while (!data.ready)
	{
		al_wait_cond(data.cond, data.mutex);
	}
	al_unlock_mutex(data.mutex);

	al_lock_mutex(data.mutex);
	data.modi_X = true;
	data.ready = false;
	al_unlock_mutex(data.mutex);

	thread_2 = al_create_thread(Func_Thread, &data);
	al_start_thread(thread_2);

	al_lock_mutex(data.mutex);
	while (!data.ready)
	{
		al_wait_cond(data.cond, data.mutex);
	}
	al_unlock_mutex(data.mutex);

	while (1)
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
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;

			al_lock_mutex(data.mutex);
			float X = data.posiX;
			float Y = data.posiY;
			al_unlock_mutex(data.mutex);

			al_draw_bitmap(bouncer, X, Y, 0);

			al_flip_display();
		}
	}
	al_destroy_thread(thread_1);
	al_destroy_thread(thread_2);

	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}

static void *Func_Thread(ALLEGRO_THREAD *thr, void *arg)
{
	DATA *data = (DATA*)arg;
	float num = 0.1;

	al_lock_mutex(data->mutex);

	bool modi_X = data->modi_X;
	data->ready = true;
	al_broadcast_cond(data->cond);

	al_unlock_mutex(data->mutex);

	while (!al_get_thread_should_stop(thr))
	{
		al_lock_mutex(data->mutex);
		if (modi_X)
			data->posiX += num;
		else
			data->posiY += num;
		al_unlock_mutex(data->mutex);

		al_rest(0.01);
	}

	return NULL;
}*/

// Addon/Fonts tutorial

/*#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

int main(int argc, char **argv)
{
	if (!al_init())
	{
		std::cerr << "Failed to initialize Allegro!" << std::endl;
		return -1;
	}

	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_DISPLAY *display = al_create_display(640, 480);

	if (!display)
	{
		std::cerr << "Failed to create display!" << std::endl;
		return -1;
	}

	ALLEGRO_FONT *font = al_load_ttf_font("../dependencies/fonts/pirulen.ttf", 36, 0);

	if (!font)
	{
		std::cerr << "Failed to load 'pirulen.ttf'." << std::endl;
	system("PAUSE");
		return -1;
	}

	al_clear_to_color(al_map_rgb(50, 10, 70));
	al_draw_text(font, al_map_rgb(255, 255, 255), 640 / 2, (480 / 4), ALLEGRO_ALIGN_CENTRE, "My Text!");

	al_flip_display();

	al_rest(10.0);

	al_destroy_display(display);

	return 0;
}*/

// Addon/audio tutorial

/*#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

int main(int argc, char **argv)
{

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_SAMPLE *sample = NULL;

	if (!al_init())
	{
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	if (!al_install_audio())
	{
		std::cerr << "Bad audio init" << std::endl;
		return -1;
	}
	if (!al_init_acodec_addon())
	{
		std::cerr << "bad codec addon" << std::endl;
		return -1;
	}
	if (!al_reserve_samples(1))
	{
		std::cerr << "bad sample reserve" << std::endl;
		return -1;
	}

	sample = al_load_sample("../Dependencies/sound/footsteps-1.wav");

	if (!sample)
	{
		std::cerr << "sample clip bad" << std::endl;
		return -1;
	}

	display = al_create_display(640, 480);

	if (!display)
	{
		std::cerr << "Bad display" << std::endl;
		return -1;
	}

	al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

	al_rest(10.0);

	al_destroy_display(display);
	al_destroy_sample(sample);

	return 0;

}*/

#include <iostream>
#include "allegro5\allegro5.h"
#include "allegro5\allegro_image.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>


const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;

enum MYKEYS
{
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT
};

void updateCharacter(ALLEGRO_BITMAP *character, bool key[], int curFrame, int imageWidth, int imageHeight, float X, float Y, int &curDirection);

	int r = 100;
	int g = 100;
	int b = 100;
	int image_width = 20;
	int image_height = 40;
	int curFrame = 0;
	int frameDelay = 6;
	int frameCount = 0;
	int curDirection = 1;

int main(int argc, char** argv)
{

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *character;
	ALLEGRO_SAMPLE *sample = NULL;



	float posX = SCREEN_W / 2.0 - image_width / 2.0;
	float posY = SCREEN_H / 2.0 - image_height / 2.0;

	bool key[4] = { false, false, false, false };
	bool redraw = true;
	bool doexit = false;
	bool playingSound = false;

	al_init();
	al_install_keyboard();
	al_init_image_addon();
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(1);
	
	timer = al_create_timer(1.0 / FPS);
	display = al_create_display(SCREEN_W, SCREEN_H);
	event_queue = al_create_event_queue();
	sample = al_load_sample("../Dependencies/sound/internettheme.ogg");

	character = al_load_bitmap("../dependencies/bmp/megaman-mod.png");
	al_convert_mask_to_alpha(character, al_map_rgb(0, 128, 128));
	
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);

	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			if (key[KEY_UP] && posY >= image_height)
			{
				posY -= 2.0;
			}
			if (key[KEY_DOWN] && posY <= SCREEN_H - BOUNCER_SIZE - 4.0)
			{
				posY += 2.0;
			}
			if (key[KEY_LEFT] && posX >= 4.0)
			{
				posX -= 2.0;
			}
			if (key[KEY_RIGHT] && posX <= SCREEN_W - BOUNCER_SIZE - 4.0)
			{
				posX += 2.0;
			}

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
				key[KEY_UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				curFrame = 0;
				break;
			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				curFrame = 0;
				break;
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				curFrame = 0;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				curFrame = 0;
				break;
			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue))
		{
				al_clear_to_color(al_map_rgb(r, g, b));

				updateCharacter(character, key, curFrame, image_width, image_height, posX, posY, curDirection);

				if (!playingSound)
				{
					al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
					playingSound = true;
				}

			if (++frameCount >= frameDelay)
			{
				curFrame++;
				if (curFrame > 5)
					curFrame = 0;

				frameCount = 0;
			}
			redraw = false;
			al_flip_display();
		}
	}

	al_destroy_bitmap(character);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}

void updateCharacter(ALLEGRO_BITMAP *character, bool key[], int curFrame, int imageWidth, int imageHeight, float X, float Y, int &curDirection)
{
	if (key[KEY_UP])
	{
		if (key[KEY_UP] && key[KEY_LEFT])
		{
			al_draw_bitmap_region(character, curFrame * 26 + 22, 259, 26, 42, X, Y, 0);
			curDirection = 259;
			return;
		}
		else if (key[KEY_UP] && key[KEY_RIGHT])
		{
			al_draw_bitmap_region(character, curFrame * 26 + 22, 302, 26, 42, X, Y, 0);
			curDirection = 302;
			return;
		}
		al_draw_bitmap_region(character, curFrame * 20 + 22, 44, 20, 42, X, Y, 0);
		curDirection = 44;
		return;
	}

	else if (key[KEY_DOWN])
	{

		if (key[KEY_DOWN] && key[KEY_LEFT])
		{
			al_draw_bitmap_region(character, curFrame * 27 + 22, 175, 27, 40, X, Y, 0);
			curDirection = 173;
			return;
		}
		else if (key[KEY_DOWN] && key[KEY_RIGHT])
		{
			al_draw_bitmap_region(character, curFrame * 27 + 22, 218, 27, 40, X, Y, 0);
			curDirection = 216;
			return;
		}
		al_draw_bitmap_region(character, curFrame * 21 + 22, 3, 21, 40, X, Y, 0);
		curDirection = 1;
		return;
	}

	else if (key[KEY_LEFT])
	{
		al_draw_bitmap_region(character, curFrame * 29 + 22, 88, 29, 41, X, Y, 0);
		curDirection = 87;
		return;
	}

	else if (key[KEY_RIGHT])
	{
		al_draw_bitmap_region(character, curFrame * 29 + 22, 131, 29, 41, X, Y, 0);
		curDirection = 130;
		return;
	}

	else 
	{
		al_draw_bitmap_region(character, 1, curDirection, 20, 42, X, Y, 0);
		return;
	}
}