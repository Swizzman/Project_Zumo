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
	bool ballMoving;
	sf::Mouse mouse;
	sf::Vector2f offset;
	sf::Vector2f dir;

public:
	Player(int xSize, int ySize);
	int getLives() const;
	int getScore() const;
	void setDirection(); 
	void increaseScore(int increase);
	void decreaseLives();
	void receiveBall(Ball* ballPtr);
	void releaseBall();
	bool shoot();
	void rotate(sf::RenderWindow& window);
	sf::Vector2f getMousePos() const;
	virtual ~Player();


	// Inherited via GameEntity
	virtual void moveSpecific() override;

};

