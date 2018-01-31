// GeneticAlgorithm-WordFinder.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "stdafx.h"
#include "Population.h"
#include "DNA.h"
using namespace std;

void run(Population population, int maxGens);
void printTitle(string targetWord);
void waitForExit();

int main()
{
	string targetWord = "Peter West";
	int maxPopulation = 100;
	int maxGenerations = 1000;
	float mutationRate = 0.01f;

	Population population = Population(targetWord, mutationRate, maxPopulation);

	printTitle(targetWord);

	run(population, maxGenerations);

	waitForExit();
    return 0;
}

void printTitle(string targetWord) {
	cout << "Welcome to Pete's Genetic Algorithm Word Finder" << endl;
	cout << "Target word: \"" << targetWord << "\"" << endl << endl;
}

void waitForExit() {

	do{
		cout << '\n' << "Press a key to continue...";
	} while (cin.get() != '\n');
}

void run(Population population, int maxGens) {
	while (!population.getFinished() && population.getGenerations() != maxGens) {
		population.naturalSelection();
		population.generate();
		population.calculatePopulationFitness();
	}
}