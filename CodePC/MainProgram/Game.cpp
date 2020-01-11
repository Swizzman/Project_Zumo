#include "Game.h"

void Game::expand()
{
	capacity += 10;
	Ball** temp = new Ball * [capacity] {nullptr};
	for (int i = 0; i < nrOfBalls; i++)
	{
		temp[i] = this->ballArr[i];
	}
	delete[] ballArr;
	ballArr = temp;
	temp = nullptr;
}

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
	uIHand.setTextPosition(sf::Vector2f(1700, 100));
	uIHand.setCharacterSize(30);
	for (int i = 0; i < 20; i++)
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
	delete playerBall;
	delete player;
	delete posHand;
	delete colHand;
	delete[] ballArr;
}



void Game::run()
{

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

			if (nrOfBalls <= 0 && player->getLives() > 0)
			{
				state = State::GAME_WON;
			}
			else if (player->getLives() > 0)
			{
				player->rotate(window);
				if (player->shoot() && !moving)
				{
					sf::Vector2f dist = (sf::Vector2f)player->getMousePos() - player->getPosition();
					float magni = sqrt(pow(dist.x, 2) + pow(dist.y, 2));
					dir = sf::Vector2f(dist.x / magni, dist.y / magni);
					moving = true;
					playerCollided = false;
					soundHand.shoot();
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
						playerBall = new Ball();
						player->recieveBall(playerBall);
						soundHand.collision();


					}
				}
				for (int i = 0; i < nrOfBalls; i++)
				{
					if (ballArr[i]->reachedDest())
					{
						if (ballArr[i]->getReachedDests() == posHand->getEndDest())
						{
							delete ballArr[i];
							nrOfBalls--;
							for (int i = 0; i < nrOfBalls; i++)
							{
								ballArr[i] = ballArr[i + 1];
							}

							player->decreaseLives();
						}
						else
						{
							ballArr[i]->setNewDest(posHand->getDestPos(ballArr[i]->getReachedDests()));
						}
					}
					ballArr[i]->moveTowardsDest();

					posHand->setCurrentPos(i, ballArr[i]->getPosition());
				}
				uIHand.changeText("Lives: " + std::to_string(player->getLives()));

			}
			else
			{
				state = State::GAME_OVER;
				std::cout << player->getLives() << std::endl;
			}
			if (nrOfBalls == capacity)
			{
				expand();
			}
			render();
		}
		return state;
	}
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
	window.draw(uIHand.getText());
	window.display();
}

