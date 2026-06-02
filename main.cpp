#include <iostream>
#include <optional>

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

  int getHeight(Node *node) const {
    if (node == nullptr) {
      return 0;
    }
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
  }

public:
  BST() : m_root{nullptr} {}
  ~BST() { deleteNode(m_root); }

  void printInOrder() { printInOrder(m_root); }

  int getHeight() const { return getHeight(m_root); }

  std::optional<int> getMin() const {
    if (m_root == nullptr) {
      std::cout << "Empty BST.\n";
      return std::nullopt;
    }
    Node *min = m_root;
    while (min->left != nullptr) {
      min = min->left;
    }
    return min->value;
  }

  std::optional<int> getMax() const {
    if (m_root == nullptr) {
      std::cout << "Empty BST.\n";
      return std::nullopt;
    }
    Node *max = m_root;
    while (max->right != nullptr) {
      max = max->right;
    }
    return max->value;
  }

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

  bool contains(int value) {
    Node *current = m_root;
    while (current != nullptr) {
      if (value == current->value) {
        return true;
      } else if (value > current->value) {
        current = current->right;
      } else {
        current = current->left;
      }
    }
    return false;
  }
};

int main() {
  BST bst{};
  return 0;
}
