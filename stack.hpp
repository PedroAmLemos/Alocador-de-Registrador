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
};

std::stack<NodeStack> build_stack(Graph &graph);

int rebuild_graph(Graph &graph, std::stack<NodeStack> stack);
#endif // STACK_HPP
