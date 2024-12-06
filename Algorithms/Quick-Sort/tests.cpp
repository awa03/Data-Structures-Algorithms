#include "quick-sort.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <sstream>

// Converts a vector to a string for printing
template<typename T>
std::string vector_to_string(const std::vector<T>& vec) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        oss << vec[i];
        if (i < vec.size() - 1) {
            oss << ", ";
        }
    }
    oss << "]";
    return oss.str();
}

// Updated ASSERT_EQ macro
#define ASSERT_EQ(expected, actual, message) \
    if ((expected) != (actual)) { \
        std::cerr << "\033[31mERROR | " << message << ": Expected " \
                  << vector_to_string(expected) << ", but got " << vector_to_string(actual) << "\033[0m\n"; \
    } else { \
        std::cout << "\033[32mPASS | " << message << "\033[0m\n"; \
    }

// Custom is_sorted implementation
template<typename Iterator>
bool sorted(Iterator begin, Iterator end) {
    if (begin == end) return true; // Empty range is sorted
    Iterator next = begin;
    ++next;
    while (next != end) {
        if (*next < *begin) {
            return false;
        }
        ++begin;
        ++next;
    }
    return true;
}

// Test 1: Sort an already sorted vector
void test_already_sorted() {
    std::vector<int> test = {1, 2, 3, 4, 5};
    quick_sort(test);
    ASSERT_EQ(std::vector<int>({1, 2, 3, 4, 5}), test, "Sort an already sorted vector");
}

// Test 2: Sort a reversed vector
void test_reversed_vector() {
    std::vector<int> test = {5, 4, 3, 2, 1};
    quick_sort(test);
    ASSERT_EQ(std::vector<int>({1, 2, 3, 4, 5}), test, "Sort a reversed vector");
}

// Test 3: Sort an empty vector
void test_empty_vector() {
    std::vector<int> test = {};
    quick_sort(test);
    ASSERT_EQ(std::vector<int>({}), test, "Sort an empty vector");
}

// Test 4: Sort a single-element vector
void test_single_element() {
    std::vector<int> test = {42};
    quick_sort(test);
    ASSERT_EQ(std::vector<int>({42}), test, "Sort a single-element vector");
}

// Test 5: Sort a large vector
void test_large_vector() {
    constexpr int VECTOR_SIZE = 10000000;
    std::vector<int> test(VECTOR_SIZE);

    // Seed the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, VECTOR_SIZE);

    // Generate random numbers
    for (int& num : test) {
        num = dist(gen);
    }

    auto start = std::chrono::high_resolution_clock::now();
    quick_sort(test);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    if (sorted(test.begin(), test.end())) {
        std::cout << "\033[32mPASS | Sort a large vector of 10,000,000 random elements in " << duration << "ms\033[0m\n";
    } else {
        std::cerr << "\033[31mERROR | Large random vector sorting failed\033[0m\n";
    }
}

// Main function to run all tests
int main() {
    test_already_sorted();
    test_reversed_vector();
    test_empty_vector();
    test_single_element();
    test_large_vector();

    std::cout << "\033[32mAll tests completed.\033[0m\n";
    return 0;
}

