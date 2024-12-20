
#include "linear-search.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <chrono>

#define ASSERT_EQ(expected, actual, message) \
    if ((expected) != (actual)) { \
        std::cerr << "\033[31mERROR | " << message << ": Expected [" << expected << "], but got [" << actual << "]\033[0m\n"; \
    } else { \
        std::cout << "\033[32mPASS | " << message << "\033[0m\n"; \
    }

// Test 1: Search for an element that exists in the vector
void test_search_element_exists() {
    std::vector<int> test = {1, 3, 5, 7, 9, 11};
    try {
        int result = linear_search<int>(test, 5);
        ASSERT_EQ(5, result, "Search for 5 in vector [1, 3, 5, 7, 9, 11]");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | SEARCH TEST FAILED: " << e.what() << "\033[0m\n";
    }
}

// Test 2: Search for a value that doesn't exist in the vector
void test_search_element_does_not_exist() {
    std::vector<int> test = {1, 3, 5, 7, 9, 11};
    try {
        int result = linear_search<int>(test, 4);
        std::cerr << "\033[31mERROR | Expected exception, got result [" << result << "]\033[0m\n";
    } catch (const std::logic_error& e) {
        std::cout << "\033[32mPASS | " << e.what() << "\033[0m\n";
    }
}

// Test 3: Search in an empty vector
void test_search_empty_vector() {
    std::vector<int> test = {};
    try {
        int result = linear_search<int>(test, 5);
        std::cerr << "\033[31mERROR | Expected exception, got result [" << result << "]\033[0m\n";
    } catch (const std::logic_error& e) {
        std::cout << "\033[32mPASS | " << e.what() << "\033[0m\n";
    }
}

// Test 4: Search for a value at the first position in the vector
void test_search_first_position() {
    std::vector<int> test = {1, 3, 5, 7, 9, 11};
    try {
        int result = linear_search<int>(test, 1);
        ASSERT_EQ(1, result, "Search for 1 at the beginning of vector [1, 3, 5, 7, 9, 11]");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | SEARCH TEST FAILED: " << e.what() << "\033[0m\n";
    }
}

// Test 5: Search for a value at the last position in the vector
void test_search_last_position() {
    std::vector<int> test = {1, 3, 5, 7, 9, 11};
    try {
        int result = linear_search<int>(test, 11);
        ASSERT_EQ(11, result, "Search for 11 at the end of vector [1, 3, 5, 7, 9, 11]");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | SEARCH TEST FAILED: " << e.what() << "\033[0m\n";
    }
}

// Test 6: Search for a value in a single-element vector (present)
void test_search_single_element_present() {
    std::vector<int> test = {10};
    try {
        int result = linear_search<int>(test, 10);
        ASSERT_EQ(10, result, "Search for 10 in single-element vector [10]");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | SEARCH TEST FAILED: " << e.what() << "\033[0m\n";
    }
}

// Test 7: Search for a value in a single-element vector (not present)
void test_search_single_element_not_present() {
    std::vector<int> test = {10};
    try {
        int result = linear_search<int>(test, 5);
        std::cerr << "\033[31mERROR | Expected exception, got result [" << result << "]\033[0m\n";
    } catch (const std::logic_error& e) {
        std::cout << "\033[32mPASS | " << e.what() << "\033[0m\n";
    }
}

// Test 8: Big Data Search
void test_big_data_search() {
    constexpr int BIG_DATA_SIZE = 100000000; // 1 million elements
    std::vector<int> test;
    for (int i = 0; i < BIG_DATA_SIZE; ++i) {
        test.push_back(i);
    }

    auto start = std::chrono::high_resolution_clock::now();
    try {
        int result = linear_search<int>(test, BIG_DATA_SIZE -1); 
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "\033[32mPASS | Search for element " << BIG_DATA_SIZE -1 
                  << " in big data took " << duration << "ms\033[0m\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Big Data Search (Element Found) FAILED: " << e.what() << "\033[0m\n";
    }

    // Search for an element that doesn't exist
    start = std::chrono::high_resolution_clock::now();
    try {
        int result = linear_search<int>(test, BIG_DATA_SIZE + 1); // Searching for an element that doesn't exist
        std::cerr << "\033[31mERROR | Expected exception, got result [" << result << "]\033[0m\n";
    } catch (const std::logic_error& e) {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "\033[32mPASS | Search for non-existent element took " << duration 
                  << "ms and correctly threw exception: " << e.what() << "\033[0m\n";
    }
}

int main() {
    test_search_element_exists();
    test_search_element_does_not_exist();
    test_search_empty_vector();
    test_search_first_position();
    test_search_last_position();
    test_search_single_element_present();
    test_search_single_element_not_present();
    test_big_data_search(); // Run the big data search test

    std::cout << "\033[32mAll tests completed.\033[0m\n";
    return 0;
}

