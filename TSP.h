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

typedef std::vector<std::vector<int>> Archive;
typedef std::vector<int> Sol;

enum Domination
{
 SOL1_DOMINATION,
 SOL2_DOMINATION,
 NO_DOMINATION
};

std::vector<int> eval_sol(Sol *mysol, Instance *inst);
void filter_offline(Archive &archive, Instance *inst);
void filter_online( Archive &archive, Sol new_sol, Instance *inst);
Domination compare(Sol sol1, Sol sol2, Instance *inst);
void write_archive(Archive &a, Instance *inst, std::string filename);

#endif
