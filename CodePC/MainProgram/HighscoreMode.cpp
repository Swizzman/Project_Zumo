#include "HighscoreMode.h"

void HighscoreMode::sort(double arr[], std::string strArr[], int nrOf)
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
	playerInputScore = "";
	nameInputDone = false;
	scoreInputDone = false;
	scoresIn.open("../datafiles/highscores.txt");
	namesIn.open("../datafiles/names.txt");
	namesIn.imbue(std::locale("swedish"));
	scoresText.changeText("SCORES");
	scoresText.setTextPosition(sf::Vector2f(window.getSize().x / 2, 100));
	scoresText.setCharacterSize(30);

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

	for (int i = 0; i < CAPACITY && i < nrOf; i++)
	{
		names[i].changeText(nameArr[i] + " : " + std::to_string((int)scoreArr[i]));
		names[i].setCharacterSize(20);
		names[i].setTextPosition(sf::Vector2f(window.getSize().x / 2, 30 * i + 200));
	}

	textDesc.changeText("Please Input your name here: ");
	textDesc.setTextPosition(sf::Vector2f(window.getSize().x / 2, 800));
	playerText.setTextPosition(sf::Vector2f(window.getSize().x / 2 + textDesc.getTextSize().x, 800));
	scoreDesc.changeText("Please input your score here (plz be honest): ");
	scoreDesc.setTextPosition(sf::Vector2f(WIDTH / 2, 900));
	playerScore.setTextPosition(sf::Vector2f(WIDTH / 2 + scoreDesc.getTextSize().x, 900));
	namesIn.close();
	scoresIn.close();

}

HighscoreMode::~HighscoreMode()
{

	delete[]scoreArr;
	delete[]nameArr;
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
			if (!nameInputDone && !scoreInputDone)
			{
				if (event.text.unicode == 8)
				{
					if (!playerInput.empty())
					{
						playerInput.pop_back();
					}
					playerText.changeText(playerInput);
				}
				else if (event.text.unicode != 13)
				{
					playerInput += event.text.unicode;
					playerText.changeText(playerInput);
				}
				
				else
				{
					nameInputDone = true;
				}
			}

			else if (nameInputDone && !scoreInputDone)
			{
				if (event.text.unicode == 8)
				{
					if (!playerInput.empty())
					{
						playerInputScore.pop_back();
					}
					playerScore.changeText(playerInputScore);
				}
				else if (event.text.unicode != 13)
				{
					playerInputScore += event.text.unicode;
					playerScore.changeText(playerInputScore);
				}
				else
				{
					scoreInputDone = true;
				}
			}


		}
	}
}

State HighscoreMode::update()
{
	State state = State::NO_CHANGE;
	if (nameInputDone && scoreInputDone)
	{
		namesOut.open("../datafiles/names.txt", std::ios::app);
		scoresOut.open("../datafiles/highscores.txt", std::ios::app);

		std::string temp = playerInput;
		namesOut << temp;
		scoresOut << playerInputScore;
		state = State::MENU;
		namesOut.close();
		scoresOut.close();
		namesOut.open("../datafiles/names.txt");

		scoresOut.open("../datafiles/highscores.txt");
		scoresOut << ++nrOf;
		namesOut << nrOf;
		for (int i = 0; i < nrOf; i++)
		{
			if (i == nrOf - 1)
			{
				scoresOut << "\n" << playerInputScore;
				namesOut << "\n" << playerInput;
			}
			else
			{
				scoresOut << "\n" << scoreArr[i];
				namesOut << "\n" << nameArr[i];
			}
		}
		namesOut.close();
		scoresOut.close();
	}
	return state;
}

void HighscoreMode::render()
{
	window.clear();
	for (int i = 0; i < CAPACITY && i < nrOf; i++)
	{
		window.draw(names[i].getText());
	}
	window.draw(textDesc.getText());
	window.draw(playerText.getText());
	if (nameInputDone)
	{
		window.draw(scoreDesc.getText());
		window.draw(playerScore.getText());
	}
	window.draw(scoresText.getText());
	window.display();

}
