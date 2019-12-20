#include "CollisionHandler.h"

CollisionHandler::CollisionHandler(PositionHandler*& posHand)
{
	this->posHand = posHand;
}

int CollisionHandler::checkBallCollision(Ball*& collisionBall, Ball**& target, int& nrOf)
{
	int collided = -1;
	for (int i = 0; i < nrOf; i++)
	{
		if (target[i]->getBounds().intersects(collisionBall->getBounds()))
		{
			collided = i;
		}
	}
	return collided;
}

void CollisionHandler::insertBall(Ball*& collidedBall, Ball**& target, int& nrOf, int collidedIndex)
{
	bool done = false;

	for (int i = collidedIndex; i >= 0; i--)
	{
		target[i]->collisionMove();

	}
	Ball* temp = nullptr;

	for (int i = collidedIndex + 1; i < nrOf ; i++)
	{

		temp = target[i + 1];
	
		target[i + 1] = target[collidedIndex + 1];
		target[collidedIndex + 1] = temp;
		
	}

	//target[collidedIndex] = nullptr;
	//collidedBall->resetMovingSpeed();
	collidedBall->setMovingSpeed(target[collidedIndex]->getMovingSpeed());
	collidedBall->setNewDest(target[collidedIndex]->getCurrentDest());
	collidedBall->setReachedDests(target[collidedIndex]->getReachedDests());
	collidedBall->setPosition(target[collidedIndex]->getPosition());
	target[collidedIndex +1 ] = collidedBall;
	//target[collidedIndex]->setPosition(posHand->getCurrentPos(collidedIndex));
	//target[nrOf] = collidedBall;
	nrOf++;
	
}
