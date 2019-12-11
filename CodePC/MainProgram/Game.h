#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "GameState.h"
#include "State.h"
class Game : public GameState
{
private:
	Player* player;


public:
	Game();
	virtual ~Game();


	// Inherited via GameState
	virtual void render() override;

	// Inherited via GameState
	virtual void initialize() override;
	virtual State update() override;
};

