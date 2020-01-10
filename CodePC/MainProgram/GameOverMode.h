#pragma once
#include "State.h"
#include "GameState.h"
#include "UIHand.h"
class GameOverMode : public GameState
{
private:
	sf::Font font;
	sf::Text text;
	bool done;
public:
	GameOverMode();
	virtual ~GameOverMode();
	// Inherited via GameState
	virtual void run() override;
	virtual void handleEvents() override;
	virtual State update() override;
	virtual void render() override;
};

