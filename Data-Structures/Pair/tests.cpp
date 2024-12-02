
#include "pair.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <chrono>

#define ASSERT_EQ(expected, actual, message) \
    if ((expected) != (actual)) { \
        std::cerr << "\033[31mERROR | " << message << ": Expected [" << expected << "], but got [" << actual << "]\033[0m\n"; \
    } else { \
        std::cout << "\033[32mPASS | " << message << "\033[0m\n"; \
    }

int main() {
    // Test 1: Default Constructor
    try {
        pair<int, double> p1(10, 20.5);
        ASSERT_EQ(10, p1.first, "First value of pair after initialization");
        ASSERT_EQ(20.5, p1.second, "Second value of pair after initialization");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Default Constructor Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 2: Assignment Operator
    try {
        pair<int, double> p1(10, 20.5);
        pair<int, double> p2(30, 40.5);
        p2 = p1;
        ASSERT_EQ(10, p2.first, "First value of pair after assignment");
        ASSERT_EQ(20.5, p2.second, "Second value of pair after assignment");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Assignment Operator Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 3: Assigning a pair to itself
    try {
        pair<int, double> p1(10, 20.5);
        p1 = p1;  // Self-assignment
        ASSERT_EQ(10, p1.first, "First value of pair after self-assignment");
        ASSERT_EQ(20.5, p1.second, "Second value of pair after self-assignment");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Self-Assignment Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 4: Comparison of pairs
    try {
        pair<int, double> p1(10, 20.5);
        pair<int, double> p2(10, 20.5);
        pair<int, double> p3(15, 25.5);
        ASSERT_EQ(true, (p1.first == p2.first && p1.second == p2.second), "Comparing two equal pairs");
        ASSERT_EQ(false, (p1.first == p3.first && p1.second == p3.second), "Comparing two unequal pairs");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Comparison of Pairs Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 5: Different Type Pair
    try {
        pair<std::string, bool> p1("hello", true);
        ASSERT_EQ("hello", p1.first, "First value of pair with different types");
        ASSERT_EQ(true, p1.second, "Second value of pair with different types");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Different Type Pair Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 6: Big Data Test using std::vector
    try {
        constexpr int BIG_DATA_SIZE = 100'000'000;
        std::vector<pair<int, double>> pairs;

        // Start the timer
        auto start = std::chrono::high_resolution_clock::now();

        // Properly initialize each pair in the vector
        for (int i = 0; i < BIG_DATA_SIZE; ++i) {
            pairs.push_back(pair<int, double>(i, i * 1.5));
        }

        // Stop the timer after insertion
        auto end = std::chrono::high_resolution_clock::now();

        // Calculate and print the elapsed time
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        
        ASSERT_EQ(100000000, pairs.size(), "Size of pairs after big data insertion");
        std::cout << "\033[32mPASS | Big Data Test: Successfully created " << BIG_DATA_SIZE << " pairs in " 
                  << duration << "ms\033[0m\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Big Data Test Failed: " << e.what() << "\033[0m\n";
    }

    std::cout << "\033[32mAll tests completed.\033[0m\n";
    return 0;
}

