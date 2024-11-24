#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>
#include "linear-search.hpp"

const std::string GREEN = "\033[32m";
const std::string RED = "\033[31m";
const std::string RESET = "\033[0m";

// Helper function to run a test
void test_linear_search(std::vector<int>& vec, int target, int expected_value, bool should_throw = false) {
    try {
        int& result = linear_search(vec, target);
        if (result == expected_value) {
            std::cout << GREEN << "Test passed!" << RESET << std::endl;
        } else {
            std::cout << RED << "Test failed! Expected: " << expected_value << ", Got: " << result << RESET << std::endl;
        }
    } catch (const std::logic_error& e) {
        if (should_throw) {
            std::cout << GREEN << "Test passed! Correctly threw exception: " << e.what() << RESET << std::endl;
        } else {
            std::cout << RED << "Test failed! Expected value: " << expected_value << ", Exception: " << e.what() << RESET << std::endl;
        }
    }
}

int main() {
    // Test 1: Search for an element that exists in the vector
    std::vector<int> test1 = {1, 3, 5, 7, 9, 11};
    int target1 = 5;
    int expected_value1 = 5;  // Element found, should return the element itself
    std::cout << "Running Test 1: Search for 5" << std::endl;
    test_linear_search(test1, target1, expected_value1);

    // Test 2: Search for a value that doesn't exist in the vector
    std::vector<int> test2 = {1, 3, 5, 7, 9, 11};
    int target2 = 4;
    std::cout << "Running Test 2: Search for 4 (should throw exception)" << std::endl;
    test_linear_search(test2, target2, 0, true);  // Expect an exception, hence 'should_throw' is true

    // Test 3: Search in an empty vector
    std::vector<int> test3 = {};
    int target3 = 5;
    std::cout << "Running Test 3: Search in empty vector (should throw exception)" << std::endl;
    test_linear_search(test3, target3, 0, true);  // Expect an exception

    // Test 4: Search for a value at the first position in the vector
    std::vector<int> test4 = {1, 3, 5, 7, 9, 11};
    int target4 = 1;
    int expected_value4 = 1;  // Element found, should return the element itself
    std::cout << "Running Test 4: Search for 1 at the beginning" << std::endl;
    test_linear_search(test4, target4, expected_value4);

    // Test 5: Search for a value at the last position in the vector
    std::vector<int> test5 = {1, 3, 5, 7, 9, 11};
    int target5 = 11;
    int expected_value5 = 11;  // Element found, should return the element itself
    std::cout << "Running Test 5: Search for 11 at the end" << std::endl;
    test_linear_search(test5, target5, expected_value5);

    // Test 6: Search for a value in a single-element vector (present)
    std::vector<int> test6 = {10};
    int target6 = 10;
    int expected_value6 = 10;  // Element found, should return the element itself
    std::cout << "Running Test 6: Search for 10 in single-element vector" << std::endl;
    test_linear_search(test6, target6, expected_value6);

    // Test 7: Search for a value in a single-element vector (not present)
    std::vector<int> test7 = {10};
    int target7 = 5;
    std::cout << "Running Test 7: Search for 5 in single-element vector (should throw exception)" << std::endl;
    test_linear_search(test7, target7, 0, true);  // Expect an exception

    return 0;
}
