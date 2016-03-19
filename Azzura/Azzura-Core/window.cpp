#include "window.h"



namespace azzure
{
	Window::Window(int screenWidth, int screenHeight)
	{
		m_ScreenHeight = screenHeight;
		m_ScreenWidth = screenWidth;
		m_Display = al_create_display(m_ScreenWidth, m_ScreenHeight);
	}

	Window::~Window()
	{
		al_destroy_display(m_Display);
	}
}