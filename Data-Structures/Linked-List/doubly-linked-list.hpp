#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP
#include <iostream>

template<typename T>
class doubly_linked_list {
public:
  doubly_linked_list() { init(); }

  doubly_linked_list(const doubly_linked_list& other) {
    init();
    auto curr = other.dummy_head->next;
    while (curr != other.dummy_tail) {
      insert_back(curr->data);
      curr = curr->next;
    }
  }

  ~doubly_linked_list() {
    clear();
    delete dummy_head;
    delete dummy_tail;
  }

  void insert(T data) {
    auto newNode = new Node(data, dummy_head->next, dummy_head);
    dummy_head->next->prev = newNode;
    dummy_head->next = newNode;
    if (dummy_tail->prev == dummy_head) {
      dummy_tail->prev = newNode;
    }
    ++_size;
  }

  void insert_back(T data) {
    auto newNode = new Node(data, dummy_tail, dummy_tail->prev);
    dummy_tail->prev->next = newNode;
    dummy_tail->prev = newNode;
    if (dummy_head->next == dummy_tail) {
      dummy_head->next = newNode;
    }
    ++_size;
  }

  void remove(T data) {
    if (dummy_head->next == dummy_tail) {
      return;
    }

    auto curr = dummy_head->next;
    while (curr != dummy_tail) {
      if (curr->data == data) {
        auto prev = curr->prev;
        auto next = curr->next;

        prev->next = next;
        next->prev = prev;

        delete curr;
        --_size;
        return;
      }
      curr = curr->next;
    }
  }

  T* front() {
    if (dummy_head->next == dummy_tail) {
      return nullptr;
    }
    return &dummy_head->next->data;
  }

  T* back() {
    if (dummy_tail->prev == dummy_head) {
      return nullptr;
    }
    return &dummy_tail->prev->data;
  }

  T* at(int index) {
    if (index < 0 || index >= _size) {
      throw std::out_of_range("Index out of bounds");
    }
    auto curr = dummy_head->next;
    for (int i = 0; i < index; ++i) {
      curr = curr->next;
    }
    return &curr->data;
  }

  T operator[](int index) {
    return *at(index);
  }

  doubly_linked_list& operator=(const doubly_linked_list& other) {
    if (this != &other) {
      clear();
      auto curr = other.dummy_head->next;
      while (curr != other.dummy_tail) {
        insert_back(curr->data);
        curr = curr->next;
      }
    }
    return *this;
  }

  void clear() {
    auto curr = dummy_head->next;
    while (curr != dummy_tail) {
      auto temp = curr;
      curr = curr->next;
      delete temp;
    }
    dummy_head->next = dummy_tail;
    dummy_tail->prev = dummy_head;
    _size = 0;
  }

  int size(){
    return _size;
  }

private:
  struct Node {
    T data;
    Node* next;
    Node* prev;
    Node(T d) : data(d), next(nullptr), prev(nullptr) {}
    Node(T d, Node* n, Node* p) : data(d), next(n), prev(p) {}
  };
  void init() {
    dummy_head = new Node(T());
    dummy_tail = new Node(T());
    dummy_head->next = dummy_tail;
    dummy_tail->prev = dummy_head;
    _size = 0;
  }

  Node* dummy_head;
  Node* dummy_tail;
  int _size;
};

#endif

