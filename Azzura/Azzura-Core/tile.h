#pragma once

#include "sprite.h"

namespace azzure
{
	class Tile 
	{
	public:
		const static float tileWidth;
		const static float tileHeight;

		static void drawTile(float x, float y);
		static void drawBlock(float x, float y, float z);
		static void drawGrid(float x, float y, float width, float height, float z);

	private:

	};
}