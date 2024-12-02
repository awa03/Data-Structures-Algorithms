#ifndef TRIE_HPP
#define TRIE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class trie {
public:
  // Constructors
  trie() { init(); }
  trie(const std::string& str) {
    init();
    insert(str);
  }
  trie(const std::vector<std::string>& strVec) {
    init();
    for (const auto& s : strVec) {
      insert(s);
    }
  }

  // Insert a string into the trie
  bool insert(const std::string& str) {
    if (str.empty()) return false;
    
    Node* curr = root;
    for (char c : str) {
      if (curr->children.find(c) == curr->children.end()) {
        curr->children[c] = new Node();
      }
      curr = curr->children[c];
    }
    
    if (curr->is_end) {
      return false; // Word already exists
    }
    
    curr->is_end = true;
    ++_size;
    return true;
  }

  // Remove a string from the trie
  bool remove(const std::string& str) {
    if (str.empty()) return false;
    
    return removeHelper(root, str, 0);
  }

  // Find a string in the trie
  bool find(const std::string& str) const {
    if (str.empty()) return false;
    
    Node* curr = root;
    for (char c : str) {
      if (curr->children.find(c) == curr->children.end()) {
        return false;
      }
      curr = curr->children[c];
    }
    
    return curr->is_end;
  }

  // Size of the trie
  size_t size() const {
    return _size;
  }

  // Destructor
  ~trie() {
    clear(root);
  }

private:
  struct Node {
    std::unordered_map<char, Node*> children;
    bool is_end;
    
    Node() : is_end(false) {}
  };

  Node* root;
  size_t _size;

  // Initialize the trie
  void init() {
    root = new Node();
    _size = 0;
  }

  // Helper function for remove
  bool removeHelper(Node*& curr, const std::string& str, size_t depth) {
    if (depth == str.length()) {
      if (!curr->is_end) {
        return false;
      }
      curr->is_end = false;
      --_size;
      return curr->children.empty();
    }
    
    char c = str[depth];
    if (curr->children.find(c) == curr->children.end()) {
      return false;
    }
    
    Node* child = curr->children[c];
    bool should_delete_child = removeHelper(curr->children[c], str, depth + 1);
    
    if (should_delete_child) {
      delete child;
      curr->children.erase(c);
    }
    
    return curr->children.empty() && !curr->is_end;
  }

  // Clear the trie
  void clear(Node* curr) {
    for (auto& pair : curr->children) {
      clear(pair.second);
    }
    delete curr;
  }
};

#endif // TRIE_HPP
