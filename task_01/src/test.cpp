#include <gtest/gtest.h>

#include "topology_sort.hpp"

TEST(TopologicalSort, SimpleGraph1) {
  Graph graph(6);
  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);
  graph.AddEdge(2, 3);
  graph.AddEdge(3, 4);
  graph.AddEdge(4, 5);
  std::vector<int> result{0, 1, 2, 3, 4, 5};
  ASSERT_EQ(graph.TopologicalSort(), result);
}

TEST(TopologicalSort, SimpleGraph2) {
  Graph graph(6);
  graph.AddEdge(5, 2);
  graph.AddEdge(5, 0);
  graph.AddEdge(4, 0);
  graph.AddEdge(4, 1);
  graph.AddEdge(2, 3);
  graph.AddEdge(3, 1);
  std::vector<int> result{4, 5, 2, 0, 3, 1};
  ASSERT_EQ(graph.TopologicalSort(), result);
}

TEST(TopologicalSort, GraphWithCycleInOneVertex) {
  Graph graph(3);
  graph.AddEdge(0, 0);
  graph.AddEdge(0, 2);
  graph.AddEdge(1, 2);
  std::vector<int> result{};
  ASSERT_EQ(graph.TopologicalSort(), result);
}

TEST(TopologicalSort, AdvancedGraph) {
  Graph graph(12);
  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(3, 5);
  graph.AddEdge(4, 5);
  graph.AddEdge(5, 6);
  graph.AddEdge(5, 7);
  graph.AddEdge(3, 8);
  graph.AddEdge(8, 9);
  graph.AddEdge(9, 10);
  graph.AddEdge(9, 11);
  std::vector<int> result{0, 4, 1, 2, 3, 5, 8, 6, 7, 9, 10, 11};
  ASSERT_EQ(graph.TopologicalSort(), result);
}

