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

public:
  BST() : m_root{nullptr} {}
  ~BST() { deleteNode(m_root); }
};

int main() {
  std::cout << "HelloWorld";
  return 0;
}
