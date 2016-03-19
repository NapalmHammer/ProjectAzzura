#pragma once

#include <iostream>
#include "allegro5/allegro5.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5\allegro_image.h"
#include "tile.h"
#include <time.h>
#include <stdlib.h>

namespace azzure {

	class Sprite
	{
	public:
		Sprite(const char *filePath, int SCREEN_W, int SCREEN_H);
		~Sprite();

		ALLEGRO_BITMAP *m_Sprite;
		const char *m_FilePath;
		float m_x;
		float m_y;
		int maxFrame;
		int frameCount;
		int frameDelay;
		int frameWidth;
		int frameHeight;
		int animationColumns;
		int animationDirection;
		int curDirection;

		enum MYKEYS
		{
			KEY_UP,
			KEY_DOWN,
			KEY_LEFT,
			KEY_RIGHT
		};

		void UpdateSprite(bool key[], int curFrame);

	private:
	};
}