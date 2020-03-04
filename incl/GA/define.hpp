#ifndef DEFINE_HPP
#define DEFINE_HPP

#include "GA/config.hpp"

bool Random(double pr);

class Individual {
	int gene[MAXN];

public:
	double Fitness();
};

void IndividualInit(vector<Individual> &tag, int n);

void Cross(Individual a, Individual b, vector<Individual> &tag);

void Mutation(Individual x, vector<Individual> &tag);

void Select(vector<Individual> &tag, int n);

#endif
