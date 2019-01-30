#include "TSP.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <fstream>

// renvoie un float random
float fRand(float fMin, float fMax){
    float f = (float)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

// Sol* two_opt(Sol *sol, int id1, int id2){
//  while (id1 < id2){
//   std::iter_swap(sol->begin()+id1, sol->begin()+id2);
//   id1++;
//   id2--;
//  }
//  return sol;
// }

// Change la solution
Sol myswap(Sol sol, int i, int j){
 while (i < j){
  std::iter_swap(sol.begin()+i, sol.begin()+j);
  i++;
  j--;
 }
 return sol;
}

/*
Calcul la somme pondérée d'une solution
*/
float eval_weight(Sol *mysol, float w1, float w2, Instance *inst){
  std::vector<int> score = eval_sol(mysol, inst);

  float evals = 0.0;
  evals += w1*score[0];
  evals += w2*score[1];

  return evals;
}

// int evaluations_weight2
// (Sol *solution, float w1, float w2, Instance *inst){
//   int evals = 0;
//   Sol &mysolr = *solution;
//
//   for (size_t j = 0; j < solution->size()-1; j++){
//     std::vector<int> *dist = inst->getValue(mysolr[j], mysolr[j+1]);
//     evals += w1 * dist->at(0);
//     evals += w2 * dist->at(1);
//   }
//   std::vector<int> *dist = inst->getValue(mysolr[solution->size()-1], mysolr[0]);
//   evals += w1 * dist->at(0);
//   evals += w2 * dist->at(1);
//
//   return evals;
// }

/*
Évalue une solution
*/
std::vector<int> eval_sol(Sol *mysol, Instance *inst){
  Sol &mysolr = *mysol;
  std::vector<int> evals;

  evals.push_back(0);
  evals.push_back(0);

  for (size_t j = 0; j < mysol->size()-1; j++){
    std::vector<int> *dist = inst->getValue(mysolr[j], mysolr[j+1]);
    evals[0] += dist->at(0);
    evals[1] += dist->at(1);
  }
  std::vector<int> *dist = inst->getValue(mysolr[mysol->size()-1], mysolr[0]);
  evals[0] += dist->at(0);
  evals[1] += dist->at(1);

  return evals;
}

// compare 2 solutions
Domination compare(Sol sol1, Sol sol2, Instance *inst){
 int cpt = 0;

 std::vector<int> score1 = eval_sol(&sol1, inst);
 std::vector<int> score2 = eval_sol(&sol2, inst);

 if(score1[0] <= score2[0]){
   cpt++;
 }
 if(score1[1] <= score2[1]){
   cpt++;
 }

 // sol1 domine
 if (cpt == 2)
  return SOL1_DOMINATION;
 // sol2 domine
 else if (cpt == 0)
  return SOL2_DOMINATION;
 // pas de dominant
 else
  return NO_DOMINATION;
}

/*
Filtre offline
*/
void filter_offline(Archive &archive, Instance *inst){
 size_t i = 0;
 size_t j = 1;

 do{
 j = i + 1;
 Sol elem = archive[i];

  while (j < archive.size()){
      Domination rs = compare(elem, archive[j], inst);
      if (rs == SOL1_DOMINATION){
        archive.erase(archive.begin()+j);
      }
      else if (rs == SOL2_DOMINATION){
        archive.erase(archive.begin()+i);
        i = 0;
        break;
      }
      else {
        j++;
      }
  }
  if (j == archive.size())
    i++;
  } while (i < archive.size());

}

/*
Filtre online
*/
void filter_online( Archive &archive, Sol new_sol, Instance *inst){
  size_t i = 0;
while (i < archive.size()){
  Domination rs = compare(archive[i], new_sol, inst);

  // new sol est dominé
  if (rs == SOL1_DOMINATION)
   return;
  // new sol domine au moins une fois, donc elle peut être ajouté
  else if (rs == SOL2_DOMINATION){
    archive.erase(archive.begin()+i);
  }
  else
    i++;
 }
 // On l'ajoute à l'archive
 archive.push_back(new_sol);
}

/*
Écrire le contenu d'une archive dans un fichier
*/
void write_archive(Archive &a, Instance *inst, std::string filename)
{
 std::ofstream file(filename, std::ofstream::out);

 for (size_t i = 0 ; i < a.size() ; i++){
  std::vector<int> evals = eval_sol(&a[i], inst);
  file << evals[0] << " "<< evals[1];
  file << std::endl;
 }
}
