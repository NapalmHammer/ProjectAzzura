#pragma once

#include "vec2.h"
#include "tile.h"

namespace azzure
{
	class Level
	{
	public:

		bool m_CanWalk[100];
		int m_TileID[100];
		int m_Grid[100];

		static const int tileW = 100;
		static const int tileH = 50;

		Level();
		~Level();

		void drawLevel(float x, float y, float ze, float screenW, float screenH);


	};
}