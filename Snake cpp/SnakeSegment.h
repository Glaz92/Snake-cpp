#pragma once
#include <SFML/Graphics.hpp>
#include <deque>

class SnakeSegment
{
protected:
	sf::RectangleShape segment;

public:
	SnakeSegment();
	SnakeSegment(sf::Vector2f position);
	~SnakeSegment();

public:
	void draw();
	bool checkCollision(std::deque<SnakeSegment> & segments);

	sf::Vector2f getPosition();
};