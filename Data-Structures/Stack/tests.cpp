#include "stack.hpp"
#include <iostream>
#include <stdexcept>

int main() {
    // Test 1: Default Constructor
    std::cout << "\033[32mTest 1: Default Constructor\033[0m\n";
    Stack<int> stack1;
    try {
        std::cout << "Is stack empty? " << (stack1.isEmpty() ? "Yes" : "No") << "\n";
        stack1.push(10);
        stack1.push(20);
        stack1.push(30);
        std::cout << "Stack contents: " << stack1 << "\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR: " << e.what() << "\033[0m\n";
    }

    // Test 2: Top and Pop
    std::cout << "\033[32mTest 2: Top and Pop\033[0m\n";
    try {
        std::cout << "Top element: " << stack1.top() << "\n";
        stack1.pop();
        std::cout << "Stack after pop: " << stack1 << "\n";
        std::cout << "Top element: " << stack1.top() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR: " << e.what() << "\033[0m\n";
    }

    // Test 3: Copy Constructor
    std::cout << "\033[32mTest 3: Copy Constructor\033[0m\n";
    Stack<int> stack2; // Declare outside try block
    try {
        stack2 = stack1;  // Copy the stack
        std::cout << "Copied stack: " << stack2 << "\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR: " << e.what() << "\033[0m\n";
    }

    // Test 4: Move Constructor
    std::cout << "\033[32mTest 4: Move Constructor\033[0m\n";
    Stack<int> stack3; // Declare outside try block
    try {
        stack3 = std::move(stack1);  // Move the stack
        std::cout << "Moved stack: " << stack3 << "\n";
        std::cout << "Original stack after move: " << stack1 << "\n";  // Should be empty
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR: " << e.what() << "\033[0m\n";
    }

    // Test 5: Copy Assignment
    std::cout << "\033[32mTest 5: Copy Assignment\033[0m\n";
    Stack<int> stack4; // Declare outside try block
    try {
        stack4 = stack3;  // Copy assignment
        std::cout << "Assigned stack: " << stack4 << "\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR: " << e.what() << "\033[0m\n";
    }

    // Test 6: Move Assignment
    std::cout << "\033[32mTest 6: Move Assignment\033[0m\n";
    Stack<int> stack5; // Declare outside try block
    try {
        stack5 = std::move(stack3);  // Move assignment
        std::cout << "Moved-assigned stack: " << stack5 << "\n";
        std::cout << "Original stack after move: " << stack3 << "\n";  // Should be empty
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR: " << e.what() << "\033[0m\n";
    }

    // Test 7: Exception Handling (Empty Stack)
    std::cout << "\033[32mTest 7: Exception Handling (Empty Stack)\033[0m\n";
    Stack<int> emptyStack; // Declare outside try block
    try {
        emptyStack.pop();  // Should throw an exception
    } catch (const std::out_of_range& e) {
        std::cerr << "\033[33mExpected Error: " << e.what() << "\033[0m\n";
    }

    // Test 8: Large Data Handling
    std::cout << "\033[32mTest 8: Large Data Handling\033[0m\n";
    Stack<int> largeStack; // Declare outside try block
    try {
        for (int i = 0; i < 1'000'000; ++i) {
            largeStack.push(i);
        }
        std::cout << "Large stack size: " << largeStack.size() << "\n";
        for (int i = 0; i < 100'000; ++i) {
            largeStack.pop();
        }
        std::cout << "Large stack size after pops: " << largeStack.size() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR: " << e.what() << "\033[0m\n";
    }

    std::cout << "\033[32mAll tests completed.\033[0m\n";
    return 0;
}
