
#include "vector.hpp"
#include <stdexcept>
#include <iostream>

int main() {
    // Test 1: Default Constructor
    std::cout << "\033[32mTest 1: Vector Created Using Default Constructor\033[0m\n";
    Vector<int> test1;
    try {
        std::cout << "Inserting 1\n";
        test1.push_back(1);
        std::cout << test1 << "\n";

        std::cout << "Inserting 2\n";
        test1.push_back(2);
        std::cout << test1 << "\n";

        std::cout << "Inserting 3\n";
        test1.push_back(3);
        std::cout << test1 << "\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED INSERTION TEST: " << e.what() << "\033[0m\n";
    }

    // Testing empty functionality
    std::cout << "\033[32mTesting Empty Functionality\033[0m\n";
    try {
        test1.clear();
        std::cout << "Size after clearing: " << test1.size() << "\n";

        if (test1.isEmpty()) {
            std::cout << "Vector is now empty\n";
        } else {
            throw std::logic_error("Vector is not empty");
        }
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED EMPTY TEST: " << e.what() << "\033[0m\n";
    }

    // Test 2: Initializer List Constructor
    std::cout << "\033[32mTest 2: Vector Created Using Initializer List\033[0m\n";
    Vector<int> test2({1, 2, 3, 4, 3, 1, 3, 4, 5, 6, 6, 9, 1, 3, 4});
    try {
        std::cout << "Vector contents: " << test2 << "\n";

        test1 = test2; // Copy assignment
        std::cout << "Copied contents to test1: " << test1 << "\n";

        if (test1 == test2) {
            std::cout << "Vectors are equal\n";
        } else {
            throw std::logic_error("Vectors are not equal");
        }
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED COPY/COMPARE TEST: " << e.what() << "\033[0m\n";
    }

    // Test 3: Large Data Handling
    std::cout << "\033[32mTest 3: Large Data Handling\033[0m\n";
    Vector<int> test3;
    try {
        // Insert 1,000,000 elements
        for (int i = 0; i < 1'000'000; ++i) {
            test3.push_back(i);
        }
        std::cout << "Inserted 1,000,000 elements\n";

        // Modify elements
        for (int i = 0; i < 100'000; ++i) {
            test3[i + 1] = test3[i];
        }
        std::cout << "Modified first 100,000 elements\n";

        // Pop elements
        for (int i = 0; i < 100'000; ++i) {
            test3.pop_back();
        }
        std::cout << "Popped 100,000 elements\n";

        // Reference and move testing
        auto& test4 = test3;
        auto&& test5 = std::move(test3);

        test4.clear();
        test5.clear();

        if (test4.isEmpty() && test5.isEmpty()) {
            std::cout << "Vectors emptied successfully\n";
        } else {
            throw std::logic_error("Vectors not empty after clearing");
        }
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED MASS DATA TEST: " << e.what() << "\033[0m\n";
    }

    // Test 4: Exception Handling for Out-of-Range Access
    std::cout << "\033[32mTest 4: Out-of-Range Access\033[0m\n";
    try {
        std::cout << "Accessing out-of-range index:\n";
        std::cout << test2[100]; // Should throw exception
    } catch (const std::out_of_range& e) {
        std::cerr << "\033[33mExpected Error | " << e.what() << "\033[0m\n";
    }

    // Test 5: Resize Handling
    std::cout << "\033[32mTest 5: Resizing the Vector\033[0m\n";
    try {
        Vector<int> test5({10, 20, 30});
        std::cout << "Before resizing: " << test5 << " (capacity: " << test5.capacity() << ")\n";
        test5.push_back(40);
        test5.push_back(50);
        std::cout << "After resizing: " << test5 << " (capacity: " << test5.capacity() << ")\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED RESIZE TEST: " << e.what() << "\033[0m\n";
    }

    std::cout << "\033[32mAll tests completed.\033[0m\n";
    return 0;
}

