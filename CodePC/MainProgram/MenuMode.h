#pragma once
#include <SFML/Graphics.hpp>
#include "Logo.h"
#include "GameState.h"
#include <iostream>
class MenuMode : public GameState
{
private:
	static const int CAPACITY = 3;
	const int MAX = 2;
	sf::Text alternatives[CAPACITY];
	sf::Font font;
	Logo logo;
	sf::Time timePerFrame;
	sf::Time elapsedTimeSinceLastUpdate;
	sf::Clock clock;
	int currentSelection;
	bool done;	
	int timeCounter;
	int updateTime;
public:
	MenuMode();
	virtual ~MenuMode();
	void moveUp();
	void moveDown();

	// Inherited via GameState
	virtual void run() override;

	virtual void handleEvents() override;

	virtual State update() override;

	virtual void render() override;

};

