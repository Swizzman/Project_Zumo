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
	this->nrOfDeathBalls = 0;
	this->moving = false;
	this->capacity = 50;
	this->nrOfBalls = 0;
	this->collidedI = 0;
	this->mousePos = sf::Vector2f(0, 0);
	this->playerCollided = false;
	posHand = new PositionHandler();
	player = new Player(WIDTH, HEIGHT);
	ballArr = new Ball * [capacity] {nullptr};
	deathArr = new Ball * [capacity] {nullptr};
	colHand = new CollisionHandler(posHand);
	livesText.setTextPosition(sf::Vector2f(1700, 100));
	livesText.setCharacterSize(30);
	scoreText.setTextPosition(sf::Vector2f(1700, 150));
	scoreText.setCharacterSize(30);
	for (int i = 0; i < 50; i++)
	{
		ballArr[i] = new Ball();
		if (i != 0)
		{
			ballArr[i]->setPosition(ballArr[i - 1]->getPosition().x - 45, 0);
		}
		ballArr[i]->setNewDest(posHand->getDestPos(ballArr[i]->getReachedDests()));
		nrOfBalls++;
	}
	playerBall = new Ball();
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
	for (int i = 0; i < nrOfDeathBalls; i++)
	{
		delete deathArr[i];

	}
	delete playerBall;
	delete player;
	delete posHand;
	delete colHand;
	delete[] ballArr;
	delete[] deathArr;
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
				currentScoreOut.open("../datafiles/currentscore.txt");
				currentScoreOut << player->getScore();
				currentScoreOut.close();
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
						player->increaseScore(40 * colHand->colourCheck(ballArr, nrOfBalls, collidedI));
						playerCollided = true;
						moving = false;
						playerBall = new Ball();
						player->recieveBall(playerBall);
						soundHand.collision();


					}
				}
				if (moving && (playerBall->getPosition().x > WIDTH || 
					playerBall->getPosition().x < 0 ||
					playerBall->getPosition().y > HEIGHT || 
					playerBall->getPosition().y < 0 ))
				{
					delete playerBall;
					playerBall = new Ball();
					player->recieveBall(playerBall);
					moving = false;
				}
				for (int i = 0; i < nrOfBalls; i++)
				{
					
					ballArr[i]->moveTowardsDest();
					if (ballArr[i]->checkReached())
					{
						ballArr[i]->increaseReachedDests();
						if (ballArr[i]->getReachedDests() == posHand->getEndDest())
						{
							deathArr[nrOfDeathBalls++] = ballArr[i];
							nrOfBalls--;
							for (int y = i; y < nrOfBalls; y++)
							{
								ballArr[y] = ballArr[y + 1];
							}

							player->decreaseLives();
						}
						else
						{
							ballArr[i]->setNewDest(posHand->getDestPos(ballArr[i]->getReachedDests()));
						}
					}

					posHand->setCurrentPos(i, ballArr[i]->getPosition());
				}
				livesText.changeText("Lives: " + std::to_string(player->getLives()));
				scoreText.changeText("Score: " + std::to_string(player->getScore()));
			}
			else
			{
				state = State::GAME_OVER;
				currentScoreOut.open("../datafiles/currentscore.txt");
				currentScoreOut << player->getScore();
				currentScoreOut.close();
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
	window.draw(livesText.getText());
	window.draw(scoreText.getText());
	window.display();
}

