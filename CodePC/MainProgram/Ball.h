#pragma once
#include "GameEntity.h"
class Ball :
	public GameEntity
{
private:
	int textureColour;
	int xSpeed;
	int ySpeed;
	int movingSpeed;
	int reachedDests;
	sf::Vector2f currentDest;
	sf::Vector2f lastPos;
	bool reachedCurrentDest;
	void setLastPos();
public:
	Ball();
	void setNewDest(sf::Vector2f newDest);
	int getReachedDests() const;
	sf::Vector2f getCurrentDest() const;
	void increaseReachedDests();
	void setReachedDests(int reached);
	void collisionMove();
	void collisionSetPos(sf::Vector2f newPos);
	bool checkCollision(const Ball& other);
	void getAttrOfOtherBall(const Ball& other);
	bool checkReached();
	int getMovingSpeed() const;
	void setMovingSpeed(int newSpeed);
	int getColour() const;
	int getXSpeed() const;
	int getYSpeed() const;
	virtual ~Ball();

	// Inherited via GameEntity
	virtual void moveSpecific() override;
};

