#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <iostream>
#include <vector>

template <typename T>
inline int partition(std::vector<T>& arr, int low, int high){
  int pivot = arr[high];
  int i = (low - 1);

  for(int j = low; j <= high - 1; j++){
    if(arr[j] <= pivot){
      i++;
      std::swap(arr[i], arr[j]);
    }
  }

  std::swap(arr[i+1], arr[high]);

  return (i+1);
}

template <typename T>
inline void quick_sort_helper(std::vector<T>& arr, int low, int high){
  if(low < high){
    int pi = partition(arr, low, high);
    quick_sort_helper(arr, low, pi - 1);
    quick_sort_helper(arr, pi + 1, high);
  } 
}

template <typename T>
inline void quick_sort(std::vector<T>& arr){
  quick_sort_helper(arr, 0, arr.size() - 1);
}



#endif
