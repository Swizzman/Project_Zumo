#include "MenuMode.h"


MenuMode::MenuMode()
{
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
	gameName.setFont(this->font);
	gameName.setString("Zumo!");
	gameName.setFillColor(sf::Color::Red);
	gameName.setPosition(200, 200);
}

MenuMode::~MenuMode()
{
}

void MenuMode::moveUp()
{
	if (currentSelection-- < 1)
	{
		currentSelection = MAX;
	}
	std::cout << currentSelection << std::endl;
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

	if (currentSelection++ > MAX)
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
		if (sf::Keyboard::isKeyPressed)
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
		}
	}
	return state;
}

void MenuMode::render()
{
	window.clear();
	window.draw(gameName);
	for (int i = 0; i < CAPACITY; i++)
	{
		window.draw(alternatives[i]);
	}
	window.display();
}
