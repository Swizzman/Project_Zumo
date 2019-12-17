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
	sf::Vector2f lerp(sf::Vector2f& pointA, sf::Vector2f& pointB, float factor = 0.01);
	int getReachedDests() const;
	void moveTowardsDest();
	bool reachedDest();
	virtual ~Ball();
};

