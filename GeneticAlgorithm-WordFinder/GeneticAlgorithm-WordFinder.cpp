// GeneticAlgorithm-WordFinder.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "stdafx.h"
#include "Population.h"
#include "DNA.h"
using namespace std;

void getUserInput(string& targetWord);
void waitForExit();
void run(Population population, int maxGens);

int main()
{
	string targetWord;
	int maxPopulation = 100;
	int maxGenerations = 1000;
	float mutationRate = 0.011f;

	cout << "Welcome to Pete's Genetic Algorithm Word Finder" << endl << endl;

	getUserInput(targetWord);

	Population population = Population(targetWord, mutationRate, maxPopulation);

	run(population, maxGenerations);

	waitForExit();
    return 0;
}

void getUserInput(string& targetWord) {
	cout << "Default word is \"apple\"" << endl;
	cout << "Enter a different word or press enter:" << endl;
	getline(cin, targetWord);

	locale loc;

	if (targetWord == "") {
		targetWord = "apple";
	}
	else {
		for (std::string::iterator it = targetWord.begin(); it != targetWord.end(); ++it) {
			if (!isalpha(*it) && !isspace(*it)) {
				cout << "Invalid input, defaulting to \"apple\"" << endl << endl;
				targetWord = "apple";
				break;
			}
		}
	}
}

void waitForExit() {

	do{
		cout << endl << "Press a key to continue..." << endl;
	} while (cin.get() != '\n');
}

void run(Population population, int maxGens) {
	while (!population.getFinished() && population.getGenerations() != maxGens) {
		population.naturalSelection();
		population.generate();
		population.calculatePopulationFitness();
	}
}