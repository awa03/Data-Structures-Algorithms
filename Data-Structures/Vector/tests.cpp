
#include "vector.hpp"
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
    Vector<int> test;
    try {
        test.push_back(1);
        ASSERT_EQ(1, test[0], "First element should be 1");
        
        test.push_back(2);
        ASSERT_EQ(2, test[1], "Second element should be 2");

        test.push_back(3);
        ASSERT_EQ(3, test[2], "Third element should be 3");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED INSERTION TEST: " << e.what() << "\033[0m\n";
    }
}

// Test 2: Empty Functionality
void test_empty_functionality() {
    Vector<int> test;
    try {
        test.push_back(1);
        test.clear();
        ASSERT_EQ(0, test.size(), "Size after clear should be 0");
        ASSERT_EQ(true, test.isEmpty(), "Vector should be empty after clearing");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED EMPTY TEST: " << e.what() << "\033[0m\n";
    }
}

// Test 3: Initializer List Constructor
void test_initializer_list_constructor() {
    Vector<int> test1({1, 2, 3, 4, 5});
    try {
        ASSERT_EQ(5, test1.size(), "Size of vector should be 5");
        ASSERT_EQ(3, test1[2], "Third element should be 3");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED INITIALIZER LIST TEST: " << e.what() << "\033[0m\n";
    }
}

// Test 4: Copy Assignment and Comparison
void test_copy_assignment_and_comparison() {
    Vector<int> test1({1, 2, 3, 4, 5});
    Vector<int> test3;
    try {
        test3 = test1;
        ASSERT_EQ(true, (test1 == test3), "Vectors should be equal after copy assignment");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED COPY/COMPARE TEST: " << e.what() << "\033[0m\n";
    }
}

// Test 5: Large Data Handling
void test_large_data_handling() {
    Vector<int> test;
    try {
        for (int i = 0; i < 1'000'000; ++i) {
            test.push_back(i);
        }
        ASSERT_EQ(1'000'000, test.size(), "Size should be 1,000,000 after insertion");

        for (int i = 0; i < 100'000; ++i) {
            test[i + 1] = test[i];
        }
        ASSERT_EQ(test[100], test[99], "Modification of elements failed");

        for (int i = 0; i < 100'000; ++i) {
            test.pop_back();
        }
        ASSERT_EQ(900'000, test.size(), "Size should be 900,000 after popping 100,000 elements");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED LARGE DATA TEST: " << e.what() << "\033[0m\n";
    }
}

// Test 6: Out-of-Range Access
void test_out_of_range_access() {
    Vector<int> test({1, 2, 3, 4, 5});
    try {
        test[100]; // Should throw exception
    } catch (const std::out_of_range& e) {
        std::cout << "\033[33mExpected Error | " << e.what() << "\033[0m\n";
    }
}

// Test 7: Resize Handling
void test_resize_handling() {
    Vector<int> test({10, 20, 30});
    try {
        test.push_back(40);
        test.push_back(50);
        ASSERT_EQ(5, test.size(), "Size should be 5 after pushing 2 elements");
        ASSERT_EQ(50, test[4], "Last element should be 50 after resizing");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED RESIZE TEST: " << e.what() << "\033[0m\n";
    }
}

int main() {
    test_default_constructor_and_insertion();
    test_empty_functionality();
    test_initializer_list_constructor();
    test_copy_assignment_and_comparison();
    test_large_data_handling();
    test_out_of_range_access();
    test_resize_handling();

    std::cout << "\033[32mAll tests completed.\033[0m\n";
    return 0;
}

