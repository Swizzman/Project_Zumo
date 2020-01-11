#include "CollisionHandler.h"

CollisionHandler::CollisionHandler(PositionHandler* posHand)
{
	this->colourBack = 0;
	this->colourForward = 0;
	this->posHand = posHand;
}

int CollisionHandler::checkBallCollision(Ball*& collisionBall, Ball**& target, int& nrOf)
{
	int collided = -1;
	for (int i = 0; i < nrOf && collided == -1; i++)
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

	collidedBall->setMovingSpeed(target[collidedIndex]->getMovingSpeed());
	collidedBall->setReachedDests(target[collidedIndex]->getReachedDests());
	collidedBall->setNewDest(target[collidedIndex]->getCurrentDest());
	collidedBall->setPosition(target[collidedIndex]->getPosition());
	for (int i = collidedIndex; i >= 0; i--)
	{
		if (i == 0)
		{
			target[i]->collisionMove();

		}
		else
		{
			target[i]->collisionSetPos(posHand->getCurrentPos(i - 1));
		}

	}

	Ball* temp = nullptr;
	Ball* temp2 = nullptr;

	temp = target[collidedIndex];
	for (int i = collidedIndex; i < nrOf; i++)
	{
		if (target[i + 1] != nullptr)
		{
			temp2 = target[i + 1];
			target[i + 1] = temp;
			temp = temp2;
		}
		else
		{
			target[i + 1] = temp;
			temp = nullptr;
			temp2 = nullptr;
		}
	}
	target[collidedIndex + 1] = collidedBall;
	nrOf++;
	colourCheck(target, nrOf, collidedIndex + 1);
}

void CollisionHandler::colourCheck(Ball**& arr, int& nrOf, int collidedIndex)
{
	bool stopBack = false;
	bool stopForward = false;
	int collidedColour = arr[collidedIndex]->getColour();

	for (int i = collidedIndex; i < nrOf && !stopBack; i++)
	{
		if (arr[i]->getColour() == collidedColour)
		{
			colourBack++;
		}
		else
		{
			stopBack = true;
		}

	}
	for (int i = collidedIndex; i >= 0 && !stopForward; i--)
	{

		if (arr[i]->getColour() == collidedColour)
		{
			colourForward++;
		}
		else
		{
			stopForward = true;
		}

	}

	colourBack--;
	colourForward--;
	std::cout << "Forward: " << colourForward << " Back: " << colourBack << std::endl;
	if (colourBack + colourForward >= 2)
	{
		colourDestroy(arr, nrOf, collidedIndex, colourForward, colourBack);
	}
	colourForward = 0;
	colourBack = 0;
}

void CollisionHandler::colourDestroy(Ball**& arr, int& nrOf, int collidedIndex, int forward, int back)
{
	int counter = 1;
	for (int i = collidedIndex; i <= collidedIndex + back; i++)
	{
		delete arr[i];
	}

	for (int i = collidedIndex - 1; i >= collidedIndex - forward; i--)
	{
		delete arr[i];
	}
	for (int i = collidedIndex - forward; i < nrOf; i++)
	{
		arr[i] = arr[collidedIndex + back + counter];
		counter++;
	}
	counter = 1;
	nrOf -= forward + back + 1;
	std::cout << nrOf << std::endl;
}
