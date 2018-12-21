
#include "parse.h"

#define N 100

using namespace std;

//struct W {int w1; int w2;};
//
//
// int* cmp (int x, int y){
//   int* tab;
//   tab = new int[2];
//   if (x < y){
//     tab[0] = x;
//     tab[1] = y;
//   }
//   else if (x > y){
//     tab[0] = y;
//     tab[1] = x;
//   }
//   else {
//     cout << "Problème x == y" << endl;
//     return nullptr;
//   }
//   return tab;
// }
//
// /*
//   Évalue une solution pour chaque objectif
// */
// std::vector<int> eval(int n_obj, std::vector<int> *mysol){
//   std::vector<int> &mysolr = *mysol;
//   std::vector<int> score;
//
//   // initialise tous les scores à 0
//   for (int i = 0; i < n_obj; i++){
//     score.push_back(0);
//   }
//   // score = new int[n_obj];
//
//   int pointA = mysolr[0];
//   int pointB = mysolr[1];
//   int* tab = cmp(pointA, pointB);
//
//   // cout << tab[0] << ';' << tab[1] << endl;
//
//   for (int i = 1; i < N; i++){
//     int pointB = mysolr[i];
//     int* tab = cmp(pointA, pointB);
//
//     // cout << tab[0] << ';' << tab[1] << endl;
//     std::transform (edgematrix[tab[0]][tab[1]].begin(), edgematrix[tab[0]][tab[1]].end(), score.begin(), score.begin(), std::plus<int>());
//     pointA = pointB;
//   }
//
//   print_content(&score);
//   return score;
// }

/*
Permutation d'une solution
*/
void random_perm(std::vector<int> *mysol){

  for (int i=0; i<N; i++) mysol->push_back(i);

  random_shuffle ( mysol->begin(), mysol->end() );

  return;
}

// void print_content(std::vector<int> *mysol){
//   std::cout << "mysol contains:";
//   for (std::vector<int>::iterator it=mysol->begin(); it!=mysol->end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << endl;
// }
//
// void offline(std::vector<int> tominmax, std::vector <std::vector <int>> *sols, std::vector <std::vector <int>> pareto){
//   for (std::vector<int>::iterator it=sols->begin(); it!=sols->end(); ++it){
//
//   }
// }

int print_prob(){
  for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++)
            cout << edgematrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}

/*
Forme matrice =

0 1 2 3 4 5
1 0
2 a 0
3 b e 0
4 c f h 0
5 d g i j 0

donc si on i sur en abscisse et j en ordonnée
i < j
*/
int main(int argc, char** argv){
  string line1, line2;
  int val1, val2;

  vector<int> edgematrix[N][N];


  int u = 0; // là où je dois écrire dans la matrice
  int v = 0;

  std::vector<int> mysol;

  assert(argc == 3); // nom du fichier  en argument


  ifstream myfile1, myfile2; // stream in
  myfile1.open (argv[1]); // randomA
  myfile2.open (argv[2]); // randomB
  assert(myfile1.is_open() && myfile2.is_open());

  for (int i =0; i < 7; i++){
    getline (myfile1,line1);
    getline (myfile2,line2);
  }
    while (getline (myfile1,line1) ){ // lit la ligne
      getline (myfile2,line2);
      val1 = stoi (line1,nullptr); // string to int
      val2 = stoi (line2, nullptr); // string to int
      if (v >= N){ // structure en escalier
        u++;
        v = u;
        //std::cout << endl;
      }
      // assert(u < N);
      //std::cout << "(" << u << ","<< v <<")";
      edgematrix[u][v].push_back(val1);
      edgematrix[u][v].push_back(val2);
      v++;
    }
  myfile1.close();
  myfile2.close();

  // print_prob();

  // random_perm(&mysol);
  // print_content(&mysol);

  // eval(2, &mysol);
  return 0;
}
