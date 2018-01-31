#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <random>
#include "DNA.h"
using namespace std;

class Population{
	float mutationRate = 0.01f;
	vector<DNA> population;
	vector<DNA> mating;
	string targetWord;
	int generations;
	bool finished;
	int perfectScore;

public:
	
	void calculatePopulationFitness();
	void naturalSelection();
	void generate();
	string getBestFit();
	float getAverageFitness();
	bool getFinished();
	int getGenerations();

	void setFinished(bool state);

	Population(string word, float mutationRate, int  maxPopulation);
	Population();
	~Population();
};

