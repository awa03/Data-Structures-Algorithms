#include "linked-list.hpp"
#include "doubly-linked-list.hpp"
#include <iostream>
#include <fstream>
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
    linked_list<int> list1;
    try {
        ASSERT_EQ(0, list1.size(), "Default constructor initializes size to 0");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Default Constructor Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 2: Insertion at Front
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
    try {
        list1.insert_back(30);
        ASSERT_EQ(3, list1.size(), "List size after inserting at back");
        ASSERT_EQ(30, *list1[2], "Last element is 30 (insert at back)");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Insertion at Back Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 4: Remove Elements
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
    try {
        list2 = list1;
        ASSERT_EQ(list1.size(), list2.size(), "Copied list has the same size as original");
        ASSERT_EQ(*list1[0], *list2[0], "Copied list's first element matches");
        ASSERT_EQ(*list1[1], *list2[1], "Copied list's second element matches");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Copy Assignment Test Failed: " << e.what() << "\033[0m\n";
    }


    // Test 7: Clear List
    try {
        list1.clear();
        ASSERT_EQ(0, list1.size(), "List size is 0 after clear");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Clear List Test Failed: " << e.what() << "\033[0m\n";
    }

    try {
        linked_list<int> list1;
        constexpr int BIG_DATA_SIZE = 100000;
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < BIG_DATA_SIZE; ++i) {
            list1.insert_back(i);
        }

        auto mid = std::chrono::high_resolution_clock::now();
        list1.clear();
        auto end = std::chrono::high_resolution_clock::now();

        auto insert_duration = std::chrono::duration_cast<std::chrono::milliseconds>(mid - start).count();
        auto clear_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - mid).count();

        ASSERT_EQ(0, list1.size(), "List size is 0 after clearing big data test");
        std::cout << "\033[32mPASS | Big Data Test: Inserted " << BIG_DATA_SIZE
                  << " elements in " << insert_duration << "ms, cleared in "
                  << clear_duration << "ms\033[0m\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Big Data Test Failed: " << e.what() << "\033[0m\n";
    }



 // Test 1: Default Constructor
    try {
        doubly_linked_list<int> list1;
        ASSERT_EQ(0, list1.size(), "Default constructor initializes size to 0");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Default Constructor Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 2: Insertion at Front
    try {
        doubly_linked_list<int> list1;
        list1.insert(10);
        list1.insert(20);
        ASSERT_EQ(2, list1.size(), "List size after inserting two elements");
        ASSERT_EQ(20, *list1.front(), "First element is 20 (insert at front)");
        ASSERT_EQ(10, *list1.at(1), "Second element is 10 (insert at front)");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Insertion at Front Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 3: Insertion at Back
    try {
        doubly_linked_list<int> list1;
        list1.insert(10);
        list1.insert_back(30);
        ASSERT_EQ(2, list1.size(), "List size after inserting at back");
        ASSERT_EQ(30, *list1.back(), "Last element is 30 (insert at back)");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Insertion at Back Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 4: Remove Elements
    try {
        doubly_linked_list<int> list1;
        list1.insert(20);
        list1.insert(10);
        list1.insert_back(30);
        list1.remove(20);
        ASSERT_EQ(2, list1.size(), "List size after removing one element");
        ASSERT_EQ(10, *list1.front(), "First element is 10 after removal");
        ASSERT_EQ(30, *list1.back(), "Last element is 30 after removal");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Remove Elements Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 5: Copy Constructor
    try {
        doubly_linked_list<int> list1;
        list1.insert(10);
        list1.insert(20);
        doubly_linked_list<int> list2 = list1;
        ASSERT_EQ(list1.size(), list2.size(), "Copied list has the same size as original");
        ASSERT_EQ(*list1.front(), *list2.front(), "Copied list's first element matches");
        ASSERT_EQ(*list1.back(), *list2.back(), "Copied list's last element matches");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Copy Constructor Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 6: Assignment Operator
    try {
        doubly_linked_list<int> list1;
        list1.insert(10);
        list1.insert(20);
        doubly_linked_list<int> list2;
        list2.insert(30);
        list2 = list1;
        ASSERT_EQ(list1.size(), list2.size(), "Assigned list has the same size as original");
        ASSERT_EQ(*list1.front(), *list2.front(), "Assigned list's first element matches");
        ASSERT_EQ(*list1.back(), *list2.back(), "Assigned list's last element matches");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Assignment Operator Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 7: Clear List
    try {
        doubly_linked_list<int> list1;
        list1.insert(10);
        list1.insert_back(20);
        list1.clear();
        ASSERT_EQ(0, list1.size(), "List size is 0 after clear");
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Clear List Test Failed: " << e.what() << "\033[0m\n";
    }

    // Test 8: Big Data Test
    try {
        doubly_linked_list<int> list1;
        constexpr int BIG_DATA_SIZE = 100'000'000;
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < BIG_DATA_SIZE; ++i) {
            list1.insert_back(i);
        }

        auto mid = std::chrono::high_resolution_clock::now();
        list1.clear();
        auto end = std::chrono::high_resolution_clock::now();

        auto insert_duration = std::chrono::duration_cast<std::chrono::milliseconds>(mid - start).count();
        auto clear_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - mid).count();

        ASSERT_EQ(0, list1.size(), "List size is 0 after clearing big data test");
        std::cout << "\033[32mPASS | Big Data Test: Inserted " << BIG_DATA_SIZE
                  << " elements in " << insert_duration << "ms, cleared in "
                  << clear_duration << "ms\033[0m\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Big Data Test Failed: " << e.what() << "\033[0m\n";
    }


    std::cout << "\033[32mAll tests completed.\033[0m\n";

    return 0;}

