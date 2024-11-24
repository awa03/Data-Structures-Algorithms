#ifndef LINEAR_SEARCH_HPP
#define LINEAR_SEARCH_HPP

#include <iostream>

template<typename T>
inline const T& linear_search(std::vector<T> v, T target){
  for(const auto& e : v){
    if(e == target){
      return e;
    }
  } 
  throw std::logic_error("item not found");
}
#endif
