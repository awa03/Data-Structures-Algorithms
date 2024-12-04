
#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <iostream>
#include <vector>

template<typename T>
void merge(std::vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<T> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {  
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template<typename T>
void merge_sort_helper(std::vector<T>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    merge_sort_helper(arr, left, mid);
    merge_sort_helper(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

template<typename T>
void merge_sort(std::vector<T>& arr) {
    if (arr.size() <= 1) {
        return;
    }
    merge_sort_helper(arr, 0, arr.size() - 1);
}

#endif

