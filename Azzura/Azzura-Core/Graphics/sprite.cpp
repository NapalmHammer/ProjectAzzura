#include "sprite.h"

namespace azzure {


	Sprite::Sprite(const char *filePath, int SCREEN_W, int SCREEN_H, Level &level)
	{
		m_FilePath = filePath;
		m_Sprite = al_load_bitmap(m_FilePath);
		frameWidth = 20;
		frameHeight = 42;
		m_x = level.map.m_StartTileX * 50 - 25;
		m_y = level.map.m_StartTileY * 50 - 25;
		m_XY.m_X = m_x;
		m_XY.m_Y = m_y;
		maxFrame = 5;
		frameCount = 0;
		frameDelay = 6;
		curDirection = 0;
		al_convert_mask_to_alpha(m_Sprite, al_map_rgb(0, 128, 128));
	}
	Sprite::Sprite(const char *filePath, int frameW, int frameH, int maxF, int x, int y, Level &level)
	{
		m_FilePath = filePath;
		m_Sprite = al_load_bitmap(m_FilePath);
		frameWidth = frameW;
		frameHeight = frameH;
		m_x = x * 50 - 25;
		m_y = y * 50 - 25;
		m_XY.m_X = (x - 25);
		m_XY.m_Y = (y - 25);
		maxFrame = maxF;
		frameCount = 0;
		frameDelay = 3;
		count = 0;
		//curDirection = 0;
		al_convert_mask_to_alpha(m_Sprite, al_map_rgb(0, 0, 0));
	}

	Sprite::~Sprite()
	{
		al_destroy_bitmap(m_Sprite);
	}

	void Sprite::UpdateSprite(Camera &camera, Keyboard &keyboard, Level &level, float &screenW, float &screenH)
	{
		Vec2 cam(camera.m_CamX, camera.m_CamY);
		Vec2 camIso = Vec2::twoDToIso(cam);
		Vec2 loc(level.startTile.m_X + m_x, level.startTile.m_Y + m_y);
		Vec2 iso = Vec2::twoDToIso(loc);
		count+=1;
		if (count >= frameDelay)
		{
			if (frameCount >= maxFrame)
				frameCount = 0;
			frameCount+=1;
			count = 0;
		}
		al_draw_bitmap_region(m_Sprite, frameWidth * frameCount, 0, frameWidth, frameHeight, (int)(camIso.m_X + screenW / 2 + iso.m_X - frameWidth/2), (int)(camIso.m_Y + screenH / 2 + iso.m_Y - frameHeight), 0);
	}

	void Sprite::UpdateSprite(int curFrame, Camera &camera, Keyboard &keyboard, float SCREEN_W, float SCREEN_H, Level &level)
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
				if (level.m_CanWalk[boundY * level.map.m_LevelWidth + boundX] != false)
				{
					m_XY.m_X -= 2.0;
					camera.m_CamX += 2.0;
				}
				boundX = floor((m_XY.m_X * 2) / 100);
				boundY = floor(((m_XY.m_Y - 2.0) * 2) / 100);
				if (level.m_CanWalk[boundY * level.map.m_LevelWidth + boundX] != false)
				{
					m_XY.m_Y -= 2.0;
					camera.m_CamY += 2.0;
				}
				std::cout << " Mega X: " << m_XY.m_X << "Mega Y: " << m_XY.m_Y << std::endl;
				Vec2 iso(Vec2::twoDToIso(m_XY));
				al_draw_bitmap_region(m_Sprite, curFrame * 22 + 22, 42, 22, frameHeight,SCREEN_W / 2 - 11,SCREEN_H / 2 - frameHeight, 0);
				curDirection = 42;
				return;
			}
			else if (keyboard.key_down(ALLEGRO_KEY_UP) && keyboard.key_down(ALLEGRO_KEY_RIGHT))
			{
				//camera.modXY(-2.0f, +1.0f);

				boundX = floor(((m_XY.m_X + 1.0) * 2) / 100);
				boundY = floor((m_XY.m_Y * 2) / 100);
				if (level.m_CanWalk[boundY * level.map.m_LevelWidth + boundX] != false)
				{
					m_XY.m_X += 1.0;
					camera.m_CamX -= 1.0;
				}
				boundX = floor((m_XY.m_X * 2) / 100);
				boundY = floor(((m_XY.m_Y - 1.0) * 2) / 100);
				if (level.m_CanWalk[boundY * level.map.m_LevelWidth + boundX] != false)
				{
					m_XY.m_Y -= 1.0;
					camera.m_CamY += 1.0;
				}
				std::cout << " Mega X: " << m_XY.m_X << "Mega Y: " << m_XY.m_Y << std::endl;
				Vec2 iso(Vec2::twoDToIso(m_XY));
				al_draw_bitmap_region(m_Sprite, curFrame * 30 + 22, 126, 30, frameHeight,SCREEN_W / 2 - 15, SCREEN_H / 2 - frameHeight, 0);
				curDirection = 126;
				return;
			}
			//camera.modXY(0.0f, +2.0f);

			boundX = floor((m_XY.m_X * 2) / 100);
			boundY = floor(((m_XY.m_Y - 2.0) * 2) / 100);
			if (level.m_CanWalk[boundY * level.map.m_LevelWidth + boundX] != false)
			{
				m_XY.m_Y -= 2.0;
				camera.m_CamY += 2.0;
			}
			std::cout << " Mega X: " << m_XY.m_X << "Mega Y: " << m_XY.m_Y << std::endl;
			Vec2 iso(Vec2::twoDToIso(m_XY));
			al_draw_bitmap_region(m_Sprite, curFrame * 26 + 22, 294, 26, frameHeight, SCREEN_W / 2 - 13, SCREEN_H / 2 - frameHeight, 0);
			curDirection = 294;
			return;
		}

		else if (keyboard.key_down(ALLEGRO_KEY_DOWN))
		{

			if (keyboard.key_down(ALLEGRO_KEY_DOWN) && keyboard.key_down(ALLEGRO_KEY_LEFT))
			{
				//camera.modXY(+2.0f, -1.0f);

				boundX = floor(((m_XY.m_X - 1.0) * 2) / 100);
				boundY = floor((m_XY.m_Y * 2) / 100);
				if (level.m_CanWalk[boundY * level.map.m_LevelWidth + boundX] != false)
				{
					m_XY.m_X -= 1.0;
					camera.m_CamX += 1.0;
				}
				boundX = floor((m_XY.m_X * 2) / 100);
				boundY = floor(((m_XY.m_Y + 1.0) * 2) / 100);
				if (level.m_CanWalk[boundY * level.map.m_LevelWidth + boundX] != false)
				{
					m_XY.m_Y += 1.0;
					camera.m_CamY -= 1.0;
				}
				std::cout << " Mega X: " << m_XY.m_X << "Mega Y: " << m_XY.m_Y << std::endl;
				Vec2 iso(Vec2::twoDToIso(m_XY));
				std::cout << " Mega Iso X: " << iso.m_X << "Mega Iso Y: " << iso.m_Y << std::endl;
				al_draw_bitmap_region(m_Sprite, curFrame * 30 + 22, 84, 30, frameHeight, SCREEN_W / 2 - 15, SCREEN_H / 2 - frameHeight, 0);
				curDirection = 84;
				return;
			}
			else if (keyboard.key_down(ALLEGRO_KEY_DOWN) && keyboard.key_down(ALLEGRO_KEY_RIGHT))
			{
				//camera.modXY(-2.0f, -1.0f);

				boundX = floor(((m_XY.m_X + 2.0) * 2) / 100);
				boundY = floor((m_XY.m_Y * 2) / 100);
				if (level.m_CanWalk[boundY * level.map.m_LevelWidth + boundX] != false)
				{
					m_XY.m_X += 2.0;
					camera.m_CamX -= 2.0;
				}
				boundX = floor((m_XY.m_X * 2) / 100);
				boundY = floor(((m_XY.m_Y + 2.0) * 2) / 100);
				if (level.m_CanWalk[boundY * level.map.m_LevelWidth + boundX] != false)
				{
					m_XY.m_Y += 2.0;
					camera.m_CamY -= 2.0;
				}
				std::cout << " Mega X: " << m_XY.m_X << "Mega Y: " << m_XY.m_Y << std::endl;
				Vec2 iso(Vec2::twoDToIso(m_XY));
				al_draw_bitmap_region(m_Sprite, curFrame * 22 + 22, 0, 22, frameHeight, SCREEN_W / 2 - 11, SCREEN_H / 2 - frameHeight, 0);
				curDirection = 0;
				return;
			}
			//camera.modXY(0.0f, -2.0f);

			boundX = floor((m_XY.m_X * 2) / 100);
			boundY = floor(((m_XY.m_Y + 2.0) * 2) / 100);
			if (level.m_CanWalk[boundY * level.map.m_LevelWidth + boundX] != false)
			{
				m_XY.m_Y += 2.0;
				camera.m_CamY -= 2.0;
			}
			std::cout << " Mega X: " << m_XY.m_X << "Mega Y: " << m_XY.m_Y << std::endl;
			Vec2 iso(Vec2::twoDToIso(m_XY));
			al_draw_bitmap_region(m_Sprite, curFrame * 28 + 22, 168, 28, frameHeight, SCREEN_W / 2 - 14, SCREEN_H / 2 - frameHeight, 0);
			curDirection = 168;
			return;
		}

		else if (keyboard.key_down(ALLEGRO_KEY_LEFT))
		{
			//camera.modXY(+2.0f, 0.0f);

			boundX = floor(((m_XY.m_X - 2.0) * 2) / 100);
			boundY = floor((m_XY.m_Y * 2) / 100);
			if (level.m_CanWalk[boundY * level.map.m_LevelWidth + boundX] != false)
			{
				m_XY.m_X -= 2.0;
				camera.m_CamX += 2.0;
			}
			std::cout << " Mega X: " << m_XY.m_X << "Mega Y: " << m_XY.m_Y << std::endl;
			Vec2 iso(Vec2::twoDToIso(m_XY));
			al_draw_bitmap_region(m_Sprite, curFrame * 26 + 22, 252, 26, frameHeight, SCREEN_W / 2 - 13, SCREEN_H / 2 - frameHeight, 0);
			curDirection = 252;
			return;
		}

		else if (keyboard.key_down(ALLEGRO_KEY_RIGHT))
		{
			//camera.modXY(-2.0f, 0.0f);

			boundX = floor(((m_XY.m_X + 2.0) * 2) / 100);
			boundY = floor((m_XY.m_Y * 2) / 100);
			if (level.m_CanWalk[boundY * level.map.m_LevelWidth + boundX] != false)
			{
				m_XY.m_X += 2.0;
				camera.m_CamX -= 2.0;
			}
			std::cout << " Mega X: " << m_XY.m_X << "Mega Y: " << m_XY.m_Y << std::endl;
			Vec2 iso(Vec2::twoDToIso(m_XY));
			al_draw_bitmap_region(m_Sprite, curFrame * 28 + 22, 210, 28, frameHeight, SCREEN_W / 2 - 14, SCREEN_H / 2 - frameHeight, 0);
			curDirection = 210;
			return;
		}

		else
		{
			//Vec2 iso(Vec2::twoDToIso(m_XY));
			al_draw_bitmap_region(m_Sprite, 0, curDirection, 20, frameHeight, SCREEN_W / 2 - 10, SCREEN_H / 2 - frameHeight, 0);
			return;
		}
	}
}