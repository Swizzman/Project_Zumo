#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include "Player.h"
#include "Ball.h"
#include "GameState.h"
#include "State.h"
#include "PositionHandler.h"
#include "CollisionHandler.h"
#include "SoundHandler.h"
#include "UIHandler.h"
class Game : public GameState
{
private:
	Player* player;
	Ball* playerBall;
	Ball** ballArr;
	Ball** deathArr;
	PositionHandler* posHand;
	CollisionHandler* colHand;
	SoundHandler soundHand;
	UIHandler livesText;
	UIHandler scoreText;
	std::ofstream currentScoreOut;
	int nrOfBalls;
	int nrOfDeathBalls;
	int capacity;
	bool moving;
	bool playerCollided;
	int collidedI;
	sf::Vector2f mousePos;
	sf::Vector2f dir;
	sf::Clock clock;
	sf::Time timePerFrame;
	sf::Time elapsedTimeSinceLastUpdate;
	void expand();
public:
	Game();
	virtual ~Game();


	// Inherited via GameState
	virtual void render() override;
 
	// Inherited via GameState
	virtual State update() override;

	// Inherited via GameState
	virtual void handleEvents() override;
};

