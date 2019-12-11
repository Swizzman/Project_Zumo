#pragma once
#include "State.h"
#include <SFML/Window.hpp>
class GameState
{
protected:
	sf::Window window;
public:
	GameState();
	virtual void run() = 0;
	virtual State update() = 0;
	virtual void render() = 0;
	virtual ~GameState();
};

