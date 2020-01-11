#include "MenuMode.h"


MenuMode::MenuMode()
{
	this->timeCounter = 0;
	this->updateTime = 150;
	done = false;
	this->currentSelection = 0;
	font.loadFromFile("C:/Windows/fonts/arial.ttf");
	for (int i = 0; i < CAPACITY; i++)
	{
		alternatives[i].setFont(this->font);
		alternatives[i].setFillColor(sf::Color::Green);
	}
	alternatives[0].setString("Play");
	alternatives[1].setString("Highscores");
	alternatives[2].setString("Exit");
	alternatives[0].setPosition(200, 300);
	alternatives[1].setPosition(200, 400);
	alternatives[2].setPosition(200, 500);
	alternatives[0].setFillColor(sf::Color::Red);
	logo.setPosition(-100, -100);
	this->elapsedTimeSinceLastUpdate = sf::Time::Zero;
	this->timePerFrame = sf::seconds(1 / 60.f);
}

MenuMode::~MenuMode()
{
}

void MenuMode::moveUp()
{
	if (--currentSelection < 0)
	{
		currentSelection = MAX;
	}
	alternatives[currentSelection].setFillColor(sf::Color::Red);

	for (int i = 0; i < CAPACITY; i++)
	{
		if (i != currentSelection)
		{
			alternatives[i].setFillColor(sf::Color::Green);
		}
	}

}

void MenuMode::moveDown()
{

	if (++currentSelection > MAX)
	{
		currentSelection = 0;
	}
	alternatives[currentSelection].setFillColor(sf::Color::Red);
	for (int i = 0; i < CAPACITY; i++)
	{
		if (i != currentSelection)
		{
			alternatives[i].setFillColor(sf::Color::Green);
		}

	}

}

void MenuMode::run()
{
	handleEvents();
	update();

}

void MenuMode::handleEvents()
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
			case sf::Keyboard::W:
				moveUp();
				break;
			case sf::Keyboard::Up:
				moveUp();
				break;
			case sf::Keyboard::S:
				moveDown();
				break;
			case sf::Keyboard::Down:
				moveDown();
				break;
			case sf::Keyboard::Return:
				done = true;
				break;
			}
		}
	}

}


State MenuMode::update()
{
	State state = State::NO_CHANGE;
	while (window.isOpen())
	{

		elapsedTimeSinceLastUpdate += clock.restart();

		while (elapsedTimeSinceLastUpdate > timePerFrame)
		{

			if (done)
			{
				switch (currentSelection)
				{
				case 0:
					state = State::GAME;
					break;
				case 1:
					state = State::HIGHSCORE;
					break;
				case 2:
					state = State::EXIT;
					break;
				}
			}
			this->timeCounter = (this->timeCounter + 1) % this->updateTime;
			if (this->timeCounter == 0)
			{
				logo.nextFrame();
			}
			return state;
		}
	}
}


void MenuMode::render()
{
	window.clear();
	for (int i = 0; i < CAPACITY; i++)
	{
		window.draw(alternatives[i]);
	}
	window.draw(logo);
	window.display();
}
