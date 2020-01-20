#include <SFML/Graphics.hpp>
#include "game.h"
#include "MenuMode.h"
#include "GameOverMode.h"
#include "GameWonMode.h"
#include "HighscoreInputMode.h"
#include "HighscoreViewMode.h"


#ifdef _DEBUG
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-system-d.lib")
#pragma comment(lib, "sfml-graphics-d.lib")
#pragma comment(lib, "sfml-audio-d.lib")
#else
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-system.lib")
#pragma comment(lib, "sfml-graphics.lib")
#pragma comment(lib, "sfml-audio.lib")
#endif


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	GameState* current = nullptr;
	State currentState = State::NO_CHANGE;
	current = new MenuMode();
	currentState = State::MENU;
	srand((unsigned int)time(0));
	while (currentState != State::EXIT)
	{
		current->handleEvents();
		currentState = current->update();

		switch (currentState)
		{
		case State::GAME:
			delete current;
			current = new Game();
			break;
		case State::HIGHSCOREINPUT:
			delete current;
			current = new HighscoreInputMode();
			break;
		case State::HIGHSCOREVIEW:
			delete current;
			current = new HighscoreViewMode();
			break;
		case State::MENU:
			delete current;
			current = new MenuMode();
			break;
		case State::GAME_OVER:
			delete current;
			current = new GameOverMode();
			break;
		case State::GAME_WON:
			delete current;
			current = new GameWonMode();
		}
		current->render();
	}
	delete current;
	(void) getchar();
	return 0;
}