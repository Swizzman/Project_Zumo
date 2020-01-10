#include "UIHand.h"

UIHand::UIHand()
{
	this->width = 0;
	this->height = 0;
	font.loadFromFile("C:/Windows/fonts/arial.ttf");
	text.setFont(font);
}

UIHand::UIHand(int width, int height)
{
	this->width = width;
	this->height = height;
	font.loadFromFile("C:/Windows/fonts/arial.ttf");
	text.setFont(font);

}

void UIHand::setGameOver()
{
	text.setString("Game Over!");
	text.setPosition(width / 2, height / 2);
	text.setFillColor(sf::Color::Green);
	text.setCharacterSize(30);
}

void UIHand::setSize(int width, int height)
{
	this->width = width;
	this->height = height;
}

sf::Text UIHand::getText() const
{
	return text;
}

UIHand::~UIHand()
{
}
