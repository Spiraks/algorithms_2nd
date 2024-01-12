#include <iostream>
#include <vector>

#include "topology_sort.hpp"

int main() {
  Graph g(6);
  g.AddEdge(5, 2);
  g.AddEdge(5, 0);
  g.AddEdge(4, 0);
  g.AddEdge(4, 1);
  g.AddEdge(2, 3);
  g.AddEdge(3, 1);

  std::vector<int> result = g.TopologicalSort();

  if (result.empty()) {
    std::cout
        << "Граф содержит цикл, невозможно выполнить топологическую сортировку."
        << std::endl;
  } else {
    std::cout << "Топологическая сортировка: ";
    for (int vertex : result) {
      std::cout << vertex << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
