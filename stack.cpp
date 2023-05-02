#include "stack.hpp"

std::stack<NodeStack> build_stack(Graph graph) {

  // std::vector<std::pair<int, int>> sorted_nodes = sort_nodes_by_neighbors(graph);
  std::stack<NodeStack> stack;
  std::vector<std::pair<int, int>> sorted_nodes =
      sort_nodes_by_neighbors(graph);
  for (const auto &pair : sorted_nodes) {
    int node = pair.first;
  }

  // Imprimir os nós ordenados pelo número de vizinhos
  for (const auto& pair : sorted_nodes) {
    std::cout << "Node: " << pair.first << ", Neighbors: " << pair.second << std::endl;
  }
  return stack;
}
