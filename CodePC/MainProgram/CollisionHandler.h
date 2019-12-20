#pragma once
#include "Ball.h"
#include "PositionHandler.h"
class CollisionHandler
{
private:
	PositionHandler* posHand;
public:
	CollisionHandler(PositionHandler *&posHand);
	int checkBallCollision(Ball *&collidedBall, Ball **&target, int &nrOf);
	void insertBall(Ball*& collidedBall, Ball**& target, int &nrOf, int collidedIndex);
};

