#include "hash-map.hpp"
#include <iostream>
#include <chrono>
#include <stdexcept>

#define ASSERT_EQ(expected, actual, message) \
    if ((expected) != (actual)) { \
        std::cerr << "\033[31mERROR | " << message << ": Expected [" << expected << "], but got [" << actual << "]\033[0m\n"; \
    } else { \
        std::cout << "\033[32mPASS | " << message << "\033[0m\n"; \
    }

int main() {
    try {
        // Test 1: Default Constructor and Size
        hash_map<std::string, int> map;
        ASSERT_EQ(0, map.size(), "Default constructor initializes size to 0");
        ASSERT_EQ(true, map.empty(), "Default constructor initializes an empty map");

        // Test 2: Insert and Size
        map.insert("Alice", 25);
        map.insert("Bob", 30);
        ASSERT_EQ(2, map.size(), "Size after inserting two elements");

        // Test 3: Retrieve Values
        ASSERT_EQ(25, map.at("Alice"), "Retrieve Alice's age");
        ASSERT_EQ(30, map.at("Bob"), "Retrieve Bob's age");

        // Test 4: Update Existing Key
        map.insert("Alice", 35);
        ASSERT_EQ(35, map.at("Alice"), "Update Alice's age to 35");

        // Test 5: Contains
        ASSERT_EQ(true, map.contains("Alice"), "Contains should return true for Alice");
        ASSERT_EQ(false, map.contains("Charlie"), "Contains should return false for Charlie");

        // Test 6: Remove Key
        ASSERT_EQ(true, map.remove("Alice"), "Remove Alice from the map");
        ASSERT_EQ(false, map.contains("Alice"), "Alice should no longer be in the map");
        ASSERT_EQ(1, map.size(), "Size after removing one element");

        // Test 7: Remove Non-Existent Key
        ASSERT_EQ(false, map.remove("Charlie"), "Removing non-existent key should return false");

        // Test 8: Clear
        map.clear();
        ASSERT_EQ(0, map.size(), "Size after clearing the map");
        ASSERT_EQ(true, map.empty(), "Map should be empty after clear");

        // Test 9: Exception on Missing Key
        try {
            map.at("NonExistent");
            std::cerr << "\033[31mERROR | No exception thrown for missing key\033[0m\n";
        } catch (const std::out_of_range& e) {
            std::cout << "\033[32mPASS | Exception thrown for missing key: " << e.what() << "\033[0m\n";
        }

        // Test 10: Collision Handling
        hash_map<int, int> collision_map(2); // Small bucket count to force collisions
        collision_map.insert(1, 100);
        collision_map.insert(3, 300); // Assume hash(1) and hash(3) collide
        ASSERT_EQ(100, collision_map.at(1), "Retrieve value for key 1");
        ASSERT_EQ(300, collision_map.at(3), "Retrieve value for key 3");
        ASSERT_EQ(2, collision_map.size(), "Size after inserting two colliding elements");


    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Test Failed: " << e.what() << "\033[0m\n";
    }

 try {
        hash_map<int, int> map;

        // Big Data Insert Test
        auto start_insert = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10'000'000; ++i) {
            map.insert(i, i * 2);
        }
        auto end_insert = std::chrono::high_resolution_clock::now();

        ASSERT_EQ(10'000'000, map.size(), "Map size after inserting 1 million elements");

        auto insert_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_insert - start_insert).count();
        std::cout << "\033[32mINFO | Insert Time: " << insert_duration << " ms\033[0m\n";

        // Big Data Clear Test
        auto start_clear = std::chrono::high_resolution_clock::now();
        map.clear();
        auto end_clear = std::chrono::high_resolution_clock::now();

        ASSERT_EQ(0, map.size(), "Map size after clearing all elements");

        auto clear_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_clear - start_clear).count();
        std::cout << "\033[32mINFO | Clear Time: " << clear_duration << " ms\033[0m\n";

    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Big Data Test Failed: " << e.what() << "\033[0m\n";
    }


    std::cout << "\033[32mAll tests completed.\033[0m\n";
    return 0;
}

