// GeneticAlgorithm-WordFinder.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "stdafx.h"
#include "Population.h"
#include "DNA.h"
using namespace std;

void printTitle(string targetWord);
void getUserInput(string& targetWord);
void waitForExit();
void run(Population population, int maxGens);

int main()
{
	string targetWord = "apple";
	int maxPopulation = 100;
	int maxGenerations = 1000;
	float mutationRate = 0.01f;

	printTitle(targetWord);
	getUserInput(targetWord);

	Population population = Population(targetWord, mutationRate, maxPopulation);

	run(population, maxGenerations);

	waitForExit();
    return 0;
}

void printTitle(string targetWord) {
	cout << "Welcome to Pete's Genetic Algorithm Word Finder" << endl;
	cout << "Target word: \"" << targetWord << "\"" << endl << endl;
}

void getUserInput(string& targetWord) {
	cout << "Default word is \"apple\"" << endl;
	cout << "Enter a different word or press enter:" << endl;
	getline(cin, targetWord);
	cout << "You entered: "<< targetWord << endl;
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