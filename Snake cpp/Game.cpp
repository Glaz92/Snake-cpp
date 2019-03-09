#include "Game.h"

Game::Game()
	: gameSpeed(gameSpeedStart), score(0)
{
}

Game::~Game()
{
}

void Game::run()
{
	control();
	logic();
	draw();
}

void Game::draw()
{
	snake.draw();
	apple.draw();
}

void Game::logic()
{
	time = clock.getElapsedTime();

	if (time.asMilliseconds() > gameSpeed)
	{
		snake.move();
		clock.restart();

		if (snake.eatApple(apple))
		{
			score += 100;
			gameSpeed = gameSpeedStart - score / 100 * 25;
			gameSpeed = gameSpeed < 100 ? 100 : gameSpeed;
		}
	}
}

void Game::control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		snake.setDirection(Direction::Left);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		snake.setDirection(Direction::Right);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		snake.setDirection(Direction::Up);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		snake.setDirection(Direction::Down);
	}
}
