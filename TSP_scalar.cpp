#include "TSP_scalar.h"

// Trouve les meilleurs solutions
Sol loop_k_opt(Sol *sol, double w1, double w2, Instance *inst){
 Sol *best_sol = sol;
 Sol *new_sol;
 double best_sol_cost = evaluations_weight(best_sol, w1, w2, inst);
 double new_sol_cost;

 for (size_t i = 0 ; i < sol->size() ; i++){
  for (size_t j = i+1 ; j < sol->size() ; j++){

   new_sol = two_opt(sol, i, j);

   new_sol_cost = evaluations_weight(new_sol, w1, w2, inst);
   if (new_sol_cost < best_sol_cost){
    best_sol_cost = new_sol_cost;
    best_sol = new_sol;
   }
  }
 }

 return *best_sol;
}

Archive genere_scalar(unsigned int seed, double fMin,
  double fMax, int limit, Instance *inst)
{

  double w1;
  double w2;

  Sol start_sol;
  Sol new_sol;
  Archive sols;
  Archive no_filter

  srand(seed);

  for (int i = 0; i < limit; i++){

    // random w1 w2
    w1 = fRand(fMin, fMax);
    w2 = fRand(fMin, fMax);

    start_sol = random_perm();
    new_sol = loop_k_opt(&start_sol, w1, w2, inst);
    filter_online(sols, new_sol, inst);
    no_filter.push_back(new_sol);
  }

  return sols;
}
