#pragma once
#include "GameEntity.h"
class Player :
	public GameEntity
{
private:
public:
	Player();
	// Inherited via GameEntity
	virtual void move() override;
};

