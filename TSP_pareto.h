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
Archive selection(Archive pop, Archive baby_pop, int childs, Instance *inst);


Archive selection_rank(Archive pop, Archive baby_pop,std::vector<int> rank, int childs, Instance *inst);

int best_parent(Archive population, std::vector<int> parents, int obji, Instance *inst);

int best_parent_rank(std::vector<int> parents, std::vector<int> rank);

Sol choose_and_repro_rank(Archive population, std::vector<int>rank, int k);

Archive new_generation(Archive population, int pcrt, int k, Instance *inst);

// Choisit 2 parents dans la population et génère un enfant
Sol choose_and_repro(Archive population, int k, Instance *inst);

// Génère un enfant
Sol reproduction(Sol *parent1, Sol *parent2);

Archive genere_pareto(unsigned int seed, int childs, int population, int max_iteration, int k, int mut, Instance *inst);

#endif
