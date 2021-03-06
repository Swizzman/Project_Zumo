#pragma once
#include "GameState.h"
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include <fstream>
#include <string>
#include <iostream>
#include "UIHandler.h"
class HighscoreViewMode :
	public GameState
{
private:
	int nrOf;
	static const int CAPACITY = 10;
	UIHandler scoresText;
	std::ifstream namesIn;
	std::ifstream scoresIn;
	std::ofstream namesOut;
	std::ofstream scoresOut;
	UIHandler names[CAPACITY];
	double* scoreArr;
	std::string* nameArr;
	bool done;
	void sort(double arr[], std::string strArr[], int nrOf);

	void swapThem(double& item1, std::string& name, double& item2, std::string& name2);
public:
	HighscoreViewMode();
	virtual ~HighscoreViewMode();
	// Inherited via GameState
	virtual void handleEvents() override;
	virtual State update() override;
	virtual void render() override;
};

