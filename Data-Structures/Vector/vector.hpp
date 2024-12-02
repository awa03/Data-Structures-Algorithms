
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
        _size = list.size();
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
        arr[_size] = element;  // Place the element at the correct position
        _size++;               // Increment size
    }

    // Add element to the front
    void push_front(const T& element) {
        if (_size >= _capacity) {
            resize((_capacity == 0) ? 1 : _capacity * 2);
        }
        // Shift all elements to the right
        for (int i = _size; i > 0; --i) {
            arr[i] = arr[i - 1];
        }
        arr[0] = element;  // Place the new element at the front
        ++_size;
    }

    // Remove element from the back
    void pop_back() {
        if (_size > 0) {
            --_size;
        }
    }

    // Remove element from the front
    void pop_front() {
        if (_size == 0) return;  // Don't pop if the vector is empty
        for (int i = 1; i < _size; ++i) {
            arr[i - 1] = arr[i];  // Shift elements left
        }
        --_size;  // Decrease size after popping the front element
    }

    // Clear the vector
    void clear() {
        delete[] arr;  // Free memory
        arr = nullptr;  // Set to null after deletion
        _size = 0;
        _capacity = 0;
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

    // Access element at index (non-const)
    T& operator[](int i) {
        if (i < 0 || i >= _size) {
            throw std::out_of_range("Index Out Of Range");
        }
        return arr[i];
    }

    // Access element at index (const version)
    const T& operator[](int i) const {
        if (i < 0 || i >= _size) {
            throw std::out_of_range("Index Out Of Range");
        }
        return arr[i];
    }

    // Assignment operator (copy)
    Vector& operator=(const Vector& v) {
        if (this != &v) {
            copy(v);
        }
        return *this;
    }

    // Assignment operator (move)
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

    // Resize the vector
    void resize(int new_capacity) {
        if (new_capacity <= _capacity) return;  // No need to resize

        T* tmp = new T[new_capacity];  // Allocate new memory
        for (int i = 0; i < _size; ++i) {
            tmp[i] = arr[i];  // Copy elements
        }
        delete[] arr;  // Free old memory
        arr = tmp;      // Point to new memory
        _capacity = new_capacity;  // Update capacity
    }

private:
    T* arr;
    int _size;
    int _capacity;

    // Copy elements from another vector
    void copy(const Vector& v) {
        delete[] arr;  // Free current memory
        _capacity = v._capacity;
        _size = v._size;
        arr = new T[_capacity];  // Allocate new memory
        for (int i = 0; i < _size; ++i) {
            arr[i] = v.arr[i];  // Copy elements
        }
    }
};

#endif

