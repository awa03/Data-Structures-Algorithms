#ifndef PAIR_HPP
#define PAIR_HPP

#include <system_error>

template<typename T, typename K>
struct pair {
    T first;
    K second;

    pair(T f, K s) : first(f), second(s) {}
    
    pair& operator=(const pair& other) {
        first = other.first;
        second = other.second;
        return *this;
    }
};

#endif
