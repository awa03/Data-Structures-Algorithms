#ifndef VECTOR_BINARY_TREE
#define VECTOR_BINARY_TREE

#include <vector>
#include <stdexcept>
#include <iostream>

template<typename T>
class VectorBinaryTree {

public:

    VectorBinaryTree() = default;

    void insert(const T& value) {
        tree.push_back(value);
    }

    const T& root() const {
        if (tree.empty()) {
            throw std::out_of_range("Tree is empty, no root exists.");
        }
        return tree[0];
    }


  void remove(const T& value) {
    auto it = std::find(tree.begin(), tree.end(), value);
    if (it != tree.end()) {
      size_t index = std::distance(tree.begin(), it);

      for (size_t i = index; i < tree.size() - 1; ++i) {
        tree[i] = tree[i + 1];
      }

      tree.pop_back();
    } else {
      throw std::invalid_argument("Value not found in the tree");
    }
  }

  const T& leftChild(int parentIndex) const {
    int leftIndex = 2 * parentIndex + 1;
    if (leftIndex >= tree.size()) {
      throw std::out_of_range("No left child exists for the given index.");
    }
    return tree[leftIndex];
  }

  const T& rightChild(int parentIndex) const {
    int rightIndex = 2 * parentIndex + 2;
    if (rightIndex >= tree.size()) {
      throw std::out_of_range("No right child exists for the given index.");
    }
    return tree[rightIndex];
  }

  bool contains(const T& value) const {
    for (const auto& item : tree) {
      if (item == value) {
        return true;
      }
    }
    return false;
  }

  size_t size() const {
    return tree.size();
  }

  void clear() {
    tree.clear();
  }

  void display() const {
    if (tree.empty()) {
      std::cout << "Tree is empty.\n";
      return;
    }

    for (const auto& value : tree) {
      std::cout << value << " ";
    }
    std::cout << "\n";
  }

private:
  std::vector<T> tree; 
};

#endif
