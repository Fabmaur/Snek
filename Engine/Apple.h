#pragma once
#include "Board.h"
#include <random>

class Apple
{
	public:
		Apple(std::mt19937& rng, Board& brd);
		void Draw();
		bool checkEaten(Coords& coords);
		void respawn(std::mt19937& rng);

	private:	
		
		Coords coord;
		Color c;
		Board& brd;
		static constexpr Color red = Colors::Red;
		
};

