#pragma once
#include "GameEntity.h"
#include "Ball.h"
#include <cmath>
class Player :
	public GameEntity
{
private:
	Ball* shootBall;
	int lives;
	sf::Mouse mouse;
	sf::Vector2f offset;

public:
	Player(std::string texture);
	int getLives() const;
	void recieveBall(Ball* ballPtr);
	void releaseBall();
	bool shoot();
	void rotate(sf::RenderWindow& window);

};

