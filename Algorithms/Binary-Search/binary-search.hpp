
#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include <vector>
#include <stdexcept>

template<typename T>
inline int binary_search(const std::vector<T>& v, T target) {
    if (v.empty()) {
        throw std::logic_error("Cannot search in an empty vector");
    }

    int left = 0;
    int right = v.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  
        if (v[mid] < target) {
            left = mid + 1;
        } else if (v[mid] > target) {
            right = mid - 1;
        } else {
            return mid;     
      }
    }
    throw std::logic_error(
      "Element Not Found In Vector"
    );
}

#endif

