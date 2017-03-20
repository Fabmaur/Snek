#include "Snake.h"

Snake::Snake(const Coords & coords)
{
	constexpr int nColors = 4;
	constexpr Color bodyColors[nColors] = {
	{ 10, 100, 32 },
	{ 10, 130, 48 },
	{ 18, 160, 48 },
	{ 10, 130, 48 }};
	for (int n = 1; n < maxSegments; n++) {
		segments[n].initBody(bodyColors[n%nColors]);
	}
	segments[0].initHead(coords);
}

void Snake::Move(Coords& vector)
{
	for (int n = currentSegments - 1; n > 0; n--) {
		segments[n].follow(segments[n - 1]);

	}
	segments[0].moveHead(vector);
}

void Snake::grow()
{
	currentSegments++;
}

void Snake::Draw(Board& brd)
{
	for (int n = 0; n < currentSegments ; n++) {
		segments[n].draw(brd);
	}
}

bool Snake::inGrid()
{
	return segments[0].checkInGrid();
}

bool Snake::isNotTouching()
{
	for (int n = 1; n < currentSegments; n++) {
		if (segments[0].getCoords() == segments[n].getCoords()) {
			return false;
		}
	}
	return true;
}

Coords Snake::getCoord()
{
	return segments[0].getCoords();
}


void Snake::Segment::initHead(const Coords & selfCoords)
{
	coords = selfCoords;
	c = headColour;
}

void Snake::Segment::initBody(Color c_in)
{
	c = c_in;
}

void Snake::Segment::follow(Segment & nextSegment)
{
	coords = nextSegment.coords;
}

void Snake::Segment::moveHead(Coords& coord)
{
	coords.add(coord);
}

void Snake::Segment::draw(Board& brd)
{
	brd.drawCell(coords, c);
}



bool Snake::Segment::checkInGrid()
{
	return coords.x < 40 &&
		coords.x >= 0 &&
		coords.y >= 0 &&
		coords.y < 30;

}

Coords Snake::Segment::getCoords()
{
	return coords;
}


