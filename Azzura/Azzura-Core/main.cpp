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
	//float bouncer_dx = -4.0, bouncer_dy = 4.0;
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