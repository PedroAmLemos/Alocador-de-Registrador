#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "utils.hpp"

struct GraphNode {
  std::set<int> neighbors;
  std::set<int> unavailable_registers;
};

// Definindo o tipo de grafo
struct Graph {
  std::unordered_map<int, GraphNode> nodes;
  int k;
};

Graph build_graph(const GraphData &data);

void print_graph(const Graph &g);

std::vector<std::pair<int, int>> sort_nodes_by_neighbors(const Graph &graph);
#endif // GRAPH_HPP
