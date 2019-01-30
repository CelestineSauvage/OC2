#ifndef TSP_SCALAR_H_
#define TSP_SCALAR_H_

#include "TSP.h"
#include "TSP_random.h"

// Sol loop_k_opt(Sol *sol, float w1, float w2, Instance *inst);
Sol neighborhood(Sol sol, float w1, float w2, Instance *inst);
// Archive genere_scalar_rand(unsigned int seed, float fMin,
//   float fMax, int population, Instance *inst);
  Archive genere_scalar_step(unsigned int seed, float step, Instance *inst);

#endif
