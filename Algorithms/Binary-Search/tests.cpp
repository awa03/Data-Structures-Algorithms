#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>
#include "binary-search.hpp"

const std::string GREEN = "\033[32m";
const std::string RED = "\033[31m";
const std::string RESET = "\033[0m";

// Helper function to run a test
void test_binary_search(const std::vector<int>& vec, int target, int expected_index) {
    try {
        int result = binary_search(vec, target);
        if (result == expected_index) {
            std::cout << GREEN << "Test passed!" << RESET << std::endl;
        } else {
            std::cout << RED << "Test failed! Expected index: " << expected_index << ", Got: " << result << RESET << std::endl;
        }
    } catch (const std::logic_error& e) {
        if (expected_index == -1) {
            std::cout << GREEN << "Test passed! Correctly thrown exception: " << e.what() << RESET << std::endl;
        } else {
            std::cout << RED << "Test failed! Expected index: " << expected_index << ", Exception: " << e.what() << RESET << std::endl;
        }
    }
}

int main() {
    // Test 1: Search for a value that exists
    std::vector<int> test1 = {1, 3, 5, 7, 9, 11};
    int target1 = 5;
    int expected_index1 = 2;  // The index of 5 in the sorted vector
    std::cout << "Running Test 1: Search for 5" << std::endl;
    test_binary_search(test1, target1, expected_index1);

    // Test 2: Search for a value that doesn't exist
    std::vector<int> test2 = {1, 3, 5, 7, 9, 11};
    int target2 = 4;
    int expected_index2 = -1;  // 4 is not in the vector
    std::cout << "Running Test 2: Search for 4" << std::endl;
    test_binary_search(test2, target2, expected_index2);

    // Test 3: Search for a value in an empty vector
    std::vector<int> test3 = {};
    int target3 = 5;
    int expected_index3 = -1;  // No element in the vector
    std::cout << "Running Test 3: Search in empty vector" << std::endl;
    test_binary_search(test3, target3, expected_index3);

    // Test 4: Search for a value in a single-element vector (present)
    std::vector<int> test4 = {10};
    int target4 = 10;
    int expected_index4 = 0;  // 10 is at index 0
    std::cout << "Running Test 4: Search for 10 in single-element vector" << std::endl;
    test_binary_search(test4, target4, expected_index4);

    // Test 5: Search for a value in a single-element vector (not present)
    std::vector<int> test5 = {10};
    int target5 = 5;
    int expected_index5 = -1;  // 5 is not in the vector
    std::cout << "Running Test 5: Search for 5 in single-element vector" << std::endl;
    test_binary_search(test5, target5, expected_index5);

    // Test 6: Search for a value at the first position in the vector
    std::vector<int> test6 = {1, 3, 5, 7, 9, 11};
    int target6 = 1;
    int expected_index6 = 0;  // 1 is at the first position
    std::cout << "Running Test 6: Search for 1 at the beginning" << std::endl;
    test_binary_search(test6, target6, expected_index6);

    // Test 7: Search for a value at the last position in the vector
    std::vector<int> test7 = {1, 3, 5, 7, 9, 11};
    int target7 = 11;
    int expected_index7 = 5;  // 11 is at the last position
    std::cout << "Running Test 7: Search for 11 at the end" << std::endl;
    test_binary_search(test7, target7, expected_index7);

    return 0;
}
