#ifndef INSTANCE_H_
#define INSTANCE_H_

#include <vector>
#include <string>

class Instance
{
  public :
    //Constructeurs
    Instance(std::string filename1, std::string filename2);

    //Accesseurs et mutateurs
    std::vector<int> *getValue(int i, int j);
    void toPrint();
    // void setValue(int i, int j);
  private:
    std::vector<int> edgematrix[100][100];
};

#endif
