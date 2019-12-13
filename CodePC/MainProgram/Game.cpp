#include "Game.h"

Game::Game()
{
	this->capacity = 20;
	this->nrOfBalls = 0;
	player = new Player("player.png");
	ballArr = new Ball * [capacity] {nullptr};
	for (int i = 0; i < capacity; i++)
	{
		ballArr[i] = new Ball("Ball.png");
		nrOfBalls++;
		ballArr[i]->setNewDest(posHand.getDestPos(ballArr[i]->getReachedDests()));
	}
	player->setPosition(WIDTH / 2, HEIGHT / 2);
	elapsedTimeSinceLastUpdate = sf::Time::Zero;
	timePerFrame = sf::seconds(1 / 60.f);
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
	State state = State::NO_CHANGE;

	while (window.isOpen())
	{
		elapsedTimeSinceLastUpdate += clock.restart();

		while (elapsedTimeSinceLastUpdate > timePerFrame)
		{
			elapsedTimeSinceLastUpdate -= timePerFrame;

			if (player->getLives() <= 0)
			{
				state = State::HIGHSCORE;
			}
			else
			{
				state = State::NO_CHANGE;
			}
			player->rotate(window);
			for (int i = 0; i < nrOfBalls; i++)
			{

				if (ballArr[i]->reachedDest())
				{
					ballArr[i]->setNewDest(posHand.getDestPos(ballArr[i]->getReachedDests()));
				}
				ballArr[i]->moveTowardsDest();
			}
			render();
		}
	}
	return state;
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

