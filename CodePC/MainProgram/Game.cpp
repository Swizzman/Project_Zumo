#include "Game.h"

Game::Game()
{
	this->lerpTemp = false;
	this->capacity = 20;
	this->nrOfBalls = 0;
	this->mousePos = sf::Vector2f(0, 0);
	player = new Player(WIDTH, HEIGHT);
	ballArr = new Ball * [capacity] {nullptr};
	for (int i = 0; i < capacity; i++)
	{
		ballArr[i] = new Ball("Ball.png");
		nrOfBalls++;
		ballArr[i]->setNewDest(posHand.getDestPos(ballArr[i]->getReachedDests()));
		if (i != 0)
		{
			ballArr[i]->setPosition(ballArr[i - 1]->getPosition().x - 20, 0);
		}

	}
	playerBall = new Ball("ball.png");
	//player->setPosition(WIDTH / 2, HEIGHT / 2);
	player->recieveBall(playerBall);
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


			player->rotate(window);
			if (player->shoot())
			{
				mousePos = player->getMousePos();
				lerpTemp = true;
			}
			if (lerpTemp)
			{
				playerBall->setPosition(playerBall->lerp(playerBall->getPosition(), mousePos, 0.1));
				if (colHand.checkBallCollision(*playerBall, ballArr, nrOfBalls) != -1)
				{

					nrOfBalls++;
				}
			}
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

void Game::handleEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void Game::render()
{
	window.clear();
	window.draw(*player);
	for (int i = 0; i < nrOfBalls; i++)
	{
		window.draw(*this->ballArr[i]);
	}
	window.draw(*playerBall);
	window.display();
}

