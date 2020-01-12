#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include <fstream>
#include <string>
#include <iostream>
#include "UIHandler.h"

class HighscoreMode :
	public GameState
{
private:
	int nrOf;
	static const int CAPACITY = 10;
	std::string playerInput;
	std::string playerInputScore;
	UIHandler playerText;
	UIHandler playerScore;
	UIHandler scoresText;
	std::string currentName;
	std::string score;
	std::ifstream namesIn;
	std::ifstream scoresIn;
	std::ofstream namesOut;
	std::ofstream scoresOut;
	UIHandler names[CAPACITY];
	UIHandler textDesc;
	UIHandler scoreDesc;
	double* scoreArr;
	std::string* nameArr;
	bool nameInputDone;
	bool scoreInputDone;
	void sort(double arr[],std::string strArr[], int nrOf);

	void swapThem(double& item1, std::string& name, double& item2, std::string &name2);

public:
	HighscoreMode();
	virtual ~HighscoreMode();
	// Inherited via GameState
	virtual void handleEvents() override;
	virtual State update() override;
	virtual void render() override;
};

