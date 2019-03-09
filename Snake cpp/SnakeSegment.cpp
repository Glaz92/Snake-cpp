#include "SnakeSegment.h"
#include "Window.h"
#include "ConstElements.h"

SnakeSegment::SnakeSegment()
	: segment(sf::Vector2f(snakeSegmentSize - 2, snakeSegmentSize - 2))
{
	segment.setOutlineThickness(2);
	segment.setFillColor(snakeFillColor);
	segment.setOutlineColor(snakeOutlineColor);
}

SnakeSegment::SnakeSegment(sf::Vector2f position)
	: segment(sf::Vector2f(snakeSegmentSize-2,snakeSegmentSize-2))
{
	segment.setPosition(position);
	segment.setOutlineThickness(2);
	segment.setFillColor(snakeFillColor);
	segment.setOutlineColor(snakeOutlineColor);
}

SnakeSegment::~SnakeSegment()
{
}

void SnakeSegment::draw()
{
	GetWindow().draw(segment);
}

bool SnakeSegment::checkCollision(std::deque<SnakeSegment>& segments)
{
	auto isTheSame = [](float x, float y) { return x - 3 < y && x + 3 > y; };

	for (auto s : segments)
	{
		if (isTheSame(s.getPosition().x, segment.getPosition().x))
			if (isTheSame(s.getPosition().y, segment.getPosition().y))
				return true;
	}

	return false;
}

sf::Vector2f SnakeSegment::getPosition()
{
	return segment.getPosition();
}
