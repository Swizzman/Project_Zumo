#pragma once
#include <SFML/Graphics.hpp>
class UIHand
{
private:
	sf::Font font;
	sf::Text text;
	int width;
	int height;
public:
	UIHand();
	UIHand(int width, int height);
	void setGameOver();
	void setSize(int width, int height);
	sf::Text getText() const;
	virtual ~UIHand();
};

