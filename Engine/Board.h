#pragma once
#include "Graphics.h"
#include "Coords.h"


class Board
{
public:
	Board(Graphics& gfx);
	void drawCell(Coords& coord, Color c);
	int getGridHeight();
	int getGridWidth();

private:
	static constexpr int vertCells = 30;
	static constexpr int hozCells = 40;
	static constexpr int dimCells = 20;
	int x;
	int y;
	Graphics& gfx;

	

};

