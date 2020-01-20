#include "GameOverMode.h"

GameOverMode::GameOverMode()
{
	
	uIHand.changeText("Game Over!");
	uIHand.setTextPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
	uIHand.setCharacterSize(30);
	done = false;
}

GameOverMode::~GameOverMode()
{
}


void GameOverMode::handleEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Enter:
				done = true;
				break;
			}
		}

	}
}

State GameOverMode::update()
{
	State state = State::NO_CHANGE;
	if (done)
	{
		state = State::HIGHSCOREINPUT;
	}
	return state;
}

void GameOverMode::render()
{
	
	window.draw(uIHand.getText());
	window.display();
}
