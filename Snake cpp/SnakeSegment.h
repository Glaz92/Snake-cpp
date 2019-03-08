#pragma once
#include <SFML/Graphics.hpp>
#include <deque>

class SnakeSegment
{
private:
	sf::RectangleShape segment;

public:
	SnakeSegment(sf::Vector2f position);
	~SnakeSegment();

public:
	void draw();
	bool checkCollision(std::deque<SnakeSegment> & segments);

	sf::Vector2f getPosition();
};