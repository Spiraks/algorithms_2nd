
#include <gtest/gtest.h>
#include "jonson.hpp"
#include <iostream>
#include <cassert>

TEST(JonsonTest, FordBelman) {
    
    Graph graph;
    std::vector<std::vector<int>> weight_matrix = {
        {0, 2, INF, 1},
        {INF, 0, 4, INF},
        {INF, INF, 0, 3},
        {INF, INF, INF, 0}
    };

    graph.ReadGraph(weight_matrix);

    std::vector<int> distances = graph.FordBelman(0);

    // Assuming correct distances are calculated
    assert(distances[0] == 0);
    assert(distances[1] == 2);
    assert(distances[2] == 6);
    assert(distances[3] == 1);

}

TEST(JonsonTest, Jonson) {
    
    Graph graph;
    std::vector<std::vector<int>> weight_matrix = {
        {0, 2, INF, 1},
        {INF, 0, 4, INF},
        {INF, INF, 0, 3},
        {INF, INF, INF, 0}
    };
    graph.ReadGraph(weight_matrix);
    std::vector<std::vector<int>> result_matrix = graph.Jonson();

    // Assuming correct result matrix calculation

    assert(result_matrix[0][0] == 0);
    assert(result_matrix[0][1] == 2);
    assert(result_matrix[0][2] == 6);
    assert(result_matrix[0][3] == 1);

    // Other assertions for the remaining rows

    std::cout << "Jonson test passed!" << std::endl;

}

TEST(JonsonTest, Jonson1) {
    Graph graph;
    std::vector<std::vector<int>> weight_matrix = {
        {0, 2, INF, -1},
        {INF, 0, -4, INF},
        {INF, INF, 0, -3},
        {INF, INF, INF, 0}
    };
    graph.ReadGraph(weight_matrix);
    std::vector<std::vector<int>> result_matrix = graph.Jonson();
    assert(result_matrix[0][0] == 0);
    assert(result_matrix[0][1] == 2);
    assert(result_matrix[0][2] == -2);
    assert(result_matrix[0][3] == -1);
}

TEST(JonsonTest, Jonson2) {
    Graph graph;
    std::vector<std::vector<int>> weight_matrix = {
        {INF, INF, INF, INF},
        {INF, INF, INF, INF},
        {INF, INF, INF, INF},
        {INF, INF, INF, INF}
    };
    graph.ReadGraph(weight_matrix);
    std::vector<std::vector<int>> result_matrix = graph.Jonson();

    assert(result_matrix[0][0] == 0);
    assert(result_matrix[1][1] == 0);
    assert(result_matrix[2][2] == 0);
    assert(result_matrix[3][3] == 0);
}





