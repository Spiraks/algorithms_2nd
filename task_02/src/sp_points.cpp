#include "sp_points.hpp"

#include <vector>

void Graph::AddEdge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

bool Graph::IsBridge(int u, int v) {
  // Удаление ребра (u, v)
  auto it = find(adj[u].begin(), adj[u].end(), v);
  adj[u].erase(it);

  it = find(adj[v].begin(), adj[v].end(), u);
  adj[v].erase(it);

  // Проверка связности
  std::vector<bool> visited(V, false);
  DFS(0, visited);

  // Восстановление графа
  AddEdge(u, v);

  // Проверка, является ли (u, v) мостом
  return !visited[u] || !visited[v];
}

void Graph::DFS(int v, std::vector<bool>& visited) {
  visited[v] = true;

  for (int u : adj[v]) {
    if (!visited[u]) {
      DFS(u, visited);
    }
  }
}

void Graph::FindCriticalEdges(std::vector<std::pair<size_t, size_t>>& edge) {
  std::vector<std::vector<bool>> visits(V, std::vector<bool>(V));
  for (int i = 0; i < V; ++i) {
    for (int j : adj[i]) {
      if (j > i && IsBridge(i, j) && !visits[i][j]) {
        visits[i][j] = true;
        edge.push_back({i, j});
      }
    }
  }
}
