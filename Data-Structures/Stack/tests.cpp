#include "stack.hpp"
#include <iostream>
#include <stdexcept>

#define ASSERT_EQ(expected, actual, message) \
    if ((expected) != (actual)) { \
        std::cerr << "\033[31mERROR | " << message << ": Expected [" << expected << "], but got [" << actual << "]\033[0m\n"; \
    } else { \
        std::cout << "\033[32mPASS | " << message << "\033[0m\n"; \
    }

void test_default_constructor_and_push() {
    Stack<int> stack1;
    try {
        ASSERT_EQ(true, stack1.isEmpty(), "Stack should be empty initially");

        stack1.push(10);
        stack1.push(20);
        stack1.push(30);

        ASSERT_EQ(false, stack1.isEmpty(), "Stack should not be empty after pushing elements");
        ASSERT_EQ(30, stack1.top(), "Top element should be 30 after pushing 10, 20, 30");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED PUSH TEST: " << e.what() << "\033[0m\n";
    }
}

void test_top_and_pop() {
    Stack<int> stack1;
    try {
        stack1.push(10);
        stack1.push(20);
        stack1.push(30);

        ASSERT_EQ(30, stack1.top(), "Top element should be 30 before popping");

        stack1.pop();
        ASSERT_EQ(20, stack1.top(), "Top element should be 20 after popping");

        stack1.pop();
        stack1.pop();
        ASSERT_EQ(true, stack1.isEmpty(), "Stack should be empty after popping all elements");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED POP/TOP TEST: " << e.what() << "\033[0m\n";
    }
}

void test_copy_constructor() {
    Stack<int> stack1;
    Stack<int> stack2;
    try {
        stack1.push(10);
        stack1.push(20);
        stack1.push(30);

        stack2 = stack1; // Copy assignment
        ASSERT_EQ(30, stack2.top(), "Top element of copied stack should be 30");

        stack2.pop();
        ASSERT_EQ(20, stack2.top(), "Top element of copied stack should be 20 after pop");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED COPY CONSTRUCTOR TEST: " << e.what() << "\033[0m\n";
    }
}

void test_move_constructor() {
    Stack<int> stack1;
    Stack<int> stack2;
    try {
        stack1.push(10);
        stack1.push(20);
        stack1.push(30);

        stack2 = std::move(stack1); // Move constructor
        ASSERT_EQ(30, stack2.top(), "Top element of moved stack should be 30");
        ASSERT_EQ(true, stack1.isEmpty(), "Original stack should be empty after move");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED MOVE CONSTRUCTOR TEST: " << e.what() << "\033[0m\n";
    }
}

void test_copy_assignment() {
    Stack<int> stack1;
    Stack<int> stack2;
    try {
        stack1.push(10);
        stack1.push(20);
        stack1.push(30);

        stack2 = stack1; // Copy assignment
        ASSERT_EQ(30, stack2.top(), "Top element of copied stack should be 30");

        stack2.pop();
        ASSERT_EQ(20, stack2.top(), "Top element of copied stack should be 20 after pop");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED COPY ASSIGNMENT TEST: " << e.what() << "\033[0m\n";
    }
}

void test_move_assignment() {
    Stack<int> stack1;
    Stack<int> stack2;
    try {
        stack1.push(10);
        stack1.push(20);
        stack1.push(30);

        stack2 = std::move(stack1); // Move assignment
        ASSERT_EQ(30, stack2.top(), "Top element of moved stack should be 30");
        ASSERT_EQ(true, stack1.isEmpty(), "Original stack should be empty after move assignment");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED MOVE ASSIGNMENT TEST: " << e.what() << "\033[0m\n";
    }
}

void test_exception_handling() {
    Stack<int> stack1;
    try {
        stack1.pop(); // Should throw exception
    } catch (const std::out_of_range& e) {
        std::cout << "\033[33mExpected Error | " << e.what() << "\033[0m\n";
    }
}

void test_large_data_handling() {
    Stack<int> stack1;
    try {
        for (int i = 0; i < 1'000'000; ++i) {
            stack1.push(i);
        }

        ASSERT_EQ(1'000'000, stack1.size(), "Stack size should be 1,000,000 after pushing 1,000,000 elements");

        for (int i = 0; i < 100'000; ++i) {
            stack1.pop();
        }

        ASSERT_EQ(900'000, stack1.size(), "Stack size should be 900,000 after popping 100,000 elements");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED LARGE DATA TEST: " << e.what() << "\033[0m\n";
    }
}

int main() {
    test_default_constructor_and_push();
    test_top_and_pop();
    test_copy_constructor();
    test_move_constructor();
    test_copy_assignment();
    test_move_assignment();
    test_exception_handling();
    test_large_data_handling();

    std::cout << "\033[32mAll tests completed.\033[0m\n";
    return 0;
}

