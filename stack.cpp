#include "stack.hpp"

std::stack<NodeStack> build_stack(Graph graph) {
  std::stack<NodeStack> stack;
  std::vector<std::pair<int, int>> sorted_nodes =
      sort_nodes_by_neighbors(graph);
  for (const auto &pair : sorted_nodes) {
    int node = pair.first;
  }
  return stack;
}
