#include "queue.hpp"
#include <iostream>
#include <stdexcept>
#include <chrono>

#define ASSERT_EQ(expected, actual, message) \
    if ((expected) != (actual)) { \
        std::cerr << "\033[31mERROR | " << message << ": Expected [" << expected << "], but got [" << actual << "]\033[0m\n"; \
    } else { \
        std::cout << "\033[32mPASS | " << message << "\033[0m\n"; \
    }

int main() {
    // Test 1: Default Constructor
    try {
        queue<int> q;
        ASSERT_EQ(0, q.size(), "Default constructor initializes size to 0");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Default Constructor Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 2: Push and Pop
    try {
        queue<int> q;
        q.push(10);
        q.push(20);
        ASSERT_EQ(2, q.size(), "Queue size after pushing two elements");
        ASSERT_EQ(10, q.front(), "First element is 10 after push");

        q.pop();
        ASSERT_EQ(1, q.size(), "Queue size after one pop");
        ASSERT_EQ(20, q.front(), "First element is 20 after one pop");

        q.pop();
        ASSERT_EQ(0, q.size(), "Queue size after popping all elements");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Push/Pop Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 3: Front of Queue
    try {
        queue<int> q;
        q.push(10);
        q.push(20);
        ASSERT_EQ(10, q.front(), "Front element is 10 after pushing two elements");

        q.pop();
        ASSERT_EQ(20, q.front(), "Front element is 20 after popping one element");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Front Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 4: Pop from Empty Queue (Exception Handling)
    try {
        queue<int> q;
        q.pop();  // Should throw an exception
    } catch (const std::out_of_range& e) {
        std::cout << "\033[32mPASS | Pop from empty queue threw expected exception: " << e.what() << "\033[0m\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Pop from Empty Queue Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 5: Copy Constructor
    try {
        queue<int> q1;
        q1.push(10);
        q1.push(20);
        queue<int> q2 = q1;

        ASSERT_EQ(q1.size(), q2.size(), "Copied queue has the same size as the original");
        ASSERT_EQ(10, q2.front(), "Copied queue's front element matches");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Copy Constructor Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 6: Assignment Operator
    try {
        queue<int> q1;
        q1.push(10);
        q1.push(20);
        queue<int> q2;
        q2 = q1;

        ASSERT_EQ(q1.size(), q2.size(), "Assigned queue has the same size as the original");
        ASSERT_EQ(10, q2.front(), "Assigned queue's front element matches");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Assignment Operator Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 7: Clear Queue (Optional for your class)
    try {
        queue<int> q;
        q.push(10);
        q.push(20);
        while (!q.is_empty()) {
            q.pop();
        }
        ASSERT_EQ(0, q.size(), "Queue size is 0 after clearing all elements");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Clear Queue Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 8: Big Data Test (Performance Test)
    try {
        queue<int> q;
        constexpr int BIG_DATA_SIZE = 10000;
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < BIG_DATA_SIZE; ++i) {
            q.push(i);
        }

        auto mid = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < BIG_DATA_SIZE; ++i) {
            q.pop();
        }
        auto end = std::chrono::high_resolution_clock::now();

        auto insert_duration = std::chrono::duration_cast<std::chrono::milliseconds>(mid - start).count();
        auto pop_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - mid).count();

        ASSERT_EQ(0, q.size(), "Queue size is 0 after clearing big data test");
        std::cout << "\033[32mPASS | Big Data Test: Inserted " << BIG_DATA_SIZE
                  << " elements in " << insert_duration << "ms, popped in "
                  << pop_duration << "ms\033[0m\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Big Data Test Failed: " << e.what() << "\033[0m\n";
    }

    std::cout << "\033[32mAll tests completed.\033[0m\n";

    return 0;
}
