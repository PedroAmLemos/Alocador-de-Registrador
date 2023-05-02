#include "stack.hpp"
#include "graph.hpp"
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

std::stack<NodeStack> build_stack(Graph &graph) {
  std::stack<NodeStack> stack;
  std::vector<std::pair<int, int>> sorted_nodes = sort_nodes_by_number(graph);
  const int num_iterations = sorted_nodes.size();
  int i;

  for (i = 0; i < num_iterations; i++) {
    // std::vector<std::pair<int, int>> sorted_nodes =
    // sort_nodes_by_number(graph);
    int node_number = find_min_and_remove(graph, sorted_nodes);

    std::cout << std::endl;
    std::cout << "Push: " << node_number;

    NodeStack stack_node;
    stack_node.node = node_number;
    stack_node.unavailable_registers =
        graph.nodes[node_number].unavailable_registers;
    stack_node.neighbors = graph.nodes[node_number].neighbors;

    if (stack_node.neighbors.size() > graph.k) {
      stack_node.possible_spill = true;
    } else {
      stack_node.possible_spill = false;
    }
    stack.push(stack_node);
    remove_number_from_neighbors(graph, node_number);
  }
  return stack;
}
