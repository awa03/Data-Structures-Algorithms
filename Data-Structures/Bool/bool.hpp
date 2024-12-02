
#ifndef BOOL_HPP
#define BOOL_HPP

#include <stdexcept>
#include <iostream>

struct boolean {
    // Constructor to initialize with True or False
    explicit boolean(int i) {
        if (i != True && i != False) {
            throw std::invalid_argument("Boolean can only be True or False");
        }
        val = i;
    }

    // Default constructor initializes to False
    boolean() : val(False) {}

    // Copy assignment operator
    boolean& operator=(const boolean& b) {
        val = b.val;
        return *this;
    }

    // Equality operator
    bool operator==(const boolean& b) const {
        return val == b.val;
    }

    // Inequality operator
    bool operator!=(const boolean& b) const {
        return val != b.val;
    }

    // Assignment from integer
    boolean& operator=(int i) {
        if (i == True || i == False) {
            val = i;
        } else {
            throw std::invalid_argument("Boolean can only be True or False");
        }
        return *this;
    }

    // Convert to a standard boolean
    bool to_bool() const {
        return val == True;
    }

private:
    int val;

    // Constants for True and False
    static constexpr int True = 1;
    static constexpr int False = 0;
};

#endif // BOOL_HPP

