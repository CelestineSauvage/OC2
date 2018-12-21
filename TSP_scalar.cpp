#include "TSP_Scalar.h"

Sol loop_k_opt(Sol *sol, std::vector<float> weights, Instance *inst){
 Sol *best_sol = sol;
 Sol *new_sol;
 float best_sol_cost = evaluations_weight(best_sol, weights, inst);
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
