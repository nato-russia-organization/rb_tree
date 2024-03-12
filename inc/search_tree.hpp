#pragma once

#include "tree_memory.hpp"
#include <concepts>

namespace tree {
namespace search_tree {

template <std::totally_ordered ValueType> class SearchTree {
private:
  TreeMemory<ValueType> memory;

public:
};

}; // namespace search_tree
}; // namespace tree
