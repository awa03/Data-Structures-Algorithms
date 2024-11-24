#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include <iostream>
#include <math.h>

template<typename T>
inline int binary_search(std::vector<T> v, T target){
  if(v.empty()) {return -1;}
  int left = 0;
  int right = v.size() - 1;

  while(left <= right){
    int mid = (left + right) / 2;
    if(v[mid] < target){
      left = mid + 1;
    }
    else if(v[mid] > target){
      right = mid - 1;
    }
    else {
      return mid;
    }
  }
  return -1;
}

#endif
