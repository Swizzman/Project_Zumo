#include "HighscoreMode.h"

void HighscoreMode::sort(double arr[], std::string strArr[], int nrOf)
{
	int currentHighestIndex = 0;
	int temp;
	for (int i = 0; i < nrOf - 1; i++)
	{
		currentHighestIndex = i;
		for (int y = (i + 1); y < nrOf; y++)
		{
			if (arr[y] > arr[currentHighestIndex])
			{
				currentHighestIndex = y;
			}

		}
		swapThem(arr[i], strArr[i], arr[currentHighestIndex], strArr[currentHighestIndex]);


	}
}

void HighscoreMode::swapThem(double& item1, std::string& name, double& item2, std::string& name2)
{
	int temp = item1;
	std::string nameTemp = name;
	item1 = item2;
	item2 = temp;
	name = name2;
	name2 = nameTemp;
}

HighscoreMode::HighscoreMode()
{
	playerInput = "";
	scoresOut.open("../datafiles/highscores.txt", std::ios::app);
	namesOut.open("../datafiles/names.txt", std::ios::app);
	scoresIn.open("../datafiles/highscores.txt");
	namesIn.open("../datafiles/names.txt");
	name[0].changeText("SCORES");
	name[0].setTextPosition(sf::Vector2f(window.getSize().x / 2, 100));
	name[0].setCharacterSize(30);

	namesIn >> nrOf;
	namesIn.ignore();
	scoresIn >> nrOf;
	scoresIn.ignore();
	scoreArr = new double[nrOf];
	nameArr = new std::string[nrOf];
	for (int i = 0; i < nrOf; i++)
	{
		std::string temp;
		std::getline(scoresIn, temp);
		scoreArr[i] = std::stod(temp);
		std::getline(namesIn, nameArr[i]);
	}
	sort(scoreArr, nameArr, nrOf);
	for (int i = 0; i < nrOf; i++)
	{
		std::cout << nameArr[i] << " : " << scoreArr[i] << std::endl;
	}

	for (int i = 1; i < CAPACITY; i++)
	{
		name[i].changeText(nameArr[i] + " : " + std::to_string((int)scoreArr[i]));
		name[i].setTextPosition(sf::Vector2f(window.getSize().x / 2, 30 * i + 100));
	}

	textDesc.changeText("Please Input your name here: ");
	textDesc.setTextPosition(sf::Vector2f(window.getSize().x / 2, 800));
	playerText.setTextPosition(sf::Vector2f(window.getSize().x / 2 + textDesc.getTextSize().x, 800));
	namesIn.close();
	scoresIn.close();
	namesOut.close();
	scoresOut.close();
}

HighscoreMode::~HighscoreMode()
{
}

void HighscoreMode::run()
{
}

void HighscoreMode::handleEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		if (event.type == sf::Event::TextEntered)
		{
			playerInput += event.text.unicode;
			playerText.changeText(playerInput);
		}
	}
}

State HighscoreMode::update()
{
	State state = State::NO_CHANGE;

	return state;
}

void HighscoreMode::render()
{
	window.clear();
	for (int i = 0; i < CAPACITY; i++)
	{
		window.draw(name[i].getText());
	}
	window.draw(textDesc.getText());
	window.draw(playerText.getText());
	window.display();

}
