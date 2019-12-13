#pragma once
#include "Ball.h"
class CollisionHandler
{
private:
public:
	bool checkBallCollision(Ball &collidedBall, Ball *& target);
};

