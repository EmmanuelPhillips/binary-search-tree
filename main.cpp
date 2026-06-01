#include <iostream>

struct Node {
  int value;
  Node *left;
  Node *right;

  Node(int v) : value{v}, left{nullptr}, right{nullptr} {}
};

int main() { return 0; }
