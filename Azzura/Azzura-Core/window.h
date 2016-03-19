#include "sprite.h"



namespace azzure 
{
	class Window
	{
	public:
		ALLEGRO_DISPLAY *m_Display;
		int m_ScreenWidth;
		int m_ScreenHeight;

		Window(int screenWidth, int screenHeight);
		~Window();
	};
}