#include "Ball.h"

Ball::Ball() : GameEntity("ball" + std::to_string(textureColour = rand() % 5) + ".png")
{
	this->reacheadDests = 0;
	this->currentDest = sf::Vector2f(0, 0);
	this->lerpMod = 0.01f;
	this->movingSpeed = 5;
	this->xSpeed = 0;
	this->ySpeed = 0;
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

sf::Vector2f Ball::getCurrentDest() const
{
	return this->currentDest;
}

void Ball::setReachedDests(int dests)
{
	this->reacheadDests = dests;
}

void Ball::collisionMove()
{
	if (this->xSpeed > 0)
	{
		this->setPosition(this->getPosition().x + 45, this->getPosition().y);
	}
	else if (this->xSpeed < 0)
	{
		this->setPosition(this->getPosition().x - 45, this->getPosition().y);

	}
	if (this->ySpeed > 0)
	{
		this->setPosition(this->getPosition().x, this->getPosition().y + 45);

	}
	else if (this->ySpeed < 0)
	{
		this->setPosition(this->getPosition().x, this->getPosition().y - 45);

	}
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
	else if (getPosition().y > currentDest.y&& xSpeed == 0)
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

int Ball::getMovingSpeed() const
{
	return movingSpeed;
}

void Ball::setMovingSpeed(int newSpeed)
{
	this->movingSpeed = newSpeed;
}

int Ball::getXSpeed() const
{
	return this->xSpeed;
}

int Ball::getYSpeed() const
{
	return this->ySpeed;
}

Ball::~Ball()
{
}
