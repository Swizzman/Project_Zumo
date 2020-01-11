#pragma once
#include "GameEntity.h"
class Logo :
	public GameEntity
{
private:
	sf::IntRect intRect;
public:
	Logo();
	virtual ~Logo();
	void nextFrame();
};

