#include "TSP_pareto.h"

int iteration = 0;
int mutation = 10;

// Sélection de la population restante
Archive selection(Archive pop, Archive baby_pop, int childs, Instance *inst){
  int sol1;
  int sol2;
  int i = 0;

  pop.insert(pop.end(), baby_pop.begin(), baby_pop.end() );
  random_shuffle(pop.begin(), pop.end());
  while (i < childs){
    sol1 = rand()%pop.size();
    sol2 = rand()%pop.size();

    Domination res_compare = compare(pop[sol1], pop[sol2], inst);
    if (res_compare == SOL1_DOMINATION){
      pop.erase(pop.begin()+sol2);
      i++;
    }
    else if (res_compare == SOL2_DOMINATION){
      pop.erase(pop.begin()+sol1);
      i++;
    }

  }
  return pop;
}

Archive selection_rank(Archive pop, Archive baby_pop,std::vector<int> rank, int childs, Instance *inst){
  int sol1;
  int sol2;
  int i = 0;

  std::vector<int> pr = pareto_rank(baby_pop, inst);
  pop.insert(pop.end(), baby_pop.begin(), baby_pop.end() );
  rank.insert(rank.end(), pr.begin(), pr.end() );

  //random_shuffle(pop.begin(), pop.end());
  while (i < childs){
    sol1 = rand()%pop.size();
    sol2 = rand()%pop.size();

    if (rank[sol1] > rank[sol2]){
      pop.erase(pop.begin()+sol2);
      i++;
    }
    else if (rank[sol1] < rank[sol2]){
      pop.erase(pop.begin()+sol1);
      i++;
    }

  }
  random_shuffle(pop.begin(), pop.end());

  return pop;
}

// Retourne le meilleur parent dans la liste
int best_parent(Archive population, std::vector<int> parents, int obji, Instance *inst){
  int bp = parents[0];
  int best_score = eval_sol(&population[bp], inst)[obji];
  int new_score;
  for (auto p = parents.begin(); p != parents.end(); p++){
    new_score = eval_sol(&population[*p], inst)[obji];

    if (new_score < best_score){
      best_score = new_score;
      bp = *p;
    }
  }

  return bp;
}

int best_parent_rank(std::vector<int> parents, std::vector<int> rank){
  int bp = parents[0];
  int best_score = rank[bp];
  int new_score;
  for (auto p = parents.begin(); p != parents.end(); p++){
    new_score = rank[*p];

    if (new_score < best_score){
      best_score = new_score;
      bp = *p;
    }
  }

  return bp;
}

// Nouvelle génération
Archive new_generation(Archive population, int childs, int k, Instance *inst){
  Archive babies;
  // std::vector<int> pr = pareto_rank(population, inst);
  for (int i = 0; i < childs; i++){
    babies.push_back(choose_and_repro(population, k, inst));
  }
  return selection(population, babies, childs, inst);
}

// Nouvelle génération
Archive new_generation_rank(Archive population, int childs, int k, Instance *inst){
  Archive babies;
  std::vector<int> pr = pareto_rank(population, inst);
  for (int i = 0; i < childs; i++){
    babies.push_back(choose_and_repro_rank(population, pr, k));
  }
  return selection_rank(population, babies, pr, childs, inst);
}

Sol choose_and_repro_rank(Archive population, std::vector<int> rank, int k){

  std::vector<int> parents1;
  std::vector<int> parents2;

  for (int cpt = 0; cpt < k; cpt++){
    parents1.push_back(rand()%population.size());
    parents2.push_back(rand()%population.size());
  }

  int parent1 = best_parent_rank(parents1, rank);
  int parent2 = best_parent_rank(parents2, rank);

  return reproduction(&population[parent1], &population[parent2]);
}

// Choisit un couple de parents qui se reproduit

// K tournament selection
Sol choose_and_repro(Archive population, int k, Instance *inst){

  std::vector<int> parents1;
  std::vector<int> parents2;

  int rand1 = rand()%2;
  int rand2 = rand()%2;

  // liste des parents qui minimisent 1, liste des parents qui minimisent 2

  for (int cpt = 0; cpt < k; cpt++){
    parents1.push_back(rand()%population.size());
    parents2.push_back(rand()%population.size());
  }

  int parent1 = best_parent(population, parents1, rand1, inst);
  int parent2 = best_parent(population, parents2, rand2, inst);

  // while (parent1 == parent2){
  //   parent2 = rand()%population.size();
  // }

  return reproduction(&population[parent1], &population[parent2]);
}

Sol reproduction(Sol *parent1, Sol *parent2){

  // On prend une partie du trajet du parent 1
  Sol new_child(100,-1);
  int p1_begin = rand()%(50);
  int p1_end = rand()%(50) + 50;

  // on copie une partie du premier parent
  std::copy(parent1->begin()+p1_begin, parent1->begin()+p1_end, new_child.begin()+p1_begin);

  // gene manquant
  std::vector<int> gen_missing(100-p1_end + p1_begin, -1);
  std::copy(parent1->begin(), parent1->begin()+p1_begin, gen_missing.begin());

  std::copy(parent1->begin()+p1_end, parent1->end(), gen_missing.begin()+  p1_begin);

  // std::cout << "Gene manquant" << std::endl;
  //
  // for (auto i = gen_missing.begin(); i != gen_missing.end(); ++i)
  //   std::cout << *i << ' ';
  //
  // std::cout << std::endl;

  std::vector<std::pair<int, int>> indexed_missing;
  for (auto gen: gen_missing)
  indexed_missing.push_back(std::pair<int, int>(
                    gen,
                    std::find(parent2->begin(), parent2->end(), gen)-parent2->begin()));

  // std::cout << "Index sans tri" << std::endl;
  // for (auto i = indexed_missing.begin(); i != indexed_missing.end(); ++i)
  //   std::cout << '(' << (*i).first << ',' << (*i).second << ')' << ' ';

 // On trie puis on ajoute les gen manquant
 std::sort(indexed_missing.begin(), indexed_missing.end(),
           [&](const std::pair<int, int>& first, const std::pair<long, int>&second)
           { return first.second < second.second; });

 // std::cout << "Index avec tri" << std::endl;

  // for (auto i = indexed_missing.begin(); i != indexed_missing.end(); ++i)
  //   std::cout << '(' << (*i).first << ',' << (*i).second << ')' << ' ';
  //
  // std::cout << std::endl;


  int ii = 0;
   for (int i = 0 ; i < (int)new_child.size() ; i++)
   {
    if (i == p1_begin)
     i = p1_end;

    new_child[i] = indexed_missing[ii].first;
    ii++;
   }

   if (iteration%mutation == 0){
   // on applique une mutation, un swap
     int ind1 = rand()%new_child.size();
     int ind2 = rand()%new_child.size();
     if (ind1 < ind2)
        new_child = myswap(new_child, ind1, ind2);
    else
        new_child = myswap(new_child, ind2, ind1);
  }

  return new_child;
}

Archive genere_pareto(unsigned int seed, int childs, int population, int max_iteration, int k, int mut, Instance *inst){

  Archive sols;
  Archive archive;
  Sol sol;

  mutation = mut;

  srand(seed);

  for (int i = 0; i < population; i++){
    sol = random_perm();
    sols.push_back(sol);
  }

  for (; iteration < max_iteration; iteration++){
      sols = new_generation(sols, childs, k, inst);
  }

  for (auto it = sols.begin(); it != sols.end(); it++){
    filter_online(archive, *it, inst);
  }

  return archive;

}
