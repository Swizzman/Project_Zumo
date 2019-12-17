#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include <iostream>
class MenuMode : public GameState
{
private:
	static const int CAPACITY = 3;
	const int MAX = 2;
	sf::Text gameName;
	sf::Text alternatives[CAPACITY];
	sf::Font font;
	int currentSelection;
	bool done;
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

