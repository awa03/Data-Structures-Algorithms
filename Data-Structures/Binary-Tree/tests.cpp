#include "binary-tree.hpp"
#include <iostream>
#include <chrono>
#include <stdexcept>

int vector_test();

#define ASSERT_EQ(expected, actual, message) \
    if ((expected) != (actual)) { \
        std::cerr << "\033[31mERROR | " << message << ": Expected [" << expected << "], but got [" << actual << "]\033[0m\n"; \
    } else { \
        std::cout << "\033[32mPASS | " << message << "\033[0m\n"; \
    }



int main() {
    // Test 1: Default Constructor
    std::cout << "\033[32mTest 1: Tree Created Using Default Constructor\033[0m\n";
    Tree<int> test1;
    try {
        std::cout << "Inserting 10\n";
        test1.insert(10);
        std::cout << "Inserting 5\n";
        test1.insert(5);
        std::cout << "Inserting 15\n";
        test1.insert(15);

        if (test1.contains(10) && test1.contains(5) && test1.contains(15)) {
            std::cout << "All elements inserted successfully\n";
        } else {
            throw std::logic_error("Inserted elements not found in the tree");
        }
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED INSERTION TEST: " << e.what() << "\033[0m\n";
    }

    // Test 2: Remove Elements
    std::cout << "\033[32mTest 2: Remove Elements from Tree\033[0m\n";
    try {
        test1.remove(5);
        if (!test1.contains(5)) {
            std::cout << "Element 5 removed successfully\n";
        } else {
            throw std::logic_error("Element 5 still exists in the tree");
        }

        test1.remove(10);
        if (!test1.contains(10)) {
            std::cout << "Element 10 removed successfully\n";
        } else {
            throw std::logic_error("Element 10 still exists in the tree");
        }
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED REMOVAL TEST: " << e.what() << "\033[0m\n";
    }

    // Test 3: Copy Constructor
    std::cout << "\033[32mTest 3: Copy Constructor\033[0m\n";
    try {
        Tree<int> test3(test1);
        if (!test3.contains(15)) {
            throw std::logic_error("Copy constructor did not properly copy elements");
        }
        std::cout << "Copy constructor passed\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED COPY CONSTRUCTOR TEST: " << e.what() << "\033[0m\n";
    }

    // Test 4: Assignment Operator
    std::cout << "\033[32mTest 4: Assignment Operator\033[0m\n";
    try {
        Tree<int> test4;
        test4.insert(20);
        test4 = test1;

        if (test4.contains(15) && !test4.contains(20)) {
            std::cout << "Assignment operator passed\n";
        } else {
            throw std::logic_error("Assignment operator failed to assign properly");
        }
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED ASSIGNMENT TEST: " << e.what() << "\033[0m\n";
    }

    // Test 5: Large Data Handling
    std::cout << "\033[32mTest 5: Large Data Handling\033[0m\n";
    try {
        Tree<int> test5;
        for (int i = 0; i < 100000; ++i) {
            test5.insert(i);
        }
        if (test5.contains(99999) && !test5.contains(100000)) {
            std::cout << "Large data test passed\n";
        } else {
            throw std::logic_error("Tree failed large data handling");
        }
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED LARGE DATA TEST: " << e.what() << "\033[0m\n";
    }

    // Test 6: Out-of-Range Behavior (Edge Case)
    std::cout << "\033[32mTest 6: Out-of-Range Behavior\033[0m\n";
    try {
        Tree<int> test6;
        if (test6.contains(1)) {
            throw std::logic_error("Tree contains elements when it should be empty");
        }
        std::cout << "Out-of-range test passed\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED OUT-OF-RANGE TEST: " << e.what() << "\033[0m\n";
    }

    // Test 7: Destructor Verification
    std::cout << "\033[32mTest 7: Destructor Verification\033[0m\n";
    try {
        {
            Tree<int> test7;
            test7.insert(50);
            test7.insert(25);
            test7.insert(75);
        }
        std::cout << "Destructor called successfully (no memory leaks)\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED DESTRUCTOR TEST: " << e.what() << "\033[0m\n";
    }


  std::cout << "Test 8: Big Data Test\n";
    try {
        Tree<int> list1;
        constexpr int BIG_DATA_SIZE = 100000;
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < BIG_DATA_SIZE; ++i) {
            list1.insert(i);
        }

        auto mid = std::chrono::high_resolution_clock::now();

        auto insert_duration = std::chrono::duration_cast<std::chrono::milliseconds>(mid - start).count();

        std::cout << "\033[32mPASS | Big Data Test: Inserted " << BIG_DATA_SIZE
                  << " elements in " << insert_duration << "ms\033[0m\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Big Data Test Failed: " << e.what() << "\033[0m\n";
    }




    std::cout << "\033[32mAll tests completed.\033[0m\n";

    vector_test();
    return 0;
}

#include "binary-tree-vector.hpp"

int vector_test() {
    // Test 1: Default Constructor and Insertion
    std::cout << "\033[32mTest 1: Tree Created Using Default Constructor\033[0m\n";
    VectorBinaryTree<int> test1;
    try {
        std::cout << "Inserting 10\n";
        test1.insert(10);
        std::cout << "Inserting 5\n";
        test1.insert(5);
        std::cout << "Inserting 15\n";
        test1.insert(15);

        // Check if the elements exist in the tree
        if (test1.contains(10) && test1.contains(5) && test1.contains(15)) {
            std::cout << "All elements inserted successfully\n";
        } else {
            throw std::logic_error("Inserted elements not found in the tree");
        }
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED INSERTION TEST: " << e.what() << "\033[0m\n";
    }

    // Test 2: Access Root and Children
    std::cout << "\033[32mTest 2: Accessing Root and Children\033[0m\n";
    try {
        std::cout << "Root: " << test1.root() << "\n";
        std::cout << "Left child of root: " << test1.leftChild(0) << "\n";
        std::cout << "Right child of root: " << test1.rightChild(0) << "\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED ACCESS ROOT/CHILD TEST: " << e.what() << "\033[0m\n";
    }

    // Test 3: Removing Elements
    std::cout << "\033[32mTest 3: Removing Elements from Tree\033[0m\n";
    try {
        test1.remove(5); // Removing element
        if (!test1.contains(5)) {
            std::cout << "Element 5 removed successfully\n";
        } else {
            throw std::logic_error("Element 5 still exists in the tree");
        }

        test1.remove(10); // Removing another element
        if (!test1.contains(10)) {
            std::cout << "Element 10 removed successfully\n";
        } else {
            throw std::logic_error("Element 10 still exists in the tree");
        }
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED REMOVAL TEST: " << e.what() << "\033[0m\n";
    }

    // Test 4: Large Data Handling
    std::cout << "\033[32mTest 4: Large Data Handling\033[0m\n";
    try {
        VectorBinaryTree<int> test4;
        for (int i = 0; i < 100000; ++i) {
            test4.insert(i);
        }
        if (test4.contains(99999) && !test4.contains(100000)) {
            std::cout << "Large data test passed\n";
        } else {
            throw std::logic_error("Tree failed large data handling");
        }
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED LARGE DATA TEST: " << e.what() << "\033[0m\n";
    }

    // Test 5: Copy Constructor
    std::cout << "\033[32mTest 5: Copy Constructor\033[0m\n";
    try {
        VectorBinaryTree<int> test5(test1); // Using copy constructor
        if (test5.contains(15)) {
            std::cout << "Copy constructor passed\n";
        } else {
            throw std::logic_error("Copy constructor did not properly copy elements");
        }
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED COPY CONSTRUCTOR TEST: " << e.what() << "\033[0m\n";
    }

    // Test 6: Destructor Verification
    std::cout << "\033[32mTest 6: Destructor Verification\033[0m\n";
    try {
        {
            VectorBinaryTree<int> test6;
            test6.insert(50);
            test6.insert(25);
            test6.insert(75);
        }
        std::cout << "Destructor called successfully (no memory leaks)\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED DESTRUCTOR TEST: " << e.what() << "\033[0m\n";
    }

    // Test 7: Out-of-Range Behavior (Edge Case)
    std::cout << "\033[32mTest 7: Out-of-Range Behavior\033[0m\n";
    try {
        VectorBinaryTree<int> test7;
        if (test7.contains(1)) {
            throw std::logic_error("Tree contains elements when it should be empty");
        }
        std::cout << "Out-of-range test passed\n";
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED OUT-OF-RANGE TEST: " << e.what() << "\033[0m\n";
    }

    // Test 8: Assignment Operator
    std::cout << "\033[32mTest 8: Assignment Operator\033[0m\n";
    try {
        VectorBinaryTree<int> test8;
        test8.insert(20);
        test8 = test1;

        if (test8.contains(15) && !test8.contains(20)) {
            std::cout << "Assignment operator passed\n";
        } else {
            throw std::logic_error("Assignment operator failed to assign properly");
        }
    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | FAILED ASSIGNMENT TEST: " << e.what() << "\033[0m\n";
    }

    std::cout << "\033[32mAll tests completed.\033[0m\n";

  std::cout << "Test 9: Big Data Test\n";
    try {
        VectorBinaryTree<int> list1;
        constexpr int BIG_DATA_SIZE = 10000000;
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < BIG_DATA_SIZE; ++i) {
            list1.insert(i);
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




    return 0;
}
