#ifndef TSP_SCALAR_H_
#define TSP_SCALAR_H_

#include "TSP.h"
#include "TSP_random.h"

Sol loop_k_opt(Sol *sol, double w1, double w2, Instance *inst);
Archive genere_scalar(unsigned int seed, double fMin,
  double fMax, int limit, Instance *inst);

#endif
