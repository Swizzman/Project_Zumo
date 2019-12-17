#include "Ball.h"

Ball::Ball(std::string texture) : GameEntity(texture), reacheadDests(0)
, xSpeed(0), ySpeed(0),movingSpeed(2), lerpMod(0.01)
{

}

void Ball::setNewDest(sf::Vector2f newDest)
{
	currentDest = newDest;
}

sf::Vector2f Ball::lerp(sf::Vector2f& pointA, sf::Vector2f& pointB, float factor)
{
	return pointA + (pointB - pointA) * factor;
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
