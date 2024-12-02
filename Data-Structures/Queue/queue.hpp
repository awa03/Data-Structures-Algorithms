
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <vector>
#include <stdexcept>

template<typename T>
class queue {
public:
    queue() {}

    queue(const queue& other) {
        q = other.q;
    }

    queue& operator=(const queue& other) {
        if (this != &other) {
            q = other.q;
        }
        return *this;
    }

    void push(const T& data) {
        q.push_back(data);
    }

    void pop() {
        if (is_empty()) {
            throw std::out_of_range("Queue is empty, cannot pop.");
        }
        q.erase(q.begin());
    }

    T& front() {
        if (is_empty()) {
            throw std::out_of_range("Queue is empty, cannot access front.");
        }
        return q.front();
    }

    bool is_empty() const {
        return q.empty();
    }

    size_t size() const {
        return q.size();
    }

private:
    std::vector<T> q;
};

#endif 
