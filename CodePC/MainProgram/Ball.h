#pragma once
#include "GameEntity.h"
class Ball :
	public GameEntity
{
private:
public:
	Ball(std::string texture);
	virtual ~Ball();
};

