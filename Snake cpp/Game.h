#pragma once
#include "Snake.h"

class Game
{
private:
	Snake snake;
	sf::Clock clock;
	sf::Time time;
	int gameSpeed;

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

