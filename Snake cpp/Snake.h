#pragma once
#include <deque>
#include "SnakeSegment.h"
#include "Apple.h"

enum class Direction { Up, Down, Left, Right };

class Snake
{
private:
	std::deque<SnakeSegment> snake;
	Direction dir;
	bool dirChanged;
	bool grow;

public:
	Snake();
	~Snake();

public:
	void move();
	void draw();
	void setDirection(Direction newDir);

	bool eatApple(Apple & apple);
};