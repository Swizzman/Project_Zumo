#include "Ball.h"

Ball::Ball() : GameEntity("ball" + std::to_string(textureColour = rand() % 5) + ".png")
{
	this->reachedDests = 0;
	this->currentDest = sf::Vector2f(600, 0);
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

int Ball::getReachedDests() const
{
	return this->reachedDests;
}

sf::Vector2f Ball::getCurrentDest() const
{
	return this->currentDest;
}

void Ball::increaseReachedDests()
{
	this->reachedDests++;
}

void Ball::setReachedDests(int reached)
{
	this->reachedDests = reached;
}

void Ball::setLastPos()
{
	this->lastPos = getPosition();
}

void Ball::collisionMove()
{
	if (this->xSpeed > 0)
	{
		this->setPosition(this->getPosition().x - 45, this->getPosition().y);
	}
	else if (this->xSpeed < 0)
	{
		this->setPosition(this->getPosition().x + 45, this->getPosition().y);

	}
	if (this->ySpeed > 0)
	{
		this->setPosition(this->getPosition().x, this->getPosition().y - 45);

	}
	else if (this->ySpeed < 0)
	{
		this->setPosition(this->getPosition().x, this->getPosition().y + 45);

	}
}



void Ball::collisionSetPos(sf::Vector2f newPos)
{
	setLastPos();
	setPosition(newPos);
	if (newPos.x != lastPos.x && this->xSpeed == 0)
	{
		this->reachedCurrentDest = true;
	}
	else if (newPos.y != lastPos.y && this->ySpeed ==0)
	{

		this->reachedCurrentDest = true;
	}

}


bool Ball::checkReached()
{
	return reachedCurrentDest;
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
		this->reachedCurrentDest = true;
	}
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
