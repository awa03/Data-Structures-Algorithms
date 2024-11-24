
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <initializer_list>
#include <stdexcept>

template<typename T>
class Vector {
public:

    // Default Constructor
    Vector() : arr(nullptr), _size(0), _capacity(0) {}

    // Initializer-List Constructor
    Vector(std::initializer_list<T> list) : arr(nullptr), _size(0), _capacity(0) {
        resize(list.size());
        int index = 0;
        for (const auto& elem : list) {
            arr[index++] = elem;
        }
    }

    // Copy Constructor
    Vector(const Vector& v) : arr(nullptr), _size(0), _capacity(0) {
        copy(v);
    }

    // Move Constructor
    Vector(Vector&& v) noexcept : arr(v.arr), _size(v._size), _capacity(v._capacity) {
        v.arr = nullptr;
        v._size = 0;
        v._capacity = 0;
    }

    // Destructor
    ~Vector() {
        delete[] arr;
    }

    // Add element to the end
    void push_back(const T& element) {
        if (_size >= _capacity) {
            resize((_capacity == 0) ? 1 : _capacity * 2);
        }
        arr[_size++] = element;
    }

    void pop_back() {
        if (_size > 0) {
            --_size;
        }
    }

    // Clear the vector
    void clear() {
        _size = 0;
    }

    bool isEmpty() const {
        return (_size == 0);
    }

    // Get size
    int size() const {
        return _size;
    }

    int capacity() const {
        return _capacity;
    }

    T& operator[](int i) {
        if (i < 0 || i >= _size) {
            throw std::out_of_range("Index Out Of Range");
        }
        return arr[i];
    }

  void empty(){
    _size = 0;
  }

    const T& operator[](int i) const {
        if (i < 0 || i >= _size) {
            throw std::out_of_range("Index Out Of Range");
        }
        return arr[i];
    }

    Vector& operator=(const Vector& v) {
        if (this != &v) {
            copy(v);
        }
        return *this;
    }

    Vector& operator=(Vector&& v) noexcept {
        if (this != &v) {
            delete[] arr;
            arr = v.arr;
            _size = v._size;
            _capacity = v._capacity;
            v.arr = nullptr;
            v._size = 0;
            v._capacity = 0;
        }
        return *this;
    }

    // Equality operator
    bool operator==(const Vector& v) const {
        if (_size != v._size) {
            return false;
        }
        for (int i = 0; i < _size; ++i) {
            if (arr[i] != v.arr[i]) {
                return false;
            }
        }
        return true;
    }

    // Inequality operator
    bool operator!=(const Vector& v) const {
        return !(*this == v);
    }

    // Print vector (friend operator<<)
    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
        for (int i = 0; i < v._size; ++i) {
            os << v.arr[i] << " ";
        }
        return os;
    }

private:
    T* arr;
    int _size;
    int _capacity;

    // Copy elements from another vector
    void copy(const Vector& v) {
        delete[] arr;
        _capacity = v._capacity;
        _size = v._size;
        arr = new T[_capacity];
        for (int i = 0; i < _size; ++i) {
            arr[i] = v.arr[i];
        }
    }

    // Resize vector
    void resize(int new_capacity) {
        if (new_capacity <= _capacity) return;

        T* tmp = new T[new_capacity];
        for (int i = 0; i < _size; ++i) {
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
        _capacity = new_capacity;
    }
};

#endif

