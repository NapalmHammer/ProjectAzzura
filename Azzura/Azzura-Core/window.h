#include "sprite.h"



namespace azzure 
{
	class Window
	{
	public:
		const float m_FPS;
		ALLEGRO_EVENT_QUEUE *m_EventQueue;
		ALLEGRO_DISPLAY *m_Display;
		ALLEGRO_TIMER *m_Timer;
		int m_ScreenWidth;
		int m_ScreenHeight;

		Window(int screenWidth, int screenHeight, float FPS);
		~Window();
		void registerEventSources();
		void installs();
	};
}