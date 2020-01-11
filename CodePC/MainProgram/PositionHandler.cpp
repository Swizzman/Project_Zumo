#include "PositionHandler.h"

PositionHandler::PositionHandler()
{
	destPos[0] = sf::Vector2f(600,0);
	destPos[1] = sf::Vector2f(600, 600);
	destPos[2] = sf::Vector2f(800, 600);
	destPos[3] = sf::Vector2f(800, 800);
	destPos[4] = sf::Vector2f(1500, 800);
	destPos[5] = sf::Vector2f(1500, 200);
	destPos[6] = sf::Vector2f(1700, 200);
	destPos[7] = sf::Vector2f(1700, 900);
	destPos[8] = sf::Vector2f(100, 900);
	destPos[9] = sf::Vector2f(100, 150);
	endDest = 10;
}

sf::Vector2f PositionHandler::getDestPos(int index)
{
	return destPos[index];
}

void PositionHandler::setCurrentPos(int index, sf::Vector2f newPos)
{
	currentPos[index] = newPos;
}

sf::Vector2f PositionHandler::getCurrentPos(int index)
{
	return currentPos[index];
}

PositionHandler::~PositionHandler()
{
}

int PositionHandler::getEndDest() const
{
	return endDest;
}
