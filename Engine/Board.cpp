#include "Board.h"

Board::Board(Graphics & gfx)
:gfx(gfx)
{
}

void Board::drawCell(Coords& coord, Color c)
{
	gfx.DrawRectDim(coord.x*dimCells , coord.y*dimCells , dimCells -1, dimCells-1, c);
}

int Board::getGridHeight()
{
	return vertCells;
}

int Board::getGridWidth()
{
	return hozCells;
}
