#include "window.h"



namespace azzure
{
	Window::Window(int screenWidth, int screenHeight, float FPS)
		:m_FPS(FPS)
	{
		m_ScreenHeight = screenHeight;
		m_ScreenWidth = screenWidth;
		m_Display = al_create_display(m_ScreenWidth, m_ScreenHeight);
		m_EventQueue = al_create_event_queue();
		m_Timer = al_create_timer(1.0 / m_FPS);
	}

	Window::~Window()
	{
		al_destroy_display(m_Display);
		al_destroy_event_queue(m_EventQueue);
		al_destroy_timer(m_Timer);
	}

	void Window::registerEventSources()
	{
		al_register_event_source(m_EventQueue, al_get_display_event_source(m_Display));
		al_register_event_source(m_EventQueue, al_get_timer_event_source(m_Timer));
		al_register_event_source(m_EventQueue, al_get_keyboard_event_source());
	}

	void Window::installs()
	{
		al_init_image_addon();
		al_init_acodec_addon();
		al_init_primitives_addon();
		al_init_image_addon();

		al_install_keyboard();
		al_install_audio();
	}
}