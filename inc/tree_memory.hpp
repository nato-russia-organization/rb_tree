#pragma once

#include <iostream>
#include <memory>
#include <vector>

namespace tree {

template <typename ValueType> struct TreeMemory {
  class TreeNode {
  private:
    ValueType value;

    std::vector<std::unique_ptr<TreeNode>> children;

  public:
    const ValueType get_value() const { return value; }
    ValueType get_value() { return value; }

    const ValueType get_children() const { return children; }

    TreeNode(const ValueType &value,
             const std::vector<std::unique_ptr<TreeNode>> &children)
        : value(value), children(children) {}
  };

  std::unique_ptr<TreeNode> root;
  std::vector<TreeNode> nodes;

  void traverse_dump_from(const TreeNode &node) {
    for (auto &&x : node.childen) {
      traverse_dump_from(x);
      std::cout << x.get_value() << std::endl;
    }
  }
  void traverse_dump() { traverse_dump_from(root); }

  virtual ~TreeMemory() = default;
};
}; // namespace tree
