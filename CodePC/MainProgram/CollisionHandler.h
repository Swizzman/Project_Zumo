#pragma once
#include "Ball.h"
#include "PositionHandler.h"
class CollisionHandler
{
private:
	PositionHandler* posHand;
	int colourBack;
	int colourForward;
	void colourDestroy(Ball** arr, int& nrOf, int collidedIndex, int forward, int back);
public:
	CollisionHandler(PositionHandler *posHand);
	int checkBallCollision(Ball *collidedBall, Ball **target, int nrOf);
	void insertBall(Ball* collidedBall, Ball** target, int &nrOf, int collidedIndex);
	int colourCheck(Ball** arr, int& nrOf, int collidedIndex);

};

