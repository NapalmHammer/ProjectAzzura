#include "level.h"

namespace azzure
{

	Level::Level(const char *address)
		:map(address)
	{
		
		m_CanWalk.resize(map.m_LevelWidth * map.m_LevelHeight);
		for (int i = 0; i < (map.m_LevelWidth * map.m_LevelHeight); i++)
		{
			if (map.m_Tiles[i] != 0)
				m_CanWalk[i] = true;
			else
				m_CanWalk[i] = false;
		}
		startTile.m_X = (-map.m_StartTileX * map.m_TileHeight) + 25;
		startTile.m_Y = (-map.m_StartTileY * map.m_TileHeight) + 25;
	}

	Level::~Level()
	{
	}


	void Level::drawLevel(float &x, float &y, float ze, float &screenW, float &screenH, Tile &tile)
	{
		Vec2 xyoffiso = Vec2::twoDToIso(startTile);
			Vec2 xy(x, y);
			//std::cout << "Camera X: " << x << " Camera Y: " << y;
			Vec2 tileIso = Vec2::twoDToIso(xy);
			//std::cout << "    ISO X " << tileIso.m_X << " ISO Y: " << tileIso.m_Y << std::endl;
			int count = 0;
			for (int i = 0; i < map.m_LevelWidth;i++)
			{
				for ( int j = 0; j < map.m_LevelHeight;j++, count++)
				{
					
					if (map.m_Tiles[count] > 0)
						tile.drawTile((int)((tileIso.m_X + ((j - i) * (tile.m_TileW / 2))) + screenW / 2 + xyoffiso.m_X), (int)((tileIso.m_Y + ((j + i) * (tile.m_TileW / 4))) + screenH / 2 + xyoffiso.m_Y), map.m_Tiles[i * map.m_LevelWidth + j] - 1);
				}
			}
	}
}