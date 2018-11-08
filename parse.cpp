#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <assert.h>

#define N 100

using namespace std;

struct W {int w1; int w2;};
W edgematrix[N][N];


int main(int argc, char** argv){
  string line1, line2;
  int val1, val2;

  int u = 0; // là où je dois écrire dans la matrice
  int v = 0;

  assert(argc == 3); // nom du fichier en argument


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
        std::cout << endl;
      }
      // assert(u < N);
      std::cout << "(" << u << ","<< v <<")";
      edgematrix[u][v].w1 = val1;
      edgematrix[u][v].w2 = val2;
      v++;
    }
  myfile1.close();
  myfile2.close();
  return 0;
}
