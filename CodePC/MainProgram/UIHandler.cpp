#include "UIHandler.h"

UIHandler::UIHandler()
{
	this->font.loadFromFile("C:/Windows/fonts/arial.ttf");
	this->text.setFont(this->font);
	this->text.setCharacterSize(12);
	this->text.setFillColor(sf::Color::Green);
}

sf::Text UIHandler::getText() const
{
	return text;
}

void UIHandler::changeText(std::string newText)
{
	this->text.setString(newText);
}

void UIHandler::setCharacterSize(int size)
{
	this->text.setCharacterSize(size);
}

void UIHandler::setTextPosition(sf::Vector2f newPos)
{
	this->text.setPosition(newPos);
}

sf::Vector2f UIHandler::getTextSize() const
{
	return sf::Vector2f(text.getGlobalBounds().width,text.getGlobalBounds().height);
}

UIHandler::~UIHandler()
{
}
