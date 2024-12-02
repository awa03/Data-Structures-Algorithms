#include "hash-set.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

#define ASSERT_EQ(expected, actual, message) \
    if ((expected) != (actual)) { \
        std::cerr << "\033[31mERROR | " << message << ": Expected [" << expected << "], but got [" << actual << "]\033[0m\n"; \
    } else { \
        std::cout << "\033[32mPASS | " << message << "\033[0m\n"; \
    }

int main() {
    // Test 1: Default Constructor
    try {
        hash_set<int> set1;
        ASSERT_EQ(0, set1.size(), "Set size after creation");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Default Constructor Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 2: Insert Elements
    try {
        hash_set<int> set1;
        set1.insert(10);
        set1.insert(20);
        set1.insert(30);
        ASSERT_EQ(3, set1.size(), "Set size after inserting 3 elements");
        ASSERT_EQ(true, set1.contains(10), "Set contains 10");
        ASSERT_EQ(true, set1.contains(20), "Set contains 20");
        ASSERT_EQ(true, set1.contains(30), "Set contains 30");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Insert Elements Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 3: Insert Duplicate Elements
    try {
        hash_set<int> set1;
        set1.insert(10);
        set1.insert(10);  // Duplicate insert
        ASSERT_EQ(1, set1.size(), "Set size after inserting duplicate element");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Insert Duplicate Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 4: Remove Elements
    try {
        hash_set<int> set1;
        set1.insert(10);
        set1.insert(20);
        set1.remove(10);
        ASSERT_EQ(1, set1.size(), "Set size after removing 1 element");
        ASSERT_EQ(false, set1.contains(10), "Set does not contain 10 after removal");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Remove Elements Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 5: Clear Set
    try {
        hash_set<int> set1;
        set1.insert(10);
        set1.insert(20);
        set1.clear();
        ASSERT_EQ(0, set1.size(), "Set size after clearing");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Clear Set Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 6: Large Data Insert and Clear Test
    try {
        hash_set<int> set1;
        for (int i = 0; i < 10000000; ++i) {
            set1.insert(i);
        }
        ASSERT_EQ(10000000, set1.size(), "Set size after inserting 10 million elements");

        set1.clear();
        ASSERT_EQ(0, set1.size(), "Set size after clearing");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Large Data Test Failed: " << e.what() << "\033[0m\n";
    }

    return 0;
}
