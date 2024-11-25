#ifndef BINARY_TREE
#define BINARY_TREE

#include <algorithm>
#include <optional>

template<typename T>
class Tree {
public:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T d) : data(d), left(nullptr), right(nullptr) {}
        Node(T d, Node* l, Node* r) : data(d), left(l), right(r) {}
    };

    Tree() : root(nullptr), _size(0), _depth(0) {}
    Tree(const Tree& t) { root = copyNodes(t.root); _size = t._size; _depth = t._depth; }
    ~Tree() { clear(root); }

    Tree& operator=(const Tree& t) {
        if (this != &t) {
            clear(root);
            root = copyNodes(t.root);
            _size = t._size;
            _depth = t._depth;
        }
        return *this;
    }

    bool insert(const T& data) {
        if (!root) {
            root = new Node(data);
            _size++;
            _depth = 1;
            return true;
        }

        Node* curr = root;
        int checkDepth = 1;
        while (true) {
            if (curr->data == data) return false; 
            if (data < curr->data) {
                if (!curr->left) {
                    curr->left = new Node(data);
                    _size++;
                    _depth = std::max(_depth, checkDepth + 1);
                    return true;
                }
                curr = curr->left;
            } else {
                if (!curr->right) {
                    curr->right = new Node(data);
                    _size++;
                    _depth = std::max(_depth, checkDepth + 1);
                    return true;
                }
                curr = curr->right;
            }
            checkDepth++;
        }
    }

    bool remove(const T& data) {
        Node* curr = root;
        Node* prev = nullptr;

        while (curr) {
            if (curr->data == data) {
                if (!curr->left && !curr->right) {
                    if (!prev) root = nullptr;
                    else if (prev->left == curr) prev->left = nullptr;
                    else prev->right = nullptr;
                    delete curr;
                } else if (!curr->left || !curr->right) {
                    Node* child = curr->left ? curr->left : curr->right;
                    if (!prev) root = child;
                    else if (prev->left == curr) prev->left = child;
                    else prev->right = child;
                    delete curr;
                } else {
                    Node* successorParent = curr;
                    Node* successor = curr->right;
                    while (successor->left) {
                        successorParent = successor;
                        successor = successor->left;
                    }
                    curr->data = successor->data;
                    if (successorParent->left == successor) successorParent->left = successor->right;
                    else successorParent->right = successor->right;
                    delete successor;
                }
                _size--;
                return true;
            }
            prev = curr;
            curr = (data < curr->data) ? curr->left : curr->right;
        }
        return false;
    }

    bool contains(const T& data) { return getNode(data) != nullptr; }

    std::optional<T> find(const T& data) {
        Node* node = getNode(data);
        if (!node) return std::nullopt;
        return node->data;
    }

private:
    Node* root;
    int _size;
    int _depth;

    Node* getNode(const T& data) {
        Node* curr = root;
        while (curr) {
            if (curr->data == data) return curr;
            curr = (data < curr->data) ? curr->left : curr->right;
        }
        return nullptr;
    }

    Node* copyNodes(Node* node) {
        if (!node) return nullptr;
        return new Node(node->data, copyNodes(node->left), copyNodes(node->right));
    }

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
};

#endif
