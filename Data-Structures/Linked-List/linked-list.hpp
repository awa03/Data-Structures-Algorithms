#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

template<typename T>
class linked_list {

public:
  linked_list() : head(nullptr), _size(0) {}
  linked_list(T data) : head(new Node(data)), _size(0) {}
  ~linked_list(){
    clear();    
  }

  linked_list(const linked_list& other) : head(nullptr), _size(0) {
    Node* curr = other.head;
    while(curr != nullptr) {
      insert(curr->data); 
      curr = curr->next;
    }
  }  

  // insert node into list
  void insert(T data){
    if(head == nullptr){
      head = new Node(data);
    }
    else {
      Node* newNode = new Node(data, head);
      head = newNode;
    }
    _size++;
  }

  void insert_back(T data){
    if(head == nullptr){
      head = new Node(data);
    }
    else { 
      Node* tail = head;
      while(tail->next != nullptr){
        tail= tail->next;
      }
      tail->next = new Node(data);
    }
    _size++;
  }

  // remove a node from the list
  bool remove(T data){
    Node* curr = head;
    Node* prev = nullptr;
    while(curr != nullptr){
      if(curr->data == data){

        if(prev != nullptr)
          prev->next = curr->next; 

        else 
          head = curr->next;

        delete curr;
        _size--;
        return true;
      }
      prev = curr;
      curr = curr->next;
    }
    return false;
  }

  void clear(){
    Node* curr = head;
    Node* next;

    while(curr != nullptr){
      next = curr->next;
      delete curr;
      curr = next;
    }
    head = nullptr;
    _size = 0;
  }

  int size(){
    return _size;
  }

  T* at(const int& index){
    if(index < 0 || index >= _size) {
      throw std::out_of_range("Index out of range");
    }

    int i = 0;
    Node* curr = head;
    while(curr != nullptr){
      if(i == index){
        return &curr->data;
      }
      curr = curr->next;
      i++;
    }
    return nullptr;
  }

  linked_list operator=(const linked_list& other){
    if(&other == this){
      return *this;
    }

    clear();

    Node* curr = other.head;
    while(curr != nullptr){
      insert_back(curr->data);
      curr = curr->next;
    }
    return *this;
  }
    
  T* operator[](const int& index){
    return this->at(index);
  }

  std::ofstream& operator<<(std::ofstream& os){
   auto* curr = head;

    while(curr != nullptr){
      os << curr << " ";
      curr= curr->next;
    }
    return os;

  }

  void print(){
    auto* curr = head;

    while(curr != nullptr){
      std::cout << curr->data << " ";
      curr= curr->next;
    }
  }
    

private:
  struct Node {
    T data; 
    Node* next;
    Node(T d) : data(d) {}
    Node(T d, Node* n) : data(d), next(n) {} 
  }; 

  Node* head;
  int _size;
  
};


#endif 
