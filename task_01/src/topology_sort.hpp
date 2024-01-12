#pragma once

#include <vector>
#include <queue>

class Graph {
private:
    int vertices;
    std::vector<std::vector<int>> adjacencyList;

public:
    Graph(int v) : vertices(v), adjacencyList(v) {}
    void AddEdge(int u, int v);
    std::vector<int> TopologicalSort();
};