#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Player.h"
#include "Ball.h"
#include "GameState.h"
#include "State.h"
#include "PositionHandler.h"
class Game : public GameState
{
private:
	Player* player;
	Ball** ballArr;
	PositionHandler posHand;
	int nrOfBalls;
	int capacity;
	sf::Clock clock;
	sf::Time timePerFrame;
	sf::Time elapsedTimeSinceLastUpdate;

public:
	Game();
	virtual ~Game();


	// Inherited via GameState
	virtual void render() override;
 
	// Inherited via GameState
	virtual void run() override;
	virtual State update() override;
};

