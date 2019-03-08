#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

class MainLoop
{
private:
	sf::RectangleShape border;
	Game game;

public:
	MainLoop();
	~MainLoop();

public:
	void mainLoop();

private:
	void draw();
};

