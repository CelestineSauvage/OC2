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

Sol loop_k_opt2(Sol sol, double w1, double w2, Instance *inst){
 Sol best_sol = sol;
 Sol new_sol;
 double best_sol_cost = evaluations_weight(&best_sol, w1, w2, inst);
 double new_sol_cost;

   for (size_t i = 0 ; i < sol.size() ; i++){
    for (size_t j = i+1 ; j < sol.size() ; j++){

     new_sol = *two_opt(&sol, i, j);

     new_sol_cost = evaluations_weight(&new_sol, w1, w2, inst);
     if (new_sol_cost < best_sol_cost){
      best_sol_cost = new_sol_cost;
      best_sol = new_sol;
     }
    }
 }

 return best_sol;
}

Archive genere_scalar(unsigned int seed, double fMin,
  double fMax, int population, Instance *inst)
{

  double w1;
  double w2;

  Sol start_sol;
  Archive sols;
  // Archive no_filter;

  srand(seed);

  for (int i = 0; i < population; i++){

    Sol new_sol;

    // random w1 w2
    w1 = fRand(fMin, fMax);
    w2 = fRand(fMin, fMax);

    start_sol = random_perm();
    new_sol = random_perm();
    while (start_sol != new_sol){
      std::cout << i << std::endl;
      start_sol = new_sol;
      new_sol = loop_k_opt(&start_sol, w1, w2, inst);
    }

    // sols.push_back(new_sol);
    filter_online(sols, start_sol, inst);
    // no_filter.push_back(new_sol);
  }

  return sols;
}

Archive genere_scalar2(unsigned int seed, double step, Instance *inst)
{
Archive sols;
srand(seed);

 // Génération des points liés à un poids
 for (float w = 0.0f ; w <= 2.0f ; w+=step*2)
 {
  std::vector<float> weights = {w, 2.0f - w};
  Sol new_sol;
  Sol new_sol2 = random_perm();

  while (new_sol != new_sol2)
  {
   new_sol = new_sol2;
   new_sol2 = loop_k_opt2(new_sol, weights[0], weights[1], inst);
  }
  filter_online(sols, new_sol, inst);
 }

 return sols;
}
