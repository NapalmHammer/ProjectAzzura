#include "map.h"


namespace azzure
{
	Map::Map(const char *address)
	{
		m_MapFile.open(address);

		if (m_MapFile.is_open())
		{
			m_MapFile >> m_LevName;
			m_MapFile >> m_LevelWidth;
			m_MapFile >> m_LevelHeight;
			m_MapFile >> m_StartTileX;
			m_MapFile >> m_StartTileY;
			m_MapFile >> m_TileAddress;
			m_MapFile >> m_TileWidth;
			m_MapFile >> m_TileHeight;
			m_MapFile >> m_TileOverhang;
			m_ImageHeight = m_TileHeight + m_TileOverhang;
			m_Tiles.resize(m_LevelWidth * m_LevelHeight);

			for (int i = 0; i < (m_LevelWidth * m_LevelHeight);i++)
			{
				m_MapFile >> m_Tiles[i];
			}
			m_MapFile.close();
		}
	}
	Map::~Map()
	{

	}

}