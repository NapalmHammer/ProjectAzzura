#include "tile.h"

namespace azzure {

	const float Tile::tileWidth = 100;
	const float Tile::tileHeight = Tile::tileWidth / 2;

	Tile::Tile(const char *fileAddress, int tileW, int tileH)
	{
		m_Tiles = al_load_bitmap(fileAddress);
		m_TileW = tileW;
		m_TileH = tileH;
		al_convert_mask_to_alpha(m_Tiles, al_map_rgb(0, 125, 125));
	}

	Tile::~Tile()
	{
		al_destroy_bitmap(m_Tiles);
	}

	void Tile::drawTile(float x, float y, int frame)
	{
		al_draw_bitmap_region(m_Tiles, frame * m_TileW, 0, m_TileW, m_TileH, x - m_TileW / 2, y, 0);
	}

	void Tile::drawTile(float x, float y)
	{
		al_draw_filled_triangle(x, y, x, y + tileHeight, x - tileWidth / 2, y + tileHeight / 2, al_map_rgb(255, 50, 50));
		al_draw_filled_triangle(x, y, x, y + tileHeight, x + tileWidth / 2, y + tileHeight / 2, al_map_rgb(255, 50, 50));

		al_draw_line(x, y, x + tileWidth / 2, y + tileHeight / 2, (al_map_rgb(0, 150, 0)), 1);
		al_draw_line(x + tileWidth / 2, y + tileHeight / 2, x, y + tileHeight, (al_map_rgb(0, 150, 0)), 1);
		al_draw_line(x, y + tileHeight, x - tileWidth / 2, y + tileHeight / 2, (al_map_rgb(0, 150, 0)), 1);
		al_draw_line(x - tileWidth / 2, y + tileHeight / 2, x, y, (al_map_rgb(0, 150, 0)), 1);
	}


	void Tile::drawBlock(float x, float y, float z)
	{
		float zHeight = z * tileHeight;
		
		//Draw top
		al_draw_filled_triangle(x, y - zHeight, x, y + tileHeight - zHeight, x - tileWidth / 2, y + tileHeight / 2 - zHeight, al_map_rgb(200, 0, 0));
		al_draw_filled_triangle(x, y - zHeight, x, y + tileHeight - zHeight, x + tileWidth / 2, y + tileHeight / 2 - zHeight, al_map_rgb(200, 0, 0));

		//Draw Left
		al_draw_filled_triangle(x - tileWidth / 2, y + tileHeight / 2 - zHeight, x, y + tileHeight - zHeight, x - tileWidth / 2, y + tileHeight / 2, al_map_rgb(100, 0, 0));
		al_draw_filled_triangle(x, y + tileHeight - zHeight, x - tileWidth / 2, y + tileHeight / 2, x, y + tileHeight, al_map_rgb(100, 0, 0));

		//Draw Right
		al_draw_filled_triangle(x + tileWidth / 2, y + tileHeight / 2 - zHeight, x, y + tileHeight - zHeight, x + tileWidth / 2, y + tileHeight / 2, al_map_rgb(255, 100, 100));
		al_draw_filled_triangle(x, y + tileHeight - zHeight, x + tileWidth / 2, y + tileHeight / 2, x, y + tileHeight, al_map_rgb(255, 100, 100));

		//Draw Outline
		al_draw_line(x, y - zHeight, x + tileWidth / 2, y + tileHeight / 2 - zHeight, (al_map_rgb(0, 50, 0)), 1);
		al_draw_line(x + tileWidth / 2, y + tileHeight / 2 - zHeight, x, y + tileHeight - zHeight, (al_map_rgb(0, 50, 0)), 1);
		al_draw_line(x, y + tileHeight - zHeight, x - tileWidth / 2, y + tileHeight / 2 - zHeight, (al_map_rgb(0, 50, 0)), 1);
		al_draw_line(x - tileWidth / 2, y + tileHeight / 2 - zHeight, x, y - zHeight, (al_map_rgb(0, 50, 0)), 1);
	}

	void Tile::drawGrid(float x, float y, float width, float height, float ze, float screenW, float screenH)
	{
		Vec2 xy(x, y);
		Vec2 tileIso = Vec2::twoDToIso(xy);
		for (int i = 0; i < width;i++)
		{
			for (int j = 0; j < height;j++)
			{
				Tile::drawBlock((tileIso.m_X + ((i - j) * (tileWidth / 2))) + screenW / 2, (tileIso.m_Y + ((i + j) * (tileHeight / 2))) + screenH / 10, ze);
			}
		}
	}


}