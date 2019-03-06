#include "Window.h"

Window::Window()
	: window(sf::VideoMode(800, 600, 32), "Tetris", sf::Style::Default)
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
