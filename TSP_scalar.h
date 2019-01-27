#ifndef TSP_SCALAR_H_
#define TSP_SCALAR_H_

#include "TSP.h"
#include "TSP_random.h"

Sol loop_k_opt(Sol *sol, float w1, float w2, Instance *inst);
Sol loop_k_opt2(Sol sol, float w1, float w2, Instance *inst);
Archive genere_scalar(unsigned int seed, float fMin,
  float fMax, int limit, Instance *inst);
  Archive genere_scalar2(unsigned int seed, float step, Instance *inst);

#endif
