#ifndef RANDOM_H_
#define RANDOM_H_

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <vector>
#include "TSP.h"

Sol random_perm_seed(int seed);
Sol random_perm();
Archive archive_rand(int nb);
Archive archive_rand_seed(int nb);

#endif
