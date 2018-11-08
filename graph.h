#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <typename Ty, int N, int M>
class EdgesMatrix {
  typedef Ty value_type;

  public:
    // Constructor
    EdgesMatrix(int N, int M);

    // Destructor
    ~EdgesMatrix();

    // ajouter un arc dans dans le graphe
    // void addEdge(int u, int v, Ty weight);

    Ty getEdge(int u, int v);


  private:
    int e_n = 100;
    Ty e_matrix[100][100];
};

#endif
