#include "PositionHandler.h"

PositionHandler::PositionHandler()
{
	destPos[0] = sf::Vector2f(400,400);
	destPos[1] = sf::Vector2f(600, 400);
	destPos[2] = sf::Vector2f(0, 400);
	destPos[3] = sf::Vector2f(0, 400);
	destPos[4] = sf::Vector2f(600, 400);
	destPos[5] = sf::Vector2f(600, 400);
	destPos[6] = sf::Vector2f(0, 400);
	destPos[7] = sf::Vector2f(600, 400);
	destPos[8] = sf::Vector2f(0, 400);
	destPos[9] = sf::Vector2f(600, 400);
}

sf::Vector2f PositionHandler::getDestPos(int index)
{
	return destPos[index];
}

PositionHandler::~PositionHandler()
{
}
