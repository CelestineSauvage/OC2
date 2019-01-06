#ifndef TSP_PARETO_H_
#define TSP_PARETO_H_

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <random>
#include "TSP.h"
#include "TSP_random.h"

// prend une population, génère son voisinage et recréer une nouvelle population
Archive mutation(Archive population, Instance *inst);

// Choisit 2 parents dans la population et génère un enfant
Sol choose_and_repro(Archive population);

// Génère un enfant
Sol reproduction(Sol *parent1, Sol *parent2);

Archive genere_pareto(unsigned int seed, int population, Instance *inst);

#endif
