#include "stack.hpp"
#include "graph.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

std::stack<NodeStack> build_stack(Graph &graph) {
  std::stack<NodeStack> stack;
  const int num_iterations = graph.nodes.size();
  int i;

  for (i = 0; i < num_iterations; i++) {
    int node_number = find_min(graph);
    bool possible_spill = false;
    if(graph.nodes[node_number].neighbors.size() >= graph.k){
      possible_spill = true;
      node_number = find_max(graph);
    }

    std::cout << std::endl;
    std::cout << "Push: " << node_number;
    if (possible_spill) {
      std::cout << " *";
    }

    NodeStack stack_node;
    stack_node.node = node_number;
    stack_node.unavailable_registers =
        graph.nodes[node_number].unavailable_registers;
    stack_node.neighbors = graph.nodes[node_number].neighbors;

    stack.push(stack_node);

    remove_number_from_neighbors(graph, node_number);
  }
  graph.nodes.clear();
  return stack;
}

int rebuild_graph(Graph &graph, std::stack<NodeStack> stack) {
  int stack_size = stack.size();

  for (int i = 0; i < stack_size; i++) {
    std::cout << std::endl;

    std::vector<int> registers(graph.k, -1);
    std::map<int, GraphNode> nodes = graph.nodes;

    NodeStack node = stack.top();
    int node_number = node.node;
    std::set<int> unavailable_registers = node.unavailable_registers;

    for (int value : unavailable_registers) {
      registers[value] = value;
    }

    // for (auto node_iter : nodes) {
    //   int n = node_iter.first;
    //   std::set<int> adj = node.neighbors;
    //   if (adj.count(n) > 0) {
    //     registers[node_iter.second.r] = n;
    //   }
    // }

    for (auto node_iter : nodes) {
      int n = node_iter.first;
      if (node.neighbors.count(n) > 0) {
        if (node_iter.second.r >= 0 /*&& node_iter.second.r < graph.k*/) {
          registers[node_iter.second.r] = n;
        }
      }
    }

    std::cout << "Pop: " << node_number;
    auto location = std::find(registers.begin(), registers.end(), -1);

    if (location != registers.end()) {
      // existe registrador
      int a = std::distance(registers.begin(), location);
      graph.nodes[node_number].r = a;
      std::cout << " -> " << a;
    } else {
      // spill
      std::cout << " -> NO COLOR AVAILABLE" << std::endl;
      return 0;
    }

    for (int neighbor : node.neighbors) {
      graph.nodes[node_number].neighbors.insert(neighbor);
      if (neighbor >= graph.k) {
        graph.nodes[neighbor].neighbors.insert(node_number);
      }
    }
    stack.pop();
  }
  std::cout << std::endl;
  return 1;
}
