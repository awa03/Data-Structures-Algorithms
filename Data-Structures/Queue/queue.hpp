#ifndef QUEUE_HPP
#define QUEUE_HPP

template<typename T>
class Queue {
  Queue(){
    head = nullptr;
    tail = nullptr;
    size = 0;
  }

  void push(T data){
    if(head == nullptr){
      head = new Node(data, nullptr, nullptr);
      tail = head;
    }
    else {
      Node* newHead(data, head, nullptr);
      head->Prev = newHead;
      head = newHead;
    }
    size++;
  }

  void pop(){
    if(head == nullptr){return;}
    Node* curr = head;
    if(curr == tail){

    }
    head->Next->Prev = nullptr;
  }



private:
  struct Node{
    Node* Next;
    Node* Prev;
    T data;
    Node(T newdata): data(newdata){}
    Node(T newdata, Node* newnext, Node* newprev) 
    : data(newdata), Next(newnext), Prev(newprev){}
  };

  Node* head;
  Node* tail;
  int size;
};

#endif
