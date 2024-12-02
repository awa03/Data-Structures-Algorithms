#include "bool.hpp"
#include <iostream>
#include <stdexcept>

#define ASSERT_EQ(expected, actual, message) \
    if ((expected) != (actual)) { \
        std::cerr << "\033[31mERROR | " << message << ": Expected [" << expected << "], but got [" << actual << "]\033[0m\n"; \
    } else { \
        std::cout << "\033[32mPASS | " << message << "\033[0m\n"; \
    }

int main() {
    try {
        // Test 1: Default Constructor
        boolean b1;
        ASSERT_EQ(false, b1.to_bool(), "Default constructor initializes to False");

        // Test 2: Parameterized Constructor
        boolean b2(1);
        ASSERT_EQ(true, b2.to_bool(), "Parameterized constructor initializes to True");

        boolean b3(0);
        ASSERT_EQ(false, b3.to_bool(), "Parameterized constructor initializes to False");

        // Test 3: Invalid Parameterized Constructor
        try {
            boolean b4(2); // Invalid value
            std::cerr << "\033[31mERROR | No exception thrown for invalid constructor value\033[0m\n";
        } catch (const std::invalid_argument& e) {
            std::cout << "\033[32mPASS | Exception thrown for invalid constructor value: " << e.what() << "\033[0m\n";
        }

        // Test 4: Assignment Operator
        b1 = true;
        ASSERT_EQ(true, b1.to_bool(), "Assignment operator assigns True");

        b1 = false;
        ASSERT_EQ(false, b1.to_bool(), "Assignment operator assigns False");

        // Test 5: Copy Assignment Operator
        b1 = b2;
        ASSERT_EQ(true, b1.to_bool(), "Copy assignment operator assigns value from another boolean");

        // Test 6: Equality Operator
        ASSERT_EQ(true, (b1 == b2), "Equality operator returns True for equal booleans");
        ASSERT_EQ(false, (b1 == b3), "Equality operator returns False for unequal booleans");

        // Test 7: Inequality Operator
        ASSERT_EQ(false, (b1 != b2), "Inequality operator returns False for equal booleans");
        ASSERT_EQ(true, (b1 != b3), "Inequality operator returns True for unequal booleans");

        // Test 8: Invalid Assignment
        try {
            b1 = 3; // Invalid value
            std::cerr << "\033[31mERROR | No exception thrown for invalid assignment\033[0m\n";
        } catch (const std::invalid_argument& e) {
            std::cout << "\033[32mPASS | Exception thrown for invalid assignment: " << e.what() << "\033[0m\n";
        }

        // Test 9: Chaining Assignments
        b1 = b2 = false;
        ASSERT_EQ(false, b1.to_bool(), "Chained assignment sets b1 to False");
        ASSERT_EQ(false, b2.to_bool(), "Chained assignment sets b2 to False");

        // Test 10: Logical Conversion
        ASSERT_EQ(true, !b2.to_bool(), "to_bool correctly returns True for True boolean");
        ASSERT_EQ(false, b3.to_bool(), "to_bool correctly returns False for False boolean");

    } catch (const std::exception& e) {
        std::cerr << "\033[31mERROR | Test failed: " << e.what() << "\033[0m\n";
    }

    std::cout << "\033[32mAll tests completed.\033[0m\n";
    return 0;
}

