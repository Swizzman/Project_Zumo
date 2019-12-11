#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Ball.h"
#include "GameState.h"
#include "State.h"
class Game : public GameState
{
private:
	Player* player;
	Ball** ballArr;
	int nrOfBalls;
	int capacity;


public:
	Game();
	virtual ~Game();


	// Inherited via GameState
	virtual void render() override;

	// Inherited via GameState
	virtual void run() override;
	virtual State update() override;
};

