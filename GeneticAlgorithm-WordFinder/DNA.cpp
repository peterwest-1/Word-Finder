#include "stdafx.h"
#include "DNA.h"
#include <time.h>
#include <random>


///please dont judge me for this, it is late
const char alpha[] = { ' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
					  'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' 
					 };

size_t DNA::getGeneSize(){
	return genes.size();
}

float DNA::getFitness(){
	return this->fitness;
}

string DNA::getGenes(){
	string word = "";
	for (size_t j = 0; j < genes.size(); j++) {
		word += genes.at(j);
	}
	return word;
}

void DNA::calculateFitness(string target){
	vector<char> targetChar(target.begin(), target.end());

	int score = 0;
	for (size_t i = 0; i < targetChar.size(); i++) {
		if (genes.at(i) == targetChar[i]) {
			score++;
		}
	}

	fitness = (float) score / targetChar.size();
}

DNA DNA::crossover(DNA partner){
	std::random_device rdom;
	std::mt19937 rng(rdom());
	std::uniform_int_distribution<int> uni(0, genes.size());

	DNA child = DNA(this->genes.size());

	size_t midpoint= uni(rng);

	for (size_t i = 0; i < genes.size(); i++) {
		if (i > midpoint) {
			child.genes.at(i) = genes.at(i);
		}
		else {
			child.genes.at(i) = partner.genes.at(i);
		}
	}

	return child;
}

void DNA::mutate(float mutationRate){
	std::random_device rdom;
	std::mt19937 rng(rdom());
	std::uniform_int_distribution<int> uni(0, 52);
	std::uniform_int_distribution<int> rando(0, 100);

	for (size_t i = 0; i < genes.size(); i++) {
		if (rando(rng) < mutationRate*100) {
			genes.at(i) = alpha[uni(rng)];
		}
	}
}

DNA::DNA(vector<char> genes) {
	this->genes = genes;
}

DNA::DNA(int numberOfCharacters) {
	std::random_device rdom;
	std::mt19937 rng(rdom());
	std::uniform_int_distribution<int> uni(0, 25);

	//srand((unsigned int) time(NULL));
	genes = vector<char>(numberOfCharacters);
	for (size_t i = 0; i < genes.size(); i++) {
		genes.at(i) = alpha[uni(rng)];
	}
}

DNA::DNA() {
	//default constructor
}

DNA::~DNA(){

}
