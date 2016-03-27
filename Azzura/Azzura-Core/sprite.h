#pragma once

#include <iostream>
#include "allegro5/allegro5.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "allegro5/allegro_primitives.h"
#include "camera.h"
#include "keyboard.h"
#include "level.h"

namespace azzure {

	class Sprite
	{
	public:
		Sprite(const char *filePath, int SCREEN_W, int SCREEN_H, Level &level);
		~Sprite();

		ALLEGRO_BITMAP *m_Sprite;
		Vec2 m_XY;
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


		void UpdateSprite(bool key[], int curFrame, Camera &camera, Keyboard &keyboard, float SCREEN_W, float SCREEN_H, Level &level);

	private:
	};

}