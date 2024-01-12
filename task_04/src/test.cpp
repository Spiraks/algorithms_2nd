#include "gtest/gtest.h"

#include "deikstr.hpp" 

TEST(DijkstraAlgorithm, SimpleGraph) {
    std::vector<std::vector<int>> weightMatrix = {
            {0, 2, 4, INF, INF},
            {INF, 0, 1, 7, INF},
            {INF, INF, 0, INF, 3},
            {INF, INF, INF, 0, 2},
            {INF, INF, INF, INF, 0}
        };

        Graph graph;
        graph.ReadGraph(weightMatrix);

        auto result = graph.FindPath(0, 4);
        vector_t expectedPath = {0, 1, 2, 4};
        int expectedWeight = 6;
        ASSERT_EQ(result.first, expectedPath);
        ASSERT_EQ(result.second, expectedWeight);
}

TEST(DijkstraAlgorithm, DisconnectedGraph) {
        std::vector<std::vector<int>> weightMatrix = {
            {0, 5, INF, INF, INF},
            {INF, 0, 2, 1, INF},
            {INF, INF, 0, INF, 4},
            {INF, INF, INF, 0, INF},
            {INF, INF, INF, INF, 0}
        };

        Graph graph;
        graph.ReadGraph(weightMatrix);

        auto result = graph.FindPath(0, 4);
        vector_t expectedPath = {0, 1, 2, 4};
        int expectedWeight = 11;

        ASSERT_EQ(result.first, expectedPath);
        ASSERT_EQ(result.second, expectedWeight);
        std::cout << "Test Case 2 Passed!\n";
    }
