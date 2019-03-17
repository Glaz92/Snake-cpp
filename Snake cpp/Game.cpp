#include "Game.h"
#include "ConstElements.h"
#include "Window.h"

Game::Game()
	: gameSpeed(gameSpeedStart), score(0), pause(false), gameOver(false),
	  frame(sf::Vector2f(150,100)), pauseTxt("Pause", GetFont(), 30), gameOverTxt("Game Over", GetFont(), 25)
{
	frame.setOutlineThickness(snakeSegmentSize / 2);
	frame.setOutlineColor(gameBoardBorderColor);
	frame.setFillColor(gameBoardFillColor);
	frame.setOrigin(75,50);
	frame.setPosition(snakeSegmentSize + snakeSegmentSize * gameBoardWidth / 2, snakeSegmentSize + snakeSegmentSize * gameBoardHeight / 2);

	pauseTxt.setPosition(frame.getGlobalBounds().left + 45, frame.getGlobalBounds().top + 35);
	pauseTxt.setFillColor(sf::Color::Black);

	gameOverTxt.setPosition(frame.getGlobalBounds().left + 20, frame.getGlobalBounds().top + 20);
	gameOverTxt.setFillColor(sf::Color::Black);
}

Game::~Game()
{
}

void Game::run()
{
	control();
	if(!pause && !gameOver) logic();
	draw();
}

void Game::draw()
{
	snake.draw();
	apple.draw();
	if (pause || gameOver) GetWindow().draw(frame);
	if (pause) GetWindow().draw(pauseTxt);
	if (gameOver) GetWindow().draw(gameOverTxt);
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

	if (snake.isDead())
	{
		gameOver = true;
		gameOverTxt.setString("Game over\nscore:" + std::to_string(score));
	}
}

void Game::control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::P));

		pause = pause ? false : true;
	}

	if (!pause)
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
}
