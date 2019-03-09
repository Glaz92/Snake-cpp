#pragma once
#include <SFML/Graphics.hpp>
#include "SnakeSegment.h"

class Apple : public SnakeSegment
{
public:
	Apple();
	~Apple();

public:
	bool isEaten(SnakeSegment & head);
	void setNewPosition(std::deque<SnakeSegment> & segments);
};

