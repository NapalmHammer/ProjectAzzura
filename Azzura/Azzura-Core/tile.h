#pragma once

#include "allegro5/allegro_primitives.h"
#include "vec2.h"

namespace azzure
{
	class Tile 
	{
	public:

		/*enum tileTypes
		{
			genericTile
		};
*/
		int m_TileW;
		int m_TileH;
		int m_TileID;
		bool m_CanWalk;
		const static float tileWidth;
		const static float tileHeight;

		Tile();
		~Tile();
		static void drawTile(float x, float y);
		static void drawBlock(float x, float y, float z);
		static void drawBlock(Vec2 vec, float z);
		static void drawGrid(float x, float y, float width, float height, float z, float screenW, float screenH);

	private:

	};
}