#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
class Game
{
private:
	sf::Window* window;
	Player player;
public:
	virtual ~Game();
	void initialize();
	void update();
};

