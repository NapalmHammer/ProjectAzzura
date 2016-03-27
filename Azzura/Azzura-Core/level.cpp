#include "level.h"

namespace azzure
{
	Level::Level()
		:m_Grid{1,1,1,1,1,1,1,1,1,1,
				1,0,0,1,1,1,1,1,1,1,
				1,0,0,1,1,1,1,1,1,1,
				1,0,0,1,0,1,1,1,0,1,
				1,0,1,1,1,1,1,1,0,1,
				1,0,1,1,1,1,1,1,0,1,
				1,0,1,1,1,0,0,1,0,1,
				1,1,1,1,0,0,1,1,0,1,
				1,1,1,1,0,1,1,0,0,1,
				1,1,1,1,1,1,1,1,1,1 }
	{

		for (int i = 0; i < 100; i++)
		{
			m_TileID[i] = m_Grid[i];
			if (m_Grid[i] != 0)
				m_CanWalk[i] = true;
			else
				m_CanWalk[i] = false;
		}
	}

	Level::~Level()
	{
	}


	void Level::drawLevel(float x, float y, float ze, float screenW, float screenH)
	{
			Vec2 xy(x, y);
			Vec2 tileIso = Vec2::twoDToIso(xy);
			int count = 0;
			for (int i = 0; i < 10;i++)
			{
				for ( int j = 0; j < 10;j++, count++)
				{
					
					if (m_TileID[count] == 1)
					Tile::drawBlock((tileIso.m_X + ((j - i) * (tileW / 2))) + screenW / 2, (tileIso.m_Y + ((j + i) * (tileH / 2))) + screenH / 10, ze);
				}
			}
	}
}