#include "sprite.h"

namespace azzure {


	Sprite::Sprite(const char *filePath, int SCREEN_W, int SCREEN_H)
	{
		m_FilePath = filePath;
		m_Sprite = al_load_bitmap(m_FilePath);
		frameWidth = 20;
		frameHeight = 40;
		m_x = SCREEN_W / 2 - frameWidth / 2;
		m_y = SCREEN_H / 2 - frameHeight / 2;
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


	void Sprite::UpdateSprite(bool key[], int curFrame)
	{
		if (key[KEY_UP])
		{
			if (key[KEY_UP] && key[KEY_LEFT])
			{
				m_x -= 2;
				m_y -= 2;
				al_draw_bitmap_region(m_Sprite, curFrame * 26 + 22, 259, 26, 42, m_x, m_y, 0);
				curDirection = 259;
				return;
			}
			else if (key[KEY_UP] && key[KEY_RIGHT])
			{
				m_x += 2;
				m_y -= 2;
				al_draw_bitmap_region(m_Sprite, curFrame * 26 + 22, 302, 26, 42, m_x, m_y, 0);
				curDirection = 302;
				return;
			}
			m_y -= 2;
			al_draw_bitmap_region(m_Sprite, curFrame * 20 + 22, 44, 20, 42, m_x, m_y, 0);
			curDirection = 44;
			return;
		}

		else if (key[KEY_DOWN])
		{

			if (key[KEY_DOWN] && key[KEY_LEFT])
			{
				m_x -= 2;
				m_y += 2;
				al_draw_bitmap_region(m_Sprite, curFrame * 27 + 22, 175, 27, 40, m_x, m_y, 0);
				curDirection = 173;
				return;
			}
			else if (key[KEY_DOWN] && key[KEY_RIGHT])
			{
				m_x += 2;
				m_y += 2;
				al_draw_bitmap_region(m_Sprite, curFrame * 27 + 22, 218, 27, 40, m_x, m_y, 0);
				curDirection = 216;
				return;
			}
			m_y += 2;
			al_draw_bitmap_region(m_Sprite, curFrame * 21 + 22, 3, 21, 40, m_x, m_y, 0);
			curDirection = 1;
			return;
		}

		else if (key[KEY_LEFT])
		{
			m_x -= 2;
			al_draw_bitmap_region(m_Sprite, curFrame * 29 + 22, 88, 29, 41, m_x, m_y, 0);
			curDirection = 87;
			return;
		}

		else if (key[KEY_RIGHT])
		{
			m_x += 2;
			al_draw_bitmap_region(m_Sprite, curFrame * 29 + 22, 131, 29, 41, m_x, m_y, 0);
			curDirection = 130;
			return;
		}

		else
		{
			al_draw_bitmap_region(m_Sprite, 1, curDirection, 20, 42, m_x, m_y, 0);
			return;
		}
	}
}