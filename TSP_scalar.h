#ifndef TSP_SCALAR_H_
#define TSP_SCALAR_H_

#include "TSP.h"

Sol loop_k_opt(Sol *sol, double w1, double w2, Instance *inst);
Archive genere_scalar(double limit, double step_weight);

#endif
