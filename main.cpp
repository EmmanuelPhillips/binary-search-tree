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

  void remove(int value) {
    if (m_root == nullptr) {
      std::cout << "No nodes to remove.\n";
      return;
    }
    Node *previous = nullptr;
    Node *current = m_root;
    while (current != nullptr) {
      if (value > current->value) {
        previous = current;
        current = current->right;
      } else if (value < current->value) {
        previous = current;
        current = current->left;
      } else {
        if (current->left == nullptr && current->right == nullptr) {
          if (previous == nullptr) {
            m_root = nullptr;
          } else if (previous->right == current) {
            previous->right = nullptr;
          } else {
            previous->left = nullptr;
          }
          delete current;
          return;
        } else if (current->left != nullptr && current->right == nullptr) {
          if (previous == nullptr) {
            m_root = current->left;
          } else if (previous->right == current) {
            previous->right = current->left;
          } else {
            previous->left = current->left;
          }
          delete current;
          return;
        } else if (current->left == nullptr && current->right != nullptr) {
          if (previous == nullptr) {
            m_root = current->right;
          } else if (previous->right == current) {
            previous->right = current->right;
          } else {
            previous->left = current->right;
          }
          delete current;
          return;
        } else {
          Node *successorParent = current;
          Node *successor = current->right;
          while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
          }
          current->value = successor->value;
          if (successorParent->left == successor) {
            successorParent->left = successor->right;
          } else {
            successorParent->right = successor->right;
          }
          delete successor;
          return;
        }
      }
    }
    std::cout << "Can't remove value that is not in BST.\n";
  }
};

int main() {
  BST bst{};
  return 0;
}
