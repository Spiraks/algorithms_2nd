#include <cstddef>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#include "sp_points.hpp"

int main() {
  Graph network(4);

  network.AddEdge(0, 1);
  network.AddEdge(1, 2);
  network.AddEdge(2, 3);
  std::vector<std::pair<size_t, size_t>> edge;
  network.FindCriticalEdges(edge);
  for (auto pair : edge) {
      std::cout << "Critical Edge: " << pair.first << " - " << pair.second << std::endl;
  }

  return 0;
}
