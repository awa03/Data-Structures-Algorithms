#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

// To make this a little easier we are going to use dummy nodes :)
// I will also show an example at a later point without dummy nodes

template<typename T>
class doubly_linked_list {
  doubly_linked_list(){ init(); }
  doubly_linked_list(const doubly_linked_list& other){
    init(); 
  }

  void insert(T data){
    auto* newNode = new Node(data, dummy_head->next, dummy_head);
    if(dummy_head->next == dummy_tail){
      dummy_tail->prev = newNode;
    } 
    else {
      dummy_head->next->prev = newNode;
    }
    _size++;
  }

  void insert_back(T data){
    auto* newNode = new Node(data, dummy_tail, dummy_tail->prev);
    if(dummy_tail->prev == dummy_head){
      dummy_head->next = newNode;
    }
    else {
      dummy_tail->prev->next = newNode;
    }
    _size++;
  }

  void remove(T data){

  }

  // get front element as pointer
  T* front(){
    if(dummy_head->next == nullptr){
      return;
    }
    return dummy_head->next->data;
  }

  // get back element as pointer
  T* back(){
    if(dummy_tail->prev == nullptr){
      return;
    }
    return dummy_tail->tail->data;
  }

  // get element as pointer 
  T* at(int index){

  }

  // get element at index
  T operator[](int index){
    return *at(index);
  }

private:

  struct Node {
    T data; 
    Node* next;
    Node* prev;
    Node(T d) : data(d) {}
    Node(T d, Node* n) : data(d), next(n) {} 
    Node(T d, Node* n, Node* p) : data(d), next(n), prev(p) {} 
    Node(Node* n, Node* p) : next(n), prev(p) {} 
  }; 

  void clear(){
    _size = 0;
  }

  void init(){
    dummy_head = new Node(dummy_tail, nullptr);
    dummy_tail = new Node(nullptr, dummy_head);
    _size = 0;
  }

  Node* dummy_head;
  Node* dummy_tail;
  int _size;

};

#endif
