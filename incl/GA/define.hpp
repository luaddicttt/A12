#ifndef DEFINE_HPP
#define DEFINE_HPP

#include "GA/config.hpp"

bool Random(double pr);

struct Individual {
	int next[MAXN];
	int num_truck;
	double fitness;
	Individual() =default;
	bool Calc();
};

void IndividualInit(vector<Individual> &tag, int n);

void Cross(Individual a, Individual b, vector<Individual> &tag);

void Mutation(Individual x, vector<Individual> &tag);

void Select(vector<Individual> &tag, int n);

#endif
