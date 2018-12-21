#include "TSP.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <fstream>

Sol* two_opt(Sol *sol, int id1, int id2){
 while (id1 < id2){
  std::iter_swap(sol->begin()+id1, sol->begin()+id2);
  id1++;
  id2--;
 }
 return sol;
}

/*
Calcul la somme pondérée d'une solution
*/
float evaluations_weight(Sol *mysol, std::vector<float> weights, Instance *inst){
  std::vector<int> score = eval_sol(mysol, inst);

  float evals = 0.0;
  evals += weights[0]*score[0];
  evals += weights[1]*score[1];

  return evals;
}

/*
Évalue une solution
*/
std::vector<int> eval_sol(Sol *mysol, Instance *inst){
  Sol &mysolr = *mysol;
  std::vector<int> score;

  // initialise tous les scores à 0
  score.push_back(0);
  score.push_back(0);

  int pointA = mysolr[0];
  int pointB = mysolr[1];

  // cout << tab[0] << ';' << tab[1] << endl;

  for (int i = 1; i < 100; i++){
    pointB = mysolr[i];
    std::vector<int> *dist = inst->getValue(pointA,pointB);

    score[0] = score[0] + dist->at(0);
    score[1] = score[1] + + dist->at(1);

    pointA = pointB;
  }

  return score;
}

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
