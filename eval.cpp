#include "eval.h"

using namespace std;

void print_content(Sol *mysol){
  std::cout << "mysol contains:";
  for (std::vector<int>::iterator it=mysol->begin(); it!=mysol->end(); ++it)
    std::cout << ' ' << *it;
  std::cout << endl;
}
