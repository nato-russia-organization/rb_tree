#include "search_tree.hpp"
#include <iostream>

int main() {
  tree::TreeMemory<int> tree;

  tree.insert(1);
  tree.traverse_dump();
  std::cout << "You can now work with the tree" << std::endl;

  return 0;
}
