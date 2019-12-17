#pragma once
#include "Ball.h"
class CollisionHandler
{
private:
public:
	int checkBallCollision(Ball &collidedBall, Ball **&target, int nrOf);
};

