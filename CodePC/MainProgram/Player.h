#pragma once
#include "GameEntity.h"
#include <cmath>
class Player :
	public GameEntity
{
private:
	sf::Mouse mouse;
public:
	Player(std::string texture);

	void rotate();
};

