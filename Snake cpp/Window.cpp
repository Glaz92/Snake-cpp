#include "Window.h"
#include "ConstElements.h"

Window::Window()
	: window(sf::VideoMode(snakeSegmentSize * 2 + snakeSegmentSize * gameBoardWidth, snakeSegmentSize * 2 + snakeSegmentSize * gameBoardHeight, 32), 
		     "Tetris", 
		     sf::Style::Default)
{
}

Window::~Window()
{
}

sf::RenderWindow & Window::get()
{
	static Window w;

	return w.window;
}
