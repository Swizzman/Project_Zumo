#include "GameOverMode.h"

GameOverMode::GameOverMode()
{
	font.loadFromFile("C:/Windows/fonts/arial.ttf");
	text.setFont(font);
	text.setString("Game Over!");
	text.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	text.setCharacterSize(30);
	done = false;
}

GameOverMode::~GameOverMode()
{
}

void GameOverMode::run()
{
	handleEvents();
	update();
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
		state = State::MENU;
	}
	return state;
}

void GameOverMode::render()
{
	
	window.draw(text);
	window.display();
}
