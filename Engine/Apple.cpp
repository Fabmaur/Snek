#include "Apple.h"


Apple::Apple(std::mt19937& rng, Board& brd)
	:brd(brd)
{
		c = red;
		respawn(rng);
}

void Apple::Draw()
{
	brd.drawCell(coord, c);
}

bool Apple::checkEaten(Coords& coords)
{
	if (coord == coords) {
		return true;
	}
	else {
		return false;
	}
}

void Apple::respawn(std::mt19937 & rng)
{
	std::uniform_int_distribution<int> xDist(0, brd.getGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.getGridHeight() - 1);
	coord.x = xDist(rng);
	coord.y = yDist(rng);
}








