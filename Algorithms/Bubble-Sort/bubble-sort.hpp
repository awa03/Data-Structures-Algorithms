#ifndef BUBBLE_SORT
#define BUBBLE_SORT

#include <vector>

template<typename T>
inline bool sorted(std::vector<T> v){
  if(v.empty()){return true;}
  for(int i = 0; i < v.size() - 1; i++){
    if(v[i] > v[i+1]){
      return false;
    }
  }
  return true;
}

template<typename T>
inline std::vector<T> bubble_sort(std::vector<T> v){
  if(v.size() == 0) { return v; }
  int n = v.size();
  if(n <= 1){
    return v;
  }
  bool swapped;
  do {
    swapped = false; 
    for(int i = 0; i < n - 1; i++){
      if(v[i] > v[i+1]){
        std::swap(v[i], v[i+1]);
        swapped = true;
      }
    }
    n--;
  } while(swapped);
  return v;
}

#endif
