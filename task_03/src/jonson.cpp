#include "jonson.hpp"

#include <cstddef>
#include <vector>

int Graph::GetVertexCount() { return vertex_count; }
int Graph::GetEdgesCount() { return edges_count; }

void Graph::ReadGraph(std::vector<std::vector<int>> weight_matrix) {
  this->vertex_count = weight_matrix[0].size();
  this->v.resize(vertex_count);

  for (size_t i = 0; i < vertex_count; i++) {
    v[i].weight = INF;
    v[i].index = i;
    v[i].color = NodeColor::White;

    for (size_t j = 0; j < vertex_count; j++) {
      Edge temp_edge;

      if (weight_matrix[i][j] == INF) continue;

      temp_edge.from = i;
      temp_edge.to = j;
      temp_edge.weight = weight_matrix[i][j];
      this->edges.push_back(temp_edge);
    }
  }

  for (size_t i = 0; i < vertex_count; i++) {
    Edge imag_edge;
    imag_edge.from = vertex_count;
    imag_edge.to = i;
    imag_edge.weight = 0;
    this->edges.push_back(imag_edge);
  }

  this->edges_count = edges.size();
}

int Graph::Dijkstra(size_t start_index, size_t end_index) {
  std::multimap<int, size_t> min_weight_map;
  this->v[start_index].weight = 0;
  min_weight_map.insert({0, start_index});
  while (!min_weight_map.empty()) {
    auto [current_weight, current_index] = *(min_weight_map.begin());
    min_weight_map.erase(min_weight_map.begin());

    if (this->v[current_index].color != NodeColor::White) continue;

    this->v[current_index].color = NodeColor::Grey;

    for (size_t i = 0; i < this->v[current_index].edges.size(); i++) {
      int index_to = this->v[current_index].edges[i].to;
      int edge_weight = this->v[current_index].edges[i].weight;
      if (this->v[index_to].color == NodeColor::White) {
        if (current_weight + edge_weight < this->v[index_to].weight &&
            current_weight + edge_weight >= 0) {
          this->v[index_to].weight = current_weight + edge_weight;
          min_weight_map.insert({this->v[index_to].weight, index_to});
        }
      }
    }
  }

  int ans = this->v[end_index].weight;
  return ans;
}

std::vector<int> Graph::FordBelman(size_t start_vertex) {
  std::vector<int> distances(vertex_count + 1, INF);
  distances[start_vertex] = 0;

  bool x;
  for (size_t i = 0; i < vertex_count; ++i) {
    x = true;
    for (size_t j = 0; j < edges_count; ++j)
      if (distances[edges[j].from] < INF)
        if (distances[edges[j].to] >
            distances[edges[j].from] + edges[j].weight) {
          distances[edges[j].to] =
              std::min(distances[edges[j].to],
                       distances[edges[j].from] + edges[j].weight);
          x = false;
        }
  }

  std::vector<int> cycle{0};
  if (!x) return cycle;

  return distances;
}

void Graph::DijkstraPreparation() {
  for (size_t i = 0; i < vertex_count; i++) {
    this->v[i].edges.resize(vertex_count);
    this->v[i].weight = INF;
    this->v[i].color = NodeColor::White;
    for (size_t j = 0; j < vertex_count; j++) {
      this->v[i].edges[j].weight = INF;
      this->v[i].edges[j].to = j;
    }
  }

  for (auto it = edges.begin(); it != edges.end(); it++) {
    this->v[it->from].edges[it->to].weight = it->weight;
    this->v[it->from].edges[it->to].to = it->to;
  }
}

std::vector<std::vector<int>> Graph::Jonson() {
  std::vector<int> potentials = FordBelman(vertex_count);
  std::vector<std::vector<int>> cycle = {{0}};
  if (potentials.size() == 1 && potentials[0] == 0) return cycle;

  for (size_t i = 0; i < vertex_count; i++) edges.pop_back();

  for (auto it = edges.begin(); it != edges.end(); it++)
    it->weight += potentials[it->from] - potentials[it->to];
  DijkstraPreparation();
  std::vector<std::vector<int>> answer(vertex_count,
                                       std::vector<int>(vertex_count, 0));
  for (size_t i = 0; i < vertex_count; i++) {
    for (size_t j = 0; j < vertex_count; j++) answer[i][j] = Dijkstra(i, j);
    DijkstraPreparation();
  }

  for (size_t i = 0; i < answer.size(); i++)
    for (size_t j = 0; j < answer[0].size(); j++) {
      if (answer[i][j] == INF) continue;

      int difference = potentials[j] - potentials[i];
      answer[i][j] += difference;
    }

  return answer;
}