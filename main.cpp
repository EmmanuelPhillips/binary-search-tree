#include <iostream>

struct Node {
  int value;
  Node *left;
  Node *right;

  Node(int v) : value{v}, left{nullptr}, right{nullptr} {}
};

class BST {
private:
  Node *m_root;

  void deleteNode(Node *node) {
    if (node == nullptr) {
      return;
    }
    delete (node->left);
    delete (node->right);
    delete node;
  }

  void printInOrder(Node *node) {
    if (node == nullptr) {
      return;
    }
    printInOrder(node->left);
    std::cout << node->value << ' ';
    printInOrder(node->right);
  }

public:
  BST() : m_root{nullptr} {}
  ~BST() { deleteNode(m_root); }

  void printInOrder() { printInOrder(m_root); }

  void insert(int value) {
    Node *temp = new Node(value);
    if (m_root == nullptr) {
      m_root = temp;
      return;
    }
    Node *current = m_root;
    while (true) {
      if (value > current->value) {
        if (current->right == nullptr) {
          current->right = temp;
          return;
        } else {
          current = current->right;
        }
      } else if (value < current->value) {
        if (current->left == nullptr) {
          current->left = temp;
          return;
        } else {
          current = current->left;
        }
      } else {
        std::cout << "Node with value already exists.\n";
        return;
      }
    }
  }
};

int main() {
  BST bst{};
  return 0;
}
