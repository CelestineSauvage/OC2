#include "Instance.h"
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>


////////////////////////////////////////////////////////////////////////////
Instance::Instance(std::string filename1, std::string filename2)
{
  int val1, val2;
  std::string line1, line2;
  std::ifstream myfile1, myfile2;

  myfile1.open (filename1); // randomA
  myfile2.open (filename2); // randomB
  assert(myfile1.is_open() && myfile2.is_open());


  // on remplit la matrice
  for (int i = 0; i < 100; i++){
    for (int j = i; j < 100; j++){
      myfile1 >> val1;
      myfile2 >> val2;
      edgematrix[i][j].push_back(val1);
      edgematrix[j][i].push_back(val1);
      edgematrix[i][j].push_back(val2);
      edgematrix[j][i].push_back(val2);
    }
  }

  myfile1.close();
  myfile2.close();
}

std::vector<int> *Instance::getValue(int i, int j){
  return &edgematrix[i][j];
}

void Instance::toPrint(){
  for (int i = 0; i < 100; i++) {
        for (int j = i; j < 100; j++)
            std::cout << "(" << edgematrix[i][j][0] << " " << edgematrix[i][j][1] << ") ";
        std::cout << std::endl;
    }

}
