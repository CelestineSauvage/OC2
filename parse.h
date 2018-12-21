#ifndef PARSE_H_
#define PARSE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <vector>

int* cmp (int x, int y);
std::vector<int> eval(int n_obj, std::vector<int> *mysol);
void random_perm(std::vector<int> *mysol);
void print_content(std::vector<int> *mysol);

#endif
