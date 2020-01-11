#pragma once
#include "GameState.h"
#include "UIHandler.h"
class GameWonMode : public GameState
{
private:
	UIHandler uIHand;
	bool done;
public:
	GameWonMode();
	virtual ~GameWonMode();
	// Inherited via GameState
	virtual void run() override;
	virtual void handleEvents() override;
	virtual State update() override;
	virtual void render() override;
};

