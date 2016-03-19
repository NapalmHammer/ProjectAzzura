#pragma once
#include <vector>
#include <string>
#include <map>


namespace azzure
{

	class Tile
	{
	public:
		int m_Width;
		int m_Height;
		int m_TileSize;

		int m_NumSelected;
		int m_NumRegions[1];
		std::vector<Tile> tiles;
		std::vector<int> resources;
	};

}