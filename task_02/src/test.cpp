#include <gtest/gtest.h>
#include "sp_points.hpp"  // Подключите ваш заголовочный файл

TEST(FindCutEdges, Simple) {
    Graph graph(5);
    graph.AddEdge(0, 1);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    std::vector<std::pair<size_t, size_t>> edge;
    graph.FindCriticalEdges(edge);
    std::vector<std::pair<size_t, size_t>> result{{0,1},{1,2},{2,3},{3,4}};
    ASSERT_EQ(edge, result);
}

TEST(FindCutEdges, Loop) {
    Graph graph(5);
    graph.AddEdge(0, 1);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(0, 4);

    std::vector<std::pair<size_t, size_t>> edge;
    graph.FindCriticalEdges(edge);
    std::vector<std::pair<size_t, size_t>> result;
    ASSERT_EQ(edge, result);
}