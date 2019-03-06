#pragma once
#include <SFML/Graphics.hpp>

class MainLoop
{
private:
	sf::RectangleShape border;

public:
	MainLoop();
	~MainLoop();

public:
	void mainLoop();

private:
	void draw();
};

