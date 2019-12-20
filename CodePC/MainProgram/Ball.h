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
	int textureColour;
	float lerpMod;
	sf::Vector2f currentDest;
public:
	Ball();
	void setNewDest(sf::Vector2f newDest);
	sf::Vector2f lerp(sf::Vector2f& pointA, sf::Vector2f& pointB, float factor = 0.01);
	int getReachedDests() const;
	sf::Vector2f getCurrentDest() const;
	void setReachedDests(int dests);
	void collisionMove();
	void moveTowardsDest();
	bool reachedDest();
	int getMovingSpeed() const;
	void setMovingSpeed(int newSpeed);
	int getXSpeed() const;
	int getYSpeed() const;
	virtual ~Ball();
};

