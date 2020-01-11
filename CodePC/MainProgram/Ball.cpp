#include "Ball.h"

Ball::Ball() : GameEntity("ball" + std::to_string(textureColour = rand() % 5) + ".png")
{
	this->reachedDests = 0;
	this->currentDest = sf::Vector2f(0, 0);
	this->lerpMod = 0.01f;
	this->movingSpeed = 5;
	this->xSpeed = 0;
	this->ySpeed = 0;
	this->reachedCurrentDest = false;
}

void Ball::setNewDest(sf::Vector2f newDest)
{
	currentDest = newDest;
	this->reachedCurrentDest = false;
}

sf::Vector2f Ball::lerp(sf::Vector2f& pointA, sf::Vector2f& pointB, float factor)
{
	return pointA + (pointB - pointA) * factor;
}

int Ball::getReachedDests() const
{
	return this->reachedDests;
}

sf::Vector2f Ball::getCurrentDest() const
{
	return this->currentDest;
}

void Ball::setReachedDests(int dests)
{
	this->reachedDests = dests;
}

void Ball::setLastPos()
{
	this->lastPos = getPosition();
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



void Ball::collisionSetPos(sf::Vector2f newPos)
{
	setLastPos();
	setPosition(newPos);
	if (getPosition().x != lastPos.x && this->xSpeed == 0)
	{
		this->reachedDests++;
		this->reachedCurrentDest = true;
	}
	else if (getPosition().y != lastPos.y && this->ySpeed ==0)
	{

		this->reachedDests++;
		this->reachedCurrentDest = true;
	}
	//if (lastPos.x > this->currentDest.x && this->xSpeed == 0)
	//{
	//	this->reachedDests++;
	//	this->reachedCurrentDest = true;
	//}
	//else if (lastPos.x < this->currentDest.x && this->xSpeed == 0)
	//{
	//	this->reachedDests++;
	//	this->reachedCurrentDest = true;
	//}
	//else if (lastPos.y > this->currentDest.y && this->ySpeed == 0)
	//{
	//	this->reachedDests++;
	//	this->reachedCurrentDest = true;
	//}
	//else if (lastPos.y < this->currentDest.y && this->ySpeed == 0)
	//{
	//	this->reachedDests++;
	//	this->reachedCurrentDest = true;
	//}
}

void Ball::moveTowardsDest()
{
	this->xSpeed = this->movingSpeed;
	this->ySpeed = this->movingSpeed;
	if (getPosition().x == this->currentDest.x)
	{
		this->xSpeed = 0;
	}
	else if (getPosition().x > this->currentDest.x)
	{
		this->xSpeed = -this->movingSpeed;
	}
	if (getPosition().y == this->currentDest.y)
	{
		this->ySpeed = 0;
	}
	else if (getPosition().y > this->currentDest.y)
	{
		this->ySpeed = -this->movingSpeed;
	}
	move(this->xSpeed, this->ySpeed);
	if (getPosition() == this->currentDest)
	{
		this->reachedDests++;
		this->reachedCurrentDest = true;
	}
}

bool Ball::reachedDest()
{
	return this->reachedCurrentDest;
}

int Ball::getMovingSpeed() const
{
	return this->movingSpeed;
}

int Ball::getColour() const
{
	return this->textureColour;
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
