
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>

template<typename T>
class linked_list {
public:
    linked_list() : head(nullptr), _size(0) {}
    linked_list(T data) : head(new Node(data)), _size(1) {}
    ~linked_list() {
        clear();
    }

    linked_list(const linked_list& other) : head(nullptr), _size(0) {
        Node* curr = other.head;
        while (curr != nullptr) {
            insert_back(curr->data);
            curr = curr->next;
        }
    }

    void insert(T data) {
        head = new Node(data, head);
        _size++;
    }

    void insert_back(T data) {
        if (head == nullptr) {
            head = new Node(data);
        } else {
            Node* tail = head;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = new Node(data);
        }
        _size++;
    }

    bool remove(T data) {
        Node* curr = head;
        Node* prev = nullptr;
        while (curr != nullptr) {
            if (curr->data == data) {
                if (prev != nullptr) {
                    prev->next = curr->next;
                } else {
                    head = curr->next;
                }
                delete curr;
                _size--;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    void clear() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        head = nullptr;
        _size = 0;
    }

    int size() const {
        return _size;
    }

    T* at(const int& index) {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("Index out of range");
        }

        Node* curr = head;
        int i = 0;
        while (curr != nullptr) {
            if (i == index) {
                return &curr->data;
            }
            curr = curr->next;
            i++;
        }
        return nullptr;
    }

    linked_list& operator=(const linked_list& other) {
        if (&other == this) {
            return *this;
        }

        clear();
        Node* curr = other.head;
        while (curr != nullptr) {
            insert_back(curr->data);
            curr = curr->next;
        }
        return *this;
    }

    T* operator[](const int& index) {
        return this->at(index);
    }

    friend std::ostream& operator<<(std::ostream& os, const linked_list& list) {
        Node* curr = list.head;
        while (curr != nullptr) {
            os << curr->data << " ";
            curr = curr->next;
        }
        return os;
    }

    void print() const {
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

private:
    struct Node {
        T data;
        Node* next;
        Node(T d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* head;
    int _size;
};

#endif

