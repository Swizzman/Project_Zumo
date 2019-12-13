#pragma once
#include <SFML/Graphics.hpp>
class PositionHandler
{
private:
	static const int CAPACITY = 10;
	sf::Vector2f destPos[CAPACITY];
public:
	PositionHandler();
	sf::Vector2f getDestPos(int index);
	virtual ~PositionHandler();

};

