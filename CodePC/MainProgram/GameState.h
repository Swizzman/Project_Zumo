#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class GameState
{
protected:
	const int WIDTH = 1000;
	const int HEIGHT = 1000;
	sf::RenderWindow window;
public:
	GameState();
	virtual void run() = 0;
	virtual State update() = 0;
	virtual void render() = 0;
	virtual ~GameState();
};

