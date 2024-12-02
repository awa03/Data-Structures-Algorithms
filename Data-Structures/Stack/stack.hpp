
#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class Stack {
public:
    Stack() {}

    Stack(const Stack& s) {
        arr = s.arr;
    }

    Stack(Stack&& s) noexcept {
        arr = std::move(s.arr);
        s.arr.clear();
    }

    void push(const T& element) {
        arr.push_back(element);
    }

    T top() const {
        if (arr.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return arr.back();
    }

    T pop() {
        if (arr.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        T topElement = arr.back();
        arr.pop_back();
        return topElement;
    }

    int size() const {
        return arr.size();
    }

    bool isEmpty() const {
        return arr.empty();
    }

    Stack& operator=(const Stack& v) {
        if (this != &v) {
            arr = v.arr;
        }
        return *this;
    }

    Stack& operator=(Stack&& v) noexcept {
        if (this != &v) {
            arr = std::move(v.arr);
            v.arr.clear();
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Stack<T>& s) {
        for (auto e : s.arr) {
            os << e << " ";
        }
        return os;
    }

private:
    std::vector<T> arr;
};
