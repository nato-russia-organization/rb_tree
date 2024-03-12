#pragma once

#include <iostream>
#include <memory>
#include <vector>

namespace tree {

template <typename ValueType> class TreeMemory final {
public:
  class TreeNode {
  private:
    ValueType value;

    TreeNode *parent = nullptr;

    std::vector<TreeNode *> children;

  public:
    const ValueType get_value() const noexcept { return value; }
    ValueType get_value() noexcept { return value; }

    const std::vector<TreeNode *> get_children() const noexcept {
      return children;
    }

    TreeNode(const ValueType &value) : value(value) {}

    void add_child(TreeNode *child) { children.push_back(child); }
    void add_parent(TreeNode *parent_ptr) noexcept { parent = parent_ptr; }
  };

private:
  TreeNode *root;
  std::vector<std::unique_ptr<TreeNode>> nodes;

public:
  void traverse_dump_from(const TreeNode *node) {
    std::cout << node->get_value() << std::endl;
    for (auto &&x : node->get_children()) {
      traverse_dump_from(x);
      std::cout << x->get_value() << std::endl;
    }
  }

  void traverse_dump() { traverse_dump_from(root); }

  void insert(ValueType value, TreeNode *parent_node = nullptr) {
    if (parent_node != nullptr) {
      nodes.emplace_back(std::make_unique<TreeNode>(TreeNode{value}));

      parent_node->add_child(nodes.back().get());
      nodes.back().get()->add_parent(parent_node);

    } else if (nodes.size() == 0) {
      nodes.emplace_back(std::unique_ptr<TreeNode>(new TreeNode{value}));

      root = nodes.back().get();
    } else {
      throw std::logic_error(
          "Trying to insert without specifying the parent_node defaults to "
          "root insertion, but this tree already has a root");
    }
  }
};
}; // namespace tree
