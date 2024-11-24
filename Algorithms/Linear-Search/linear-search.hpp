#ifndef LINEAR_SEARCH_HPP
#define LINEAR_SEARCH_HPP

#include <iostream>

template<typename T>
inline T& linear_search(std::vector<T> v, T target){
  for(auto& e : v){
    if(e == target){
      return e;
    }
  } 
  throw std::logic_error("item not found");
}
#endif
