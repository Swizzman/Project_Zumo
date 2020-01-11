#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
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
	PositionHandler* posHand;
	CollisionHandler* colHand;
	SoundHandler soundHand;
	UIHandler uIHand;
	int animTime;
	int animUpdateTime;
	int nrOfBalls;
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
	void startAnim();
public:
	Game();
	virtual ~Game();


	// Inherited via GameState
	virtual void render() override;
 
	// Inherited via GameState
	virtual void run() override;
	virtual State update() override;

	// Inherited via GameState
	virtual void handleEvents() override;
};

