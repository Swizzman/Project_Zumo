#include "Game.h"

Game::Game()
{
	this->moving = false;
	this->capacity = 50;
	this->nrOfBalls = 0;
	this->collidedI = 0;
	this->mousePos = sf::Vector2f(0, 0);
	this->playerCollided = false;
	posHand = new PositionHandler();
	player = new Player(WIDTH, HEIGHT);
	ballArr = new Ball * [capacity] {nullptr};
	colHand = new CollisionHandler(posHand);
	for (int i = 0; i < 40; i++)
	{
		ballArr[i] = new Ball();
		nrOfBalls++;
		ballArr[i]->setNewDest(posHand->getDestPos(ballArr[i]->getReachedDests()));
		if (i != 0)
		{
			ballArr[i]->setPosition(ballArr[i - 1]->getPosition().x - 45, 0);
		}

	}
	playerBall = new Ball();
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
			if (player->shoot() && !moving)
			{
				sf::Vector2f dist = (sf::Vector2f)player->getMousePos() - player->getPosition();
				float magni = sqrt(pow(dist.x, 2) + pow(dist.y, 2));
				dir = sf::Vector2f(dist.x / magni, dist.y / magni);
				moving = true;
				playerCollided = false;
			}
			if (moving)
			{
				playerBall->move(dir, playerBall->getMovingSpeed());
				collidedI = colHand->checkBallCollision(playerBall, ballArr, nrOfBalls);
				if (collidedI != -1 && !playerCollided)
				{
					colHand->insertBall(playerBall, ballArr, nrOfBalls, collidedI);
					playerCollided = true;
					moving = false;
					playerBall = nullptr;
				}
			}
			for (int i = 0; i < nrOfBalls; i++)
			{

				if (ballArr[i]->reachedDest())
				{
					ballArr[i]->setNewDest(posHand->getDestPos(ballArr[i]->getReachedDests()));
				}
				ballArr[i]->moveTowardsDest();
			}
			for (int i = 0; i < nrOfBalls; i++)
			{
				posHand->setCurrentPos(i, ballArr[i]->getPosition());
				//std::cout << std::to_string((int)posHand.getCurrentPos(i).x) << ": " << std::to_string((int)posHand.getCurrentPos(i).y) << std::endl;
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
	if (playerBall != nullptr)
	{

	window.draw(*playerBall);
	}
	window.display();
}

