#include "Game.h"

Game::Game()
{
	this->capacity = 20;
	this->nrOfBalls = 0;
	player = new Player("player.png");
	ballArr = new Ball*();
	for (int i = 0; i < capacity; i++)
	{
		ballArr[i] = new Ball("Ball.png");
		nrOfBalls++;
	}
}

Game::~Game()
{
	for (int i = 0; i < nrOfBalls; i++)
	{
		delete ballArr[i];
	}
	delete[] ballArr;
	delete player;
}



void Game::run()
{

		update();
		render();
	
}

State Game::update()
{
	return State();
}

void Game::render()
{
	window.clear();
	window.draw(*player);
	for (int i = 0; i < nrOfBalls; i++)
	{
		window.draw(*this->ballArr[i]);
	}
	window.display();
}

