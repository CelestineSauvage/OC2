#ifndef TSP_SCALAR_H_
#define TSP_SCALAR_H_

#include "TSP.h"
#include "TSP_random.h"

Sol loop_k_opt(Sol *sol, double w1, double w2, Instance *inst);
Sol loop_k_opt2(Sol sol, double w1, double w2, Instance *inst);
Archive genere_scalar(unsigned int seed, double fMin,
  double fMax, int limit, Instance *inst);
  Archive genere_scalar2(unsigned int seed, double step, Instance *inst);

#endif
