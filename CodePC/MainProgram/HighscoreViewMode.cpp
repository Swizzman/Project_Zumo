#include "HighscoreViewMode.h"

void HighscoreViewMode::sort(double arr[], std::string strArr[], int nrOf)
{
	for (int i = 1; i < nrOf; i++)
	{
		if (arr[i] >= arr[0])
		{
			arr[0] = arr[i] + 1;
		}
	}

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

void HighscoreViewMode::swapThem(double& item1, std::string& name, double& item2, std::string& name2)
{
	int temp = item1;
	std::string nameTemp = name;
	item1 = item2;
	item2 = temp;
	name = name2;
	name2 = nameTemp;
}

HighscoreViewMode::HighscoreViewMode()
{
	scoresIn.open("../datafiles/highscores.txt");
	namesIn.open("../datafiles/names.txt");
	namesIn.imbue(std::locale("swedish"));
	scoresText.changeText("SCORES");
	scoresText.setTextPosition(sf::Vector2f(window.getSize().x / 2, 100));
	scoresText.setCharacterSize(30);
	done = false;
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
	for (int i = 0; i < CAPACITY && i < nrOf; i++)
	{
		names[i].changeText(nameArr[i] + " : " + std::to_string((int)scoreArr[i]));
		names[i].setCharacterSize(20);
		names[i].setTextPosition(sf::Vector2f(window.getSize().x / 2, 30 * i + 200));
	}

	namesIn.close();
	scoresIn.close();

}

HighscoreViewMode::~HighscoreViewMode()
{
	delete[]scoreArr;
	delete[]nameArr;
}

void HighscoreViewMode::handleEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			done = true;
		}
	
		
	}
}

State HighscoreViewMode::update()
{
	State state = State::NO_CHANGE;
	if (done)
	{
		state = State::MENU;	
	}
	return state;
}

void HighscoreViewMode::render()
{
	window.clear();
	for (int i = 0; i < CAPACITY && i < nrOf; i++)
	{
		window.draw(names[i].getText());
	}
	
	window.draw(scoresText.getText());
	window.display();
}
