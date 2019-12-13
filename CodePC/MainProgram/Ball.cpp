#include "Ball.h"

Ball::Ball(std::string texture) : GameEntity(texture), reacheadDests(0)
, xSpeed(0), ySpeed(0),movingSpeed(4), lerpMod(0.01)
{

}

void Ball::setNewDest(sf::Vector2f newDest)
{
	currentDest = newDest;
}

int Ball::getReachedDests() const
{
	return reacheadDests;
}

void Ball::moveTowardsDest()
{
	xSpeed = movingSpeed;
	ySpeed = movingSpeed; 
	if (getPosition().x == currentDest.x)
	{
		xSpeed = 0;
	}
	else if (getPosition().x > currentDest.x)
	{
		xSpeed = -movingSpeed;
	}
	if (getPosition().y == currentDest.y)
	{
		ySpeed = 0;
	}
	else if (getPosition().y > currentDest.y)
	{
		ySpeed = -movingSpeed;
	}
	move(xSpeed, ySpeed);
}

bool Ball::reachedDest()
{
	bool reached = false;
	if (getPosition() == currentDest)
	{
		reached = true;
		reacheadDests++;
	}
	return reached;
}

Ball::~Ball()
{
}
