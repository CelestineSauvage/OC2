#include "graph.hpp"

EdgesMatrix::EdgesMatrix() {}

void EdgesMatrix::addEdge(int u, int v, Ty weight){
  e_matrix[u][v] = weight;
}

Ty EdgesMatrix::getEdge(int u, int v){
  assert(0 <= u < e_n);
  assert(0 <= v < e_n);
  return e_matrix[u][v];
}
