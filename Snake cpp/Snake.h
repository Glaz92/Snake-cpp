#pragma once
#include <deque>
#include "SnakeSegment.h"

enum class Direction { Up, Down, Left, Right };

class Snake
{
private:
	std::deque<SnakeSegment> snake;
	Direction dir;
	bool dirChanged;;

public:
	Snake();
	~Snake();

public:
	void move();
	void draw();
	void setDirection(Direction newDir);
};