#include "Apple.h"
#include "ConstElements.h"

Apple::Apple()
{
	segment.setFillColor(sf::Color::Blue);
	segment.setPosition(snakeSegmentSize * 3, snakeSegmentSize * 3);
}

Apple::~Apple()
{
}

bool Apple::isEaten(SnakeSegment & head)
{
	auto isTheSame = [](float x, float y) { return x - 3 < y && x + 3 > y; };

	if (isTheSame(head.getPosition().x, segment.getPosition().x))
		if (isTheSame(head.getPosition().y, segment.getPosition().y))
			return true;

	return false;
}

void Apple::setNewPosition(std::deque<SnakeSegment> & segments)
{
	int x = rand() % gameBoardWidth;
	int y = rand() % gameBoardHeight;

	segment.setPosition(snakeSegmentSize + x * snakeSegmentSize, snakeSegmentSize + y * snakeSegmentSize);

	if (checkCollision(segments)) setNewPosition(segments);
}
