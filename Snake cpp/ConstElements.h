#pragma once
#include <SFML/Graphics.hpp>

constexpr int gameBoardWidth = 20;
constexpr int gameBoardHeight = 20;
constexpr int snakeSegmentSize = 20;

const auto gameBoardBorderColor = sf::Color::Black;
const auto gameBoardFillColor = sf::Color::White;
const auto backgroundColor = sf::Color::White;

const auto snakeFillColor = sf::Color::Red;
const auto snakeOutlineColor = sf::Color::Black;

class Font
{
private:
	sf::Font font;

private:
	Font()
	{
		font.loadFromFile("data/font/font.ttf");
	}

	~Font() {}

public:
	static sf::Font & getFont()
	{
		static Font font;

		return font.font;
	}
};

constexpr auto GetFont = Font::getFont;