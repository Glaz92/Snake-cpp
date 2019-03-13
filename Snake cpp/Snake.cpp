#include "Snake.h"
#include "ConstElements.h"

Snake::Snake()
	: snake{ SnakeSegment(sf::Vector2f(snakeSegmentSize * 8, snakeSegmentSize * 10)),
			 SnakeSegment(sf::Vector2f(snakeSegmentSize * 9, snakeSegmentSize * 10)), 
			 SnakeSegment(sf::Vector2f(snakeSegmentSize * 10, snakeSegmentSize * 10))},
	dir(Direction::Left),
	dirChanged(false),
	grow(false),
	snakeIsDead(false)
{
}

Snake::~Snake()
{
}

void Snake::move()
{
	dirChanged = false;
	sf::Vector2f position = snake.front().getPosition();

	switch (dir)
	{
	case Direction::Up:
		position += sf::Vector2f(0,-snakeSegmentSize);
		break;
	case Direction::Down:
		position += sf::Vector2f(0, snakeSegmentSize);
		break;
	case Direction::Left:
		position += sf::Vector2f(-snakeSegmentSize,0);
		break;
	case Direction::Right:
		position += sf::Vector2f(snakeSegmentSize, 0);
		break;
	}

	SnakeSegment newSegment(position);

	if (grow) grow = false; 
	else snake.pop_back();

	if (newSegment.checkCollision(snake))
		snakeIsDead = true;
	snake.push_front(newSegment);
}

void Snake::draw()
{
	for (auto s : snake)
	{
		s.draw();
	}
}

void Snake::setDirection(Direction newDir)
{
	if (dirChanged) return;

	switch (newDir)
	{
	case Direction::Up:
		if (dir == Direction::Down || dir == Direction::Up) return;
		break;
	case Direction::Down:
		if (dir == Direction::Up || dir == Direction::Down) return;
		break;
	case Direction::Left:
		if (dir == Direction::Right || dir == Direction::Left) return;
		break;
	case Direction::Right:
		if (dir == Direction::Left || dir == Direction::Right) return;
		break;
	}

	dir = newDir;
	dirChanged = true;
}

bool Snake::eatApple(Apple & apple)
{
	if (apple.isEaten(snake.front()))
	{
		apple.setNewPosition(snake);
		grow = true;
	}

	return grow;
}

bool Snake::isDead()
{
	return snakeIsDead;
}
