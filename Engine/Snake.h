#pragma once
#include "Coords.h"
#include "Colors.h"
#include "Board.h"

class Snake
{
public:
	class Segment {
		public:
			void initHead(const Coords& selfCoords);
			void initBody(Color c_in);
			void follow(Segment& nextSegment);
			void moveHead( Coords& coord);
			void draw(Board& brd);
			bool checkTouching(Segment& segments);
			bool checkInGrid();
			Coords getCoords();

		private:
			Coords coords;
			Color c;
	};

public:
	Snake(const Coords& coords);
	void Move(Coords& vector);
	void grow();
	void Draw(Board& brd);
	bool inGrid();
	bool isNotTouching();
	Coords getCoord();


private:
	static constexpr Color headColour = Colors::Yellow;
	static constexpr int maxSegments = 1000;
	int currentSegments = 1;
	Segment segments[maxSegments];

};

