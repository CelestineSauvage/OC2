#ifndef TSP_H_
#define TSP_H_

#include "Instance.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <vector>

typedef std::vector<int> Sol;
typedef Sol *SolPtr;
typedef std::vector<SolPtr> Archive;
typedef Archive *ArchivePtr;


enum Domination
{
 SOL1_DOMINATION,
 SOL2_DOMINATION,
 NO_DOMINATION
};

Sol* two_opt(Sol *sol, int id1, int id2);
double evaluations_weight(Sol *mysol, double w1, double w2, Instance *inst);
std::vector<int> eval_sol(Sol *mysol, Instance *inst);
void filter_offline(Archive &archive, Instance *inst);
void filter_online( Archive &archive, Sol new_sol, Instance *inst);
Domination compare(Sol sol1, Sol sol2, Instance *inst);
void write_archive(Archive &a, Instance *inst, std::string filename);

#endif
