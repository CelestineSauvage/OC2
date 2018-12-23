#include "TSP_scalar.h"

Sol loop_k_opt(Sol *sol, double w1, double w2, Instance *inst){
 Sol *best_sol = sol;
 Sol *new_sol;
 float best_sol_cost = evaluations_weight(best_sol, w1, w2, inst);
 float new_sol_cost;
 int id1, id2;

 for (size_t i = 0 ; i < sol.size() ; i++){
  for (size_t j = i+1 ; j < sol.size() ; j++){
   id1 = i;
   id2 = j;
   new_sol = two_opt(sol, i, j);

   new_sol_cost = evaluations_weight(new_sol, weights, inst);
   if (new_sol_cost < best_sol_cost){
    best_sol_cost = new_sol_cost;
    best_sol = new_sol;
   }
  }
 }

 return *best_sol;
}

Archive genere_scalar(unsigned int seed, double fMin, double fMax, int limit){
  double w1;
  double w2;

  Sol start_sol;
  Sol new_sol
  Archive sols;

  std::rand(seed);

  for (int i = 0; i < limit; i++){
    start_sol = random_perm(std::randint(0, 2000000));
    new_sol = loop_k_opt
    sols.push_back(loop_k_opt)
  }

  return sols;
}
