#pragma once
#include "Board.h"
#include <random>

class Rock
{
public:
	void init(std::mt19937& rng, Board& brd);
	void Draw(Board& brd);
	bool checkTouch(Coords& coords);

private:
	static constexpr Color grey = Colors::Gray;
	static constexpr int maxRocks = 100;
	int currentRocks = 0;
	Coords coord;
	Color c = grey;
	

};

