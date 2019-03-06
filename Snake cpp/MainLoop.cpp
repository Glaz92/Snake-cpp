#include "MainLoop.h"
#include "Window.h"
#include "ConstElements.h"

MainLoop::MainLoop()
	: border(sf::Vector2f(gameBoardWidth*snakeSegmentSize,gameBoardHeight*snakeSegmentSize))
{
	border.setOutlineThickness(snakeSegmentSize);
	border.setOutlineColor(gameBoardBorderColor);
	border.setFillColor(gameBoardFillColor);

	border.setPosition(snakeSegmentSize, snakeSegmentSize);
}


MainLoop::~MainLoop()
{
}

void MainLoop::mainLoop()
{
	while (GetWindow().isOpen())
	{
		sf::Event event;
		while (GetWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				GetWindow().close();
		}

		GetWindow().clear(backgroundColor);
		draw();
		GetWindow().display();
	}
}

void MainLoop::draw()
{
	GetWindow().draw(border);
}
