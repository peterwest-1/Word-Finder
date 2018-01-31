
#include <random>
#include "stdafx.h"
#include "Population.h"


void Population::calculatePopulationFitness() {
	for (size_t i = 0; i < population.size(); i++) {
		population.at(i).calculateFitness(targetWord);
	}
	std::cout << "Generation: " << getGenerations() << std::endl;
	std::cout << "Best Fitness Phrase: " << getBestFit() << std::endl;
	std::cout << "Average Generation Fitness: " << getAverageFitness() << std::endl;
	std::cout << std::endl;
}

void Population::naturalSelection() {
	mating = vector<DNA>();
	float maxfitness = 0;

	for (size_t i = 0; i < population.size(); i++) {
		if (population.at(i).getFitness() > maxfitness) {
			maxfitness = population.at(i).getFitness();
		}
	}

	for (size_t i = 0; i < population.size(); i++) {
		float fitness = population.at(i).getFitness() / maxfitness;
		int n = int(fitness * 20);

		for (int k = 0; k <= n; k++) {
			mating.push_back(population.at(i));
		}
	}
}

void Population::generate() {

	std::random_device rdom;
	std::mt19937 rng(rdom());
	std::uniform_int_distribution<int> uni(0, mating.size() -1);

	for (size_t i = 0; i < population.size(); i++) {

		size_t a = (int) uni(rng);
		size_t b = (int) uni(rng);

		DNA partnerA = mating.at(a);
		DNA partnerB = mating.at(b);

		DNA child = partnerA.crossover(partnerB);
		child.mutate(mutationRate);
		population.at(i) = child;
	}
	generations++;
}

void Population::setFinished(bool state){
	this->finished = state;
}

string  Population::getBestFit(){
	float bestFitness = 0.0f;
	int index = 0;

	for (size_t i = 0; i < population.size(); i++) {
		if (population.at(i).getFitness() > bestFitness) {
			index = i;
			bestFitness = population.at(i).getFitness();
		}
	}

	if (bestFitness == 1) {
		setFinished(true);
	}

	return population.at(index).getGenes();
}

bool Population::getFinished(){
	return finished;
}

int Population::getGenerations(){
	return generations;
}

float Population::getAverageFitness() {
	float total = 0.0f;
	for (size_t i = 0; i < population.size(); i++) {
		total += population.at(i).getFitness();
	}

	return total / population.size();
}

Population::Population(string word, float mutationRate, int  maxPopulation){
	this->targetWord = word;
	this->mutationRate = mutationRate;
	this->population = vector<DNA>(maxPopulation);

	for (size_t i = 0; i < population.size(); i++) {
		population.at(i) = DNA(targetWord.length());
	}

	calculatePopulationFitness();
	this->mating = vector<DNA>();
	this->generations = 0;
	this->finished = false;

}

Population::Population() {

}

Population::~Population(){

}
