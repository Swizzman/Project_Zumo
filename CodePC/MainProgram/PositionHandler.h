#pragma once
#include <SFML/Graphics.hpp>
class PositionHandler
{
private:
	static const int CAPACITY2 = 60;
	static const int CAPACITY = 10;
	int endDest;
	sf::Vector2f destPos[CAPACITY];
	sf::Vector2f currentPos[CAPACITY2];
public:
	PositionHandler();
	sf::Vector2f getDestPos(int index);
	void setCurrentPos(int index, sf::Vector2f newPos);
	sf::Vector2f getCurrentPos(int index);
	virtual ~PositionHandler();
	int getEndDest() const;

};

