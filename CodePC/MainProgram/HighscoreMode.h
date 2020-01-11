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
	static const int CAPACITY = 11;
	std::string playerInput;
	UIHandler playerText;
	std::string currentName;
	std::string score;
	std::ifstream namesIn;
	std::ifstream scoresIn;
	std::ofstream namesOut;
	std::ofstream scoresOut;
	UIHandler name[CAPACITY];
	UIHandler textDesc;
	double* scoreArr;
	std::string* nameArr;
	void sort(double arr[],std::string strArr[], int nrOf);

	void swapThem(double& item1, std::string& name, double& item2, std::string &name2);

public:
	HighscoreMode();
	virtual ~HighscoreMode();
	// Inherited via GameState
	virtual void run() override;
	virtual void handleEvents() override;
	virtual State update() override;
	virtual void render() override;
};

