#include "tile.h"

namespace azzure {


	const float Tile::tileWidth = 100;
	const float Tile::tileHeight = Tile::tileWidth / 2;

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

	void Tile::drawGrid(float x, float y, float width, float height, float ze)
	{
		for (int i = 0; i < width;i++)
		{
			for (int j = 0; j < height;j++)
			{
				//Tile::drawTile(x + (i - j) * tileHeight / 2,  y + (i + j) * tileWidth / 2);
				Tile::drawBlock(x + (i - j) * tileWidth / 2, y + (i + j) * tileHeight / 2, ze);
			}
		}
	}
}