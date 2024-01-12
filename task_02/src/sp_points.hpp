#ifndef SPECIAL_POINTS_H
#define SPECIAL_POINTS_H
#include <vector>

class Graph {
  int V;
  std::vector<std::vector<int>> adj;

 public:
  Graph(int vertices) : V(vertices), adj(vertices) {}
  void AddEdge(int u, int v);
  bool IsBridge(int u, int v);
  void DFS(int v, std::vector<bool>& visited);
  void FindCriticalEdges(std::vector<std::pair<size_t, size_t>>& edge);
};

#endif // SPECIAL_POINTS_H
