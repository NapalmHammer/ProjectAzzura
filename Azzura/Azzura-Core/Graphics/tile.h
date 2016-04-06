#pragma once

#include "allegro5\allegro_primitives.h"
#include "allegro5\allegro_image.h"
#include "../Utils/vec2.h"

namespace azzure
{
	class Tile 
	{
	public:

		ALLEGRO_BITMAP *m_Tiles;
		int m_TileW;
		int m_TileH;
		
		const static float tileWidth;
		const static float tileHeight;

		Tile(const char *fileAddress, int tileW, int tileH);
		~Tile();
		static void drawTile(float x, float y);
		void drawTile(float x, float y, int frame);
		static void drawBlock(float x, float y, float z);
		static void drawGrid(float x, float y, float width, float height, float z, float screenW, float screenH);

	private:

	};
}