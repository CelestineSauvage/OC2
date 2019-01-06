#include "TSP_pareto.h"

// int total_cost(Archive archive, Instance *inst){
//   int total = 0;
//   for(it = archive->begin(); archive!=d->end(); ++it){
//     total += eval_sol(it, inst)
//   }
//   return total;
// }
void selection(Archive *pop, Archive *baby_pop){
  Sol worst_sol;
  int pop_size = pop->size();
  for (int i = 0; i < pop_size; i++){
    worst_sol = (*pop)[0];
    for (Sol sol = pop->begin(); sol != pop->end(); sol++){
      if ();
    }
  }

  pop->insert( pop->end(), baby_pop->begin(), baby_pop->end() );
}

Archive mutation(Archive population, int pcrt, Instance *inst){
  for (int i = 0; i < pcrt; i++){
    choose_and_repro(population);
  }
  return population;
}


Sol choose_and_repro(Archive population){
  int parent1 = rand()%population.size();
  int parent2 = rand()%population.size();

  while (parent1 == parent2){
    parent2 = rand()%population.size();
  }

  // std::cout << "Parent1" << std::endl;
  // for (auto i = population[parent1].begin(); i != population[parent1].end(); ++i)
  //   std::cout << *i << ' ';
  //
  // std::cout << std::endl;

  // std::cout << "Parent2" << std::endl;
  //
  // for (auto i = population[parent2].begin(); i != population[parent2].end(); ++i)
  //   std::cout << *i << ' ';
  //
  // std::cout << std::endl;


  return reproduction(&population[parent1], &population[parent2]);
}

Sol reproduction(Sol *parent1, Sol *parent2){

  // On prend une partie du trajet du parent 1
  Sol new_child(100,-1);
  int p1_begin = rand()%(50);
  int p1_end = rand()%(50) + 50;

  // on copie la suite génétique du premier parent
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
   //
   // for (auto i = new_child.begin(); i != new_child.end(); ++i)
   //   std::cout << *i << ' ';

  return new_child;
}

Archive genere_pareto(unsigned int seed, int population, Instance *inst){

  Archive sols;
  Sol sol;

  srand(seed);

  for (int i = 0; i < population; i++){
    sol = random_perm();
    sols.push_back(sol);
  }

  mutation(sols, inst);

  return sols;

}
