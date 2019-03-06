#pragma once
#include <SFML/Graphics.hpp>

class Window
{
private:
	sf::RenderWindow window;

public:
	Window();
	~Window();

public:
	static sf::RenderWindow & get();
};

constexpr auto GetWindow = Window::get;