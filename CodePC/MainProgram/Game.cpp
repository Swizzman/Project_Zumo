#include "Game.h"

Game::Game()
{
	this->capacity = 20;
	this->nrOfBalls = 0;
	gameRunning = true;
	player = new Player("player.png");
	ballArr = new Ball * [capacity] {nullptr};
	for (int i = 0; i < capacity; i++)
	{
		ballArr[i] = new Ball("Ball.png");
		nrOfBalls++;
	}
	player->setPosition(WIDTH / 2, HEIGHT / 2);
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
	while (window.isOpen())
	{
		player->rotate();
		std::cout << player->getRotation() << std::endl;
		render();
	}
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

