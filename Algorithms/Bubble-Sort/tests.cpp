
#include <iostream>
#include <vector>
#include <cstdlib>  
#include <chrono>   
#include "bubble-sort.hpp" 

#define ASSERT_EQ(expected, actual, message) \
    if ((expected) != (actual)) { \
        std::cerr << "\033[31mERROR | " << message << ": Expected [" << vector_to_string(expected) << "], but got [" << vector_to_string(actual) << "]\033[0m\n"; \
    } else { \
        std::cout << "\033[32mPASS | " << message << "\033[0m\n"; \
    }

// Function to convert vector to string for easier output
template <typename T>
std::string vector_to_string(const std::vector<T>& v) {
    std::string result = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        result += std::to_string(v[i]);
        if (i != v.size() - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}

// Test 1: Already sorted vector
void test_sorted_vector() {
    std::vector<int> test = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    try {
        std::vector<int> result = bubble_sort(test);
        ASSERT_EQ(expected, result, "Already sorted vector [1, 2, 3, 4, 5]");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Sorting test failed: " << e.what() << "\033[0m\n";
    }
}

// Test 2: Reverse sorted vector
void test_reverse_sorted_vector() {
    std::vector<int> test = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    try {
        std::vector<int> result = bubble_sort(test);
        ASSERT_EQ(expected, result, "Reverse sorted vector [5, 4, 3, 2, 1]");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Sorting test failed: " << e.what() << "\033[0m\n";
    }
}

// Test 3: Unsorted vector
void test_unsorted_vector() {
    std::vector<int> test = {3, 1, 4, 5, 2};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    try {
        std::vector<int> result = bubble_sort(test);
        ASSERT_EQ(expected, result, "Unsorted vector [3, 1, 4, 5, 2]");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Sorting test failed: " << e.what() << "\033[0m\n";
    }
}

// Test 4: Single-element vector (should always be sorted)
void test_single_element_vector() {
    std::vector<int> test = {42};
    std::vector<int> expected = {42};
    try {
        std::vector<int> result = bubble_sort(test);
        ASSERT_EQ(expected, result, "Single-element vector [42]");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Sorting test failed: " << e.what() << "\033[0m\n";
    }
}

// Test 5: Empty vector (should always be considered sorted)
void test_empty_vector() {
    std::vector<int> test = {};
    std::vector<int> expected = {};
    try {
        std::vector<int> result = bubble_sort(test);
        ASSERT_EQ(expected, result, "Empty vector []");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Sorting test failed: " << e.what() << "\033[0m\n";
    }
}

// Test 6: Big data test (testing with a large number of elements)
void test_big_data() {
    constexpr int BIG_DATA_SIZE = 100000; // 1 million elements
    std::vector<int> test;
    for (int i = 0; i < BIG_DATA_SIZE; ++i) {
        test.push_back(std::rand() % BIG_DATA_SIZE);  // Random numbers between 0 and BIG_DATA_SIZE-1
    }

    // Record start time
    auto start = std::chrono::high_resolution_clock::now();
    try {
        std::vector<int> result = bubble_sort(test);
        // Record end time
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        // Optionally, check if the result is sorted (can be time-consuming for large data)
        bool is_sorted = true;
        for (size_t i = 1; i < result.size(); ++i) {
            if (result[i] < result[i - 1]) {
                is_sorted = false;
                break;
            }
        }

        if (is_sorted) {
            std::cout << "\033[32mPASS | Big data sorting completed in " << duration << " ms\033[0m\n";
        } else {
            std::cerr << "\033[31mERROR | Big data sorting failed: Data is not sorted properly.\033[0m\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Big data test failed: " << e.what() << "\033[0m\n";
    }
}

int main() {
    test_sorted_vector();
    test_reverse_sorted_vector();
    test_unsorted_vector();
    test_single_element_vector();
    test_empty_vector();
    test_big_data();

    return 0;
}

