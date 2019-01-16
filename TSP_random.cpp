#include "TSP_random.h"

using namespace std;

/*
Permutation d'une solution
*/
Sol random_perm_seed(int seed){

  srand(seed);

  std::vector<int> mysol;

  for (int i=0; i<100; i++) mysol.push_back(i);

  random_shuffle ( mysol.begin(), mysol.end() );

  return mysol;
}

Sol random_perm(){

  std::vector<int> mysol;

  for (int i=0; i<100; i++) mysol.push_back(i);

  random_shuffle ( mysol.begin(), mysol.end() );

  return mysol;
}

/*
Génére un ensemble de solutions aléatoires
*/
Archive archive_rand(int nb){
  Archive archive;
  for (int i = 0; i < nb ; i++){
    archive.push_back(random_perm());
  }
  return archive;
}

/*
Génére un ensemble de solutions aléatoires
*/
Archive archive_rand_seed(int nb){
  Archive archive;
  for (int i = 0; i < nb ; i++){
    archive.push_back(random_perm_seed(i));
  }
  return archive;
}
