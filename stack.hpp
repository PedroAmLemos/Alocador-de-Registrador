#ifndef STACK_HPP
#define STACK_HPP

#include "graph.hpp"
#include <set>
#include <stack>

struct NodeStack {
  int node;
  std::set<int> neighbors;
  std::set<int> unavailable_registers;
  bool possible_spill;

  NodeStack(int node, const std::set<int> &neighbors, bool possible_spill, const std::set<int> unavailable_registers)
      : node(node), neighbors(neighbors), unavailable_registers(unavailable_registers), possible_spill(possible_spill) {}
};

std::stack<NodeStack> build_stack(Graph graph);

#endif // STACK_HPP
