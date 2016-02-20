#include <iostream>
#include "allegro5\allegro5.h"
#include "allegro5\allegro_image.h"
#include "allegro5\allegro_primitives.h"

int main(int argc, char** argv)
{

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	//ALLEGRO_DISPLAY_MODE disp_data;

	if(!al_init())	{		std::cerr << "Allegro failed to initialize!" << std::endl;
		return 0;
	}

	/*if (!al_init_image_addon())	{		std::cerr << "Allegro Image Addon failed to initialize!" << std::endl;
		return 0;
	}

	if (!al_init_primitives_addon())	{		std::cerr << "Allegro Primitives Addon failed to initialize!" << std::endl;
		return 0;
	}

	al_get_display_mode(al_get_num_display_modes() - 1, &disp_data);

	al_set_new_display_flags(ALLEGRO_FULLSCREEN);

	display = al_create_display(disp_data.width, disp_data.height);*/

	display = al_create_display(640, 480);

	if (!display)
	{
		std::cerr << "Display failed!" << std::endl;
		return 0;
	}

	event_queue = al_create_event_queue();

	if (!event_queue)
	{
		std::cerr << "event Queue failed!" << std::endl;
		al_destroy_display(display);
		return 0;
	}

	al_set_app_name("Azzura!");

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	while (1)
	{
		ALLEGRO_EVENT ev;
		ALLEGRO_TIMEOUT timeout;
		al_init_timeout(&timeout, 0.06);

		bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);

		if (get_event && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			break;
		}

		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_flip_display();
	}

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}