#include "graph.hpp"
#include <iostream>
#include <stdexcept>

#define ASSERT_EQ(expected, actual, message) \
    if ((expected) != (actual)) { \
        std::cerr << "\033[31mERROR | " << message << ": Expected [" << expected << "], but got [" << actual << "]\033[0m\n"; \
    } else { \
        std::cout << "\033[32mPASS | " << message << "\033[0m\n"; \
    }

int main() {
    // Test 1: Add Vertex
    try {
        Graph<int> graph;
        graph.add_vertex(1);
        ASSERT_EQ(1, graph.size(), "Graph size after adding one vertex");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Add Vertex Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 2: Add Edge
    try {
        Graph<int> graph;
        graph.add_vertex(1);
        graph.add_vertex(2);
        graph.add_edge(1, 2);
        ASSERT_EQ(2, graph.size(), "Graph size after adding an edge between two vertices");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Add Edge Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 3: Add Edge with non-existent vertex
    try {
        Graph<int> graph;
        graph.add_vertex(1);
        graph.add_edge(1, 2);  // This should fail
        std::cerr << "\033[31mERROR | Add Edge with non-existent vertex Test Failed: Expected exception\n";
    } catch (const std::exception& e) {
        std::cout << "\033[32mPASS | Add Edge with non-existent vertex Test Passed: " << e.what() << "\033[0m\n";
    }

    // Test 4: Get Neighbors
    try {
        Graph<int> graph;
        graph.add_vertex(1);
        graph.add_vertex(2);
        graph.add_edge(1, 2);
        const auto& neighbors = graph.get_neighbors(1);
        ASSERT_EQ(1, neighbors.size(), "Number of neighbors for vertex 1");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Get Neighbors Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 5: Get Neighbors of non-existent vertex
    try {
        Graph<int> graph;
        graph.add_vertex(1);
        const auto& neighbors = graph.get_neighbors(2);  // This should fail
        std::cerr << "\033[31mERROR | Get Neighbors of non-existent vertex Test Failed: Expected exception\n";
    } catch (const std::exception& e) {
        std::cout << "\033[32mPASS | Get Neighbors of non-existent vertex Test Passed: " << e.what() << "\033[0m\n";
    }

    // Test 6: Large Graph (Big Data Test)
    try {
        Graph<int> graph;
        constexpr int BIG_DATA_SIZE = 10000000;
        for (int i = 0; i < BIG_DATA_SIZE; ++i) {
            graph.add_vertex(i);
        }
        ASSERT_EQ(BIG_DATA_SIZE, graph.size(), "Graph size after adding a large number of vertices");
        std::cout << "\033[32mPASS | Big Data Test: Added " << BIG_DATA_SIZE << " vertices to the graph\033[0m\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Big Data Test Failed: " << e.what() << "\033[0m\n";
    }

    std::cout << "\033[32mAll tests completed.\033[0m\n";
    return 0;
}

