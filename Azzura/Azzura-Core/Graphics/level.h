#pragma once

#include "../Utils/vec2.h"
#include "tile.h"
#include <vector>
#include <iostream>
#include "map.h"

namespace azzure
{
	class Level
	{
	public:
		Map map;
		//bool m_CanWalk[100];
		int m_TileID[100];
		int m_Grid[100];
		Vec2 startTile;
		std::vector<bool> m_CanWalk;

		static const int tileW = 100;
		static const int tileH = 50;

		Level();
		Level(const char *address);
		~Level();

		void drawLevel(float &x, float &y, float ze, float &screenW, float &screenH, Tile &tile);


	};
}