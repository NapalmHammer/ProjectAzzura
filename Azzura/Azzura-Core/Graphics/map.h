#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

namespace azzure
{
	struct Map
	{
	public:

		std::ifstream m_MapFile;
		std::string m_LevName;
		std::string m_TileAddress;
		int m_LevelWidth;
		int m_LevelHeight;
		int m_TileWidth;
		int m_TileHeight;
		int m_TileOverhang;
		int m_StartTileX;
		int m_StartTileY;
		int m_ImageHeight;
		std::vector<int> m_Tiles;


		Map(const char *address);
		~Map();
	};
}