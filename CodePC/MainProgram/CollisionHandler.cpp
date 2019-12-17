#include "CollisionHandler.h"

int CollisionHandler::checkBallCollision(Ball& collisionBall, Ball**& target, int nrOf)
{
	int collided = -1;
	for (int i = 0; i < nrOf; i++)
	{
		if (target[i]->getBounds().intersects(collisionBall.getBounds()))
		{

			collided = i;
		}
	}
	return collided;
}
