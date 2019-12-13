#pragma once
#include "GameEntity.h"
class Ball :
	public GameEntity
{
private:
	int xSpeed;
	int ySpeed;
	int movingSpeed;
	int reacheadDests;
	float lerpMod;
	sf::Vector2f currentDest;
public:
	Ball(std::string texture);
	void setNewDest(sf::Vector2f newDest);
	int getReachedDests() const;
	void moveTowardsDest();
	bool reachedDest();
	virtual ~Ball();
};

