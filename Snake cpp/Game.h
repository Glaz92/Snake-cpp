#pragma once
#include "Snake.h"
#include "Apple.h"

constexpr int gameSpeedStart = 350;

class Game
{
private:
	Snake snake;
	Apple apple;

	sf::Clock clock;
	sf::Time time;
	int gameSpeed;
	int score;

public:
	Game();
	~Game();

public:
	void run();

private:
	void draw();
	void logic();
	void control();
};

