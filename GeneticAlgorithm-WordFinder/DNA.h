#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

class DNA
{

	vector<char> genes;
	float fitness = 0;

public:
	size_t getGeneSize();
	float getFitness();
	string getGenes();

	void calculateFitness(string target);
	void mutate(float mutationRate);
	DNA crossover(DNA partner);
	
	DNA(int numberOfCharacters);
	DNA(vector<char> genes);
	DNA();
	~DNA();
};

