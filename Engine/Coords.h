#pragma once
struct Coords {
	void add(Coords& coord) {
		x += coord.x;
		y += coord.y;
	}
	bool operator==(const Coords& coord2) const {
		return x == coord2.x && 
				y == coord2.y;
	}
	int x;
	int y;
};