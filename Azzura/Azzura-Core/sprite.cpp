#include "sprite.h"

namespace azzure {


	Sprite::Sprite(const char *filePath, int SCREEN_W, int SCREEN_H, Level &level)
	{
		m_FilePath = filePath;
		m_Sprite = al_load_bitmap(m_FilePath);
		frameWidth = 20;
		frameHeight = 42;
		m_x = (Level::tileW / 2) * 5;
		m_y = Level::tileH * 5;
		m_XY.m_X = m_x;
		m_XY.m_Y = m_y;
		maxFrame = 5;
		frameCount = 0;
		frameDelay = 6;
		curDirection = 0;
		al_convert_mask_to_alpha(m_Sprite, al_map_rgb(0, 128, 128));
	}

	Sprite::~Sprite()
	{
		al_destroy_bitmap(m_Sprite);
	}


	void Sprite::UpdateSprite(bool key[], int curFrame, Camera &camera, Keyboard &keyboard, float SCREEN_W, float SCREEN_H, Level &level)
	{
		int boundX = 0;
		int boundY = 0;
		if (keyboard.key_down(ALLEGRO_KEY_UP))
		{
			if (keyboard.key_down(ALLEGRO_KEY_UP) && keyboard.key_down(ALLEGRO_KEY_LEFT))
			{
				//camera.modXY(+2.0f, +1.0f);
				
				boundX = floor(((m_XY.m_X - 2.0) * 2) / 100);
				boundY = floor((m_XY.m_Y * 2) / 100);
				if (level.m_CanWalk[boundY * 10 + boundX] != false)
				{
					m_XY.m_X -= 2.0;
				}
				boundX = floor((m_XY.m_X * 2) / 100);
				boundY = floor(((m_XY.m_Y - 2.0) * 2) / 100);
				if (level.m_CanWalk[boundY * 10 + boundX] != false)
				{
					m_XY.m_Y -= 2.0;
				}
				if (m_XY.m_X < 0)
					m_XY.m_X = 0;
				if (m_XY.m_Y < 0)
					m_XY.m_Y = 0;
				std::cout << " Mega X: " << m_XY.m_X << "Mega Y: " << m_XY.m_Y << std::endl;
				Vec2 iso(Vec2::twoDToIso(m_XY));
				al_draw_bitmap_region(m_Sprite, curFrame * 22 + 22, 42, 22, frameHeight,iso.m_X - 11 + SCREEN_W / 2,iso.m_Y - frameHeight + SCREEN_H / 10, 0);
				curDirection = 42;
				return;
			}
			else if (keyboard.key_down(ALLEGRO_KEY_UP) && keyboard.key_down(ALLEGRO_KEY_RIGHT))
			{
				//camera.modXY(-2.0f, +1.0f);

				boundX = floor(((m_XY.m_X + 2.0) * 2) / 100);
				boundY = floor((m_XY.m_Y * 2) / 100);
				if (level.m_CanWalk[boundY * 10 + boundX] != false)
				{
					m_XY.m_X += 2.0;
				}
				boundX = floor((m_XY.m_X * 2) / 100);
				boundY = floor(((m_XY.m_Y - 2.0) * 2) / 100);
				if (level.m_CanWalk[boundY * 10 + boundX] != false)
				{
					m_XY.m_Y -= 2.0;
				}
				if (m_XY.m_X > 500)
					m_XY.m_X = 500;
				if (m_XY.m_Y < 0)
					m_XY.m_Y = 0;
				std::cout << " Mega X: " << m_XY.m_X << "Mega Y: " << m_XY.m_Y << std::endl;
				Vec2 iso(Vec2::twoDToIso(m_XY));
				al_draw_bitmap_region(m_Sprite, curFrame * 30 + 22, 126, 30, frameHeight, iso.m_X - 15 + SCREEN_W / 2,iso.m_Y - frameHeight + SCREEN_H / 10, 0);
				curDirection = 126;
				return;
			}
			//camera.modXY(0.0f, +2.0f);

			boundX = floor((m_XY.m_X * 2) / 100);
			boundY = floor(((m_XY.m_Y - 2.0) * 2) / 100);
			if (level.m_CanWalk[boundY * 10 + boundX] != false)
			{
				m_XY.m_Y -= 2.0;
			}
			if (m_XY.m_Y < 0)
				m_XY.m_Y = 0;
			std::cout << " Mega X: " << m_XY.m_X << "Mega Y: " << m_XY.m_Y << std::endl;
			Vec2 iso(Vec2::twoDToIso(m_XY));
			al_draw_bitmap_region(m_Sprite, curFrame * 26 + 22, 294, 26, frameHeight,iso.m_X - 13 + SCREEN_W / 2,iso.m_Y - frameHeight + SCREEN_H / 10, 0);
			curDirection = 294;
			return;
		}

		else if (keyboard.key_down(ALLEGRO_KEY_DOWN))
		{

			if (keyboard.key_down(ALLEGRO_KEY_DOWN) && keyboard.key_down(ALLEGRO_KEY_LEFT))
			{
				//camera.modXY(+2.0f, -1.0f);

				boundX = floor(((m_XY.m_X - 2.0) * 2) / 100);
				boundY = floor((m_XY.m_Y * 2) / 100);
				if (level.m_CanWalk[boundY * 10 + boundX] != false)
				{
					m_XY.m_X -= 2.0;
				}
				boundX = floor((m_XY.m_X * 2) / 100);
				boundY = floor(((m_XY.m_Y + 2.0) * 2) / 100);
				if (level.m_CanWalk[boundY * 10 + boundX] != false)
				{
					m_XY.m_Y += 2.0;
				}
				if (m_XY.m_X < 0)
					m_XY.m_X = 0;
				if (m_XY.m_Y >= 500)
					m_XY.m_Y = 498;
				std::cout << " Mega X: " << m_XY.m_X << "Mega Y: " << m_XY.m_Y << std::endl;
				Vec2 iso(Vec2::twoDToIso(m_XY));
				std::cout << " Mega Iso X: " << iso.m_X << "Mega Iso Y: " << iso.m_Y << std::endl;
				al_draw_bitmap_region(m_Sprite, curFrame * 30 + 22, 84, 30, frameHeight,iso.m_X - 15 + SCREEN_W / 2,/*(int)*/iso.m_Y - frameHeight + SCREEN_H / 10, 0);
				curDirection = 84;
				return;
			}
			else if (keyboard.key_down(ALLEGRO_KEY_DOWN) && keyboard.key_down(ALLEGRO_KEY_RIGHT))
			{
				//camera.modXY(-2.0f, -1.0f);

				boundX = floor(((m_XY.m_X + 2.0) * 2) / 100);
				boundY = floor((m_XY.m_Y * 2) / 100);
				if (level.m_CanWalk[boundY * 10 + boundX] != false)
				{
					m_XY.m_X += 2.0;
				}
				boundX = floor((m_XY.m_X * 2) / 100);
				boundY = floor(((m_XY.m_Y + 2.0) * 2) / 100);
				if (level.m_CanWalk[boundY * 10 + boundX] != false)
				{
					m_XY.m_Y += 2.0;
				}
				if (m_XY.m_X > 500)
					m_XY.m_X = 500;
				if (m_XY.m_Y >= 500)
					m_XY.m_Y = 499;
				std::cout << " Mega X: " << m_XY.m_X << "Mega Y: " << m_XY.m_Y << std::endl;
				Vec2 iso(Vec2::twoDToIso(m_XY));
				al_draw_bitmap_region(m_Sprite, curFrame * 22 + 22, 0, 22, frameHeight,iso.m_X - 11 + SCREEN_W / 2,iso.m_Y - frameHeight + SCREEN_H / 10, 0);
				curDirection = 0;
				return;
			}
			//camera.modXY(0.0f, -2.0f);

			boundX = floor((m_XY.m_X * 2) / 100);
			boundY = floor(((m_XY.m_Y + 2.0) * 2) / 100);
			if (level.m_CanWalk[boundY * 10 + boundX] != false)
			{
				m_XY.m_Y += 2.0;
			}
			if (m_XY.m_Y >= 500)
				m_XY.m_Y = 499;
			std::cout << " Mega X: " << m_XY.m_X << "Mega Y: " << m_XY.m_Y << std::endl;
			Vec2 iso(Vec2::twoDToIso(m_XY));
			al_draw_bitmap_region(m_Sprite, curFrame * 28 + 22, 168, 28, frameHeight,iso.m_X - 14 + SCREEN_W / 2,iso.m_Y - frameHeight + SCREEN_H / 10, 0);
			curDirection = 168;
			return;
		}

		else if (keyboard.key_down(ALLEGRO_KEY_LEFT))
		{
			//camera.modXY(+2.0f, 0.0f);

			boundX = floor(((m_XY.m_X - 2.0) * 2) / 100);
			boundY = floor((m_XY.m_Y * 2) / 100);
			if (level.m_CanWalk[boundY * 10 + boundX] != false)
			{
				m_XY.m_X -= 2.0;
			}
			if (m_XY.m_X < 0.0)
				m_XY.m_X = 0.0;
			std::cout << " Mega X: " << m_XY.m_X << "Mega Y: " << m_XY.m_Y << std::endl;
			Vec2 iso(Vec2::twoDToIso(m_XY));
			al_draw_bitmap_region(m_Sprite, curFrame * 26 + 22, 252, 26, frameHeight,iso.m_X - 13 + SCREEN_W / 2,iso.m_Y - frameHeight + SCREEN_H / 10, 0);
			curDirection = 252;
			return;
		}

		else if (keyboard.key_down(ALLEGRO_KEY_RIGHT))
		{
			//camera.modXY(-2.0f, 0.0f);

			boundX = floor(((m_XY.m_X + 2.0) * 2) / 100);
			boundY = floor((m_XY.m_Y * 2) / 100);
			if (level.m_CanWalk[boundY * 10 + boundX] != false)
			{
				m_XY.m_X += 2.0;
			}
			if (m_XY.m_X >= 500)
				m_XY.m_X = 499;
			std::cout << " Mega X: " << m_XY.m_X << "Mega Y: " << m_XY.m_Y << std::endl;
			Vec2 iso(Vec2::twoDToIso(m_XY));
			al_draw_bitmap_region(m_Sprite, curFrame * 28 + 22, 210, 28, frameHeight,iso.m_X - 14 + SCREEN_W / 2,iso.m_Y - frameHeight + SCREEN_H / 10, 0);
			curDirection = 210;
			return;
		}

		else
		{
			Vec2 iso(Vec2::twoDToIso(m_XY));
			al_draw_bitmap_region(m_Sprite, 0, curDirection, 20, frameHeight,iso.m_X - 10 + SCREEN_W / 2,iso.m_Y - frameHeight + SCREEN_H / 10, 0);
			return;
		}
	}
}