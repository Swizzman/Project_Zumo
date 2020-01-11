#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class UIHandler
{
private:
	sf::Font font;
	sf::Text text;
public:
	UIHandler();
	sf::Text getText() const;
	void changeText(std::string newText);
	void setCharacterSize(int size);
	void setTextPosition(sf::Vector2f newPos);
	sf::Vector2f getTextSize() const;
	virtual ~UIHandler();
};

