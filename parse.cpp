#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <assert.h>

using namespace std;

typedef struct {int w1; int w2;} W;

int main(int argc, char** argv){
  string line1, line2;

  int to_read = 100; // nombre de lignes à lire
  int u,v = 0; // là où je dois écrire dans la matrice
  W* edgematrix[100][100];

  assert(argc == 3); // nom du fichier en argument

  ifstream myfile1, myfile2; // stream in
  myfile1.open (argv[1]); // randomA
  myfile2.open (argv[2]); // randomB

  for (int i =0; i < 6; i++){
    getline (myfile1,line1);
    getline (myfile2,line2);
    std::cout << line1;
  }
  {
    while ( getline (myfile1,line1) ){ // lit la ligne
      getline (myfile2,line2);
      int w1 = stoi (line1,nullptr); // string to int
      int w2 = stoi (line2, nullptr); // string to int
      if (v >= to_read){ // structure en escalier
        v = ++u;
      }
      edgematrix[u][v]->w1 = w1;
      edgematrix[u][v]->w2 = w2;
    }
  }
  myfile1.close();
  myfile2.close();
  return 0;
}
