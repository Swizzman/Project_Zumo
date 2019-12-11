#include "Game.h"

Game::Game()
{
	player = new Player("player.jpg");
}

Game::~Game()
{
}



void Game::run()
{
	while (window.isOpen())
	{
		update();
		render();
	}
}

State Game::update()
{
	return State();
}

void Game::render()
{
	window.clear();
	window.display();
}

