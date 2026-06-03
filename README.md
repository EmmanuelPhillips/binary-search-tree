# binary search tree
## my goal with this project
my initial goals were to:
- understand what a binary search tree is
- code one from scratch in c++
## what i learned
- what actually is a binary search tree
  - a data structure consisting of nodes, where each node holds a value, and a pointer to a left and right node (or nullptr).
  - left nodes are nodes with values lower than the parent node, and conversely right nodes are greater in value.
- the typical functionality
  - inserting and removing nodes
  - printing values in order
  - checking if a BST contains a specific node
  - checking the height of a BST
  - obtaining the min/max value
- why a binary search tree is better/worse than a linked list
  - searching is better: the time complexity is O(log n), due to the node pointing.
  - memory is more expensive: there is a need to store value, left pointer and right pointer. as well as potentially more metadata if you use it e.g. height.
## challenges i ran into
- recursion.
  - it was my first time actually thinking through it and how best to use it.
-removing nodes forced me to think more carefully about the structure than any other function. insertion follows a single path through the tree, but removal requires handling several distinct cases: deleting a leaf node, deleting a node with one child, and deleting a node with two children. the final case in particular took time to understand because it requires replacing the node while preserving the BST ordering property.
- i also did better with edge cases than previous projects, but still didn't consider everything for all functions
## what i would do differently
i would spend more time planning the operations before implementing them, particularly removal.
several bugs came from handling the common case correctly while overlooking less obvious tree configurations. sketching more examples on paper beforehand would likely have saved debugging time.

