#pragma once
#include "State.h"
#include "GameState.h"
#include "UIHandler.h"
class GameOverMode : public GameState
{
private:
	UIHandler uIHand;
	bool done;
public:
	GameOverMode();
	virtual ~GameOverMode();
	// Inherited via GameState
	virtual void handleEvents() override;
	virtual State update() override;
	virtual void render() override;
};

