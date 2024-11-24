#include <iostream>
#include <vector>
#include "bubble-sort.hpp"

// ANSI color codes
const std::string GREEN = "\033[32m";
const std::string RED = "\033[31m";
const std::string RESET = "\033[0m";

// Test helper function to print results
void test_bubble_sort(std::vector<int> input, std::vector<int> expected) {
    std::vector<int> result = bubble_sort(input);
    if (sorted(result)) {
        std::cout << GREEN << "Test passed: Sorted correctly!" << RESET << std::endl;
    } else {
        std::cout << RED << "Test failed: Sorting error!" << RESET << std::endl;
    }

    // Verify if the result matches the expected output
    if (result == expected) {
        std::cout << GREEN << "Output matches expected!" << RESET << std::endl;
    } else {
        std::cout << RED << "Output does not match expected!" << RESET << std::endl;
    }
}

// Main function for running tests
int main() {
    // Test 1: Already sorted vector
    std::vector<int> test1 = {1, 2, 3, 4, 5};
    std::vector<int> expected1 = {1, 2, 3, 4, 5};
    std::cout << "Running Test 1:" << std::endl;
    test_bubble_sort(test1, expected1);
    
    // Test 2: Reverse sorted vector
    std::vector<int> test2 = {5, 4, 3, 2, 1};
    std::vector<int> expected2 = {1, 2, 3, 4, 5};
    std::cout << "Running Test 2:" << std::endl;
    test_bubble_sort(test2, expected2);

    // Test 3: Unsorted vector
    std::vector<int> test3 = {3, 1, 4, 5, 2};
    std::vector<int> expected3 = {1, 2, 3, 4, 5};
    std::cout << "Running Test 3:" << std::endl;
    test_bubble_sort(test3, expected3);

    // Test 4: Single-element vector (should always be sorted)
    std::vector<int> test4 = {42};
    std::vector<int> expected4 = {42};
    std::cout << "Running Test 4:" << std::endl;
    test_bubble_sort(test4, expected4);

    // Test 5: Empty vector (should always be considered sorted)
    std::vector<int> test5 = {};
    std::vector<int> expected5 = {};
    std::cout << "Running Test 5:" << std::endl;
    test_bubble_sort(test5, expected5);

    return 0;
}
