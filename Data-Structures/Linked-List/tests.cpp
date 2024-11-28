
#include "linked-list.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

#define ASSERT_EQ(expected, actual, message) \
    if ((expected) != (actual)) { \
        std::cerr << "\033[31mERROR | " << message << ": Expected [" << expected << "], but got [" << actual << "]\033[0m\n"; \
    } else { \
        std::cout << "\033[32mPASS | " << message << "\033[0m\n"; \
    }

int main() {
    // Test 1: Default Constructor
    std::cout << "Test 1: Default Constructor\n";
    linked_list<int> list1;
    try {
        ASSERT_EQ(0, list1.size(), "Default constructor initializes size to 0");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Default Constructor Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 2: Insertion at Front
    std::cout << "Test 2: Insertion at Front\n";
    try {
        list1.insert(10);
        list1.insert(20);
        ASSERT_EQ(2, list1.size(), "List size after inserting two elements");
        ASSERT_EQ(20, *list1[0], "First element is 20 (insert at front)");
        ASSERT_EQ(10, *list1[1], "Second element is 10 (insert at front)");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Insertion at Front Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 3: Insertion at Back
    std::cout << "Test 3: Insertion at Back\n";
    try {
        list1.insert_back(30);
        ASSERT_EQ(3, list1.size(), "List size after inserting at back");
        ASSERT_EQ(30, *list1[2], "Last element is 30 (insert at back)");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Insertion at Back Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 4: Remove Elements
    std::cout << "Test 4: Remove Elements\n";
    try {
        list1.remove(20);
        ASSERT_EQ(2, list1.size(), "List size after removing one element");
        ASSERT_EQ(10, *list1[0], "First element is 10 after removal");
        ASSERT_EQ(30, *list1[1], "Second element is 30 after removal");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Remove Elements Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 5: Copy Assignment Operator
    linked_list<int> list2;
    std::cout << "Test 5: Copy Assignment Operator\n";
    try {
        list2 = list1;
        ASSERT_EQ(list1.size(), list2.size(), "Copied list has the same size as original");
        ASSERT_EQ(*list1[0], *list2[0], "Copied list's first element matches");
        ASSERT_EQ(*list1[1], *list2[1], "Copied list's second element matches");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Copy Assignment Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 6: Stream Insertion Operator
    std::cout << "Test 6: Stream Insertion Operator\n";
    try {
        std::ofstream outfile("output.txt");
        if (!outfile) throw std::runtime_error("Failed to open output file.");
        list1 << outfile;
        outfile.close();
        std::cout << "\033[32mPASS | List successfully written to output.txt\033[0m\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Stream Insertion Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 7: Clear List
    std::cout << "Test 7: Clear List\n";
    try {
        list1.clear();
        ASSERT_EQ(0, list1.size(), "List size is 0 after clear");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Clear List Test Failed: " << e.what() << "\033[0m\n";
    }

    return 0;
}

