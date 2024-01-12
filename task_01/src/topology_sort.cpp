#include "topology_sort.hpp"

#include <vector>

void Graph::AddEdge(int u, int v) { adjacencyList[u].push_back(v); }

std::vector<int> Graph::TopologicalSort() {
  std::vector<int> inDegree(vertices, 0);

  for (int i = 0; i < vertices; ++i) {
    for (int neighbor : adjacencyList[i]) {
      ++inDegree[neighbor];
    }
  }

  std::queue<int> q;
  for (int i = 0; i < vertices; ++i) {
    if (inDegree[i] == 0) {
      q.push(i);
    }
  }

  std::vector<int> result;
  while (!q.empty()) {
    int current = q.front();
    q.pop();
    result.push_back(current);

    for (int neighbor : adjacencyList[current]) {
      --inDegree[neighbor];
      if (inDegree[neighbor] == 0) {
        q.push(neighbor);
      }
    }
  }

  if (result.size() != vertices) {
    return std::vector<int>();
  }

  return result;
}