#include "Rock.h"

void Rock::init(std::mt19937 & rng, Board& brd)
{
	std::uniform_int_distribution<int> xDist(0, brd.getGridWidth() - 1 );
	std::uniform_int_distribution<int> yDist(0, brd.getGridHeight() - 1 );
	coord = { xDist(rng), yDist(rng) };

}

void Rock::Draw(Board& brd)
{
	brd.drawCell(coord, c);
}

bool Rock::checkTouch(Coords& coords)
{
	if (coord == coords) {
		return true;
	}
	else {
		return false;
	}
}









