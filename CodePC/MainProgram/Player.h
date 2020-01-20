#pragma once
#include "GameEntity.h"
#include "Ball.h"
#include <cmath>
#include <iostream>;
class Player :
	public GameEntity
{
private:
	Ball* shootBall;
	int lives;
	int score;
	sf::Mouse mouse;
	sf::Vector2f offset;

public:
	Player(int xSize, int ySize);
	int getLives() const;
	int getScore() const;
	void increaseScore(int increase);
	void decreaseLives();
	void recieveBall(Ball* ballPtr);
	void releaseBall();
	bool shoot();
	void rotate(sf::RenderWindow& window);
	sf::Vector2f getMousePos() const;
	virtual ~Player();

};

