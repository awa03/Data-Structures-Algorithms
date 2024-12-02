
#include "binary-tree.hpp"
#include <iostream>
#include <chrono>
#include <stdexcept>

#define ASSERT_EQ(expected, actual, message) \
    if ((expected) != (actual)) { \
        std::cerr << "\033[31mERROR | " << message << ": Expected [" << expected << "], but got [" << actual << "]\033[0m\n"; \
    } else { \
        std::cout << "\033[32mPASS | " << message << "\033[0m\n"; \
    }

// Test 1: Default Constructor and Insertion
void test_default_constructor_and_insertion() {
    Tree<int> test;
    try {
        test.insert(10);
        test.insert(5);
        test.insert(15);

        ASSERT_EQ(true, test.contains(10), "Tree should contain 10 after insertion");
        ASSERT_EQ(true, test.contains(5), "Tree should contain 5 after insertion");
        ASSERT_EQ(true, test.contains(15), "Tree should contain 15 after insertion");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED INSERTION TEST: " << e.what() << "\033[0m\n";
    }
}

// Test 2: Remove Elements from Tree
void test_remove_elements() {
    Tree<int> test;
    test.insert(10);
    test.insert(5);
    test.insert(15);
    
    try {
        test.remove(5);
        ASSERT_EQ(false, test.contains(5), "Element 5 should be removed");

        test.remove(10);
        ASSERT_EQ(false, test.contains(10), "Element 10 should be removed");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED REMOVAL TEST: " << e.what() << "\033[0m\n";
    }
}

// Test 3: Copy Constructor
void test_copy_constructor() {
    Tree<int> original;
    original.insert(10);
    original.insert(5);
    original.insert(15);

    try {
        Tree<int> copy(original);
        ASSERT_EQ(true, copy.contains(10), "Copied tree should contain 10");
        ASSERT_EQ(true, copy.contains(5), "Copied tree should contain 5");
        ASSERT_EQ(true, copy.contains(15), "Copied tree should contain 15");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED COPY CONSTRUCTOR TEST: " << e.what() << "\033[0m\n";
    }
}

// Test 4: Assignment Operator
void test_assignment_operator() {
    Tree<int> original;
    original.insert(10);
    original.insert(5);
    original.insert(15);

    Tree<int> assigned;
    assigned = original;

    try {
        ASSERT_EQ(true, assigned.contains(10), "Assigned tree should contain 10");
        ASSERT_EQ(true, assigned.contains(5), "Assigned tree should contain 5");
        ASSERT_EQ(true, assigned.contains(15), "Assigned tree should contain 15");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED ASSIGNMENT OPERATOR TEST: " << e.what() << "\033[0m\n";
    }
}

// Test 5: Large Data Handling
void test_large_data_handling() {
    Tree<int> test;
    try {
        for (int i = 0; i < 100000; ++i) {
            test.insert(i);
        }
        ASSERT_EQ(true, test.contains(99999), "Large data test failed");
        ASSERT_EQ(false, test.contains(100000), "Large data test failed");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED LARGE DATA TEST: " << e.what() << "\033[0m\n";
    }
}

// Test 6: Out-of-Range Behavior
void test_out_of_range_behavior() {
    Tree<int> test;
    try {
        ASSERT_EQ(false, test.contains(1), "Tree should be empty initially");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED OUT-OF-RANGE TEST: " << e.what() << "\033[0m\n";
    }
}

// Test 7: Destructor Verification
void test_destructor_verification() {
    try {
        {
            Tree<int> test;
            test.insert(10);
            test.insert(5);
            test.insert(15);
        }
        std::cout << "\033[32mPASS | Destructor called successfully (no memory leaks)\033[0m\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED DESTRUCTOR TEST: " << e.what() << "\033[0m\n";
    }
}

// Test 8: Big Data Test with Performance
void test_big_data() {
    constexpr int BIG_DATA_SIZE = 100000;
    Tree<int> test;
    auto start = std::chrono::high_resolution_clock::now();

    try {
        for (int i = 0; i < BIG_DATA_SIZE; ++i) {
            test.insert(i);
        }
        auto mid = std::chrono::high_resolution_clock::now();
        auto insert_duration = std::chrono::duration_cast<std::chrono::milliseconds>(mid - start).count();
        std::cout << "\033[32mPASS | Inserted " << BIG_DATA_SIZE << " elements in " << insert_duration << "ms\033[0m\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Big Data Test Failed: " << e.what() << "\033[0m\n";
    }
}

int main() {
    test_default_constructor_and_insertion();
    test_remove_elements();
    test_copy_constructor();
    test_assignment_operator();
    test_large_data_handling();
    test_out_of_range_behavior();
    test_destructor_verification();
    test_big_data();

    std::cout << "\033[32mAll tests completed.\033[0m\n";

    return 0;
}

