#ifndef UTILS_HPP
#define UTILS_HPP

#include <map>
#include <string>
#include <vector>

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::string> get_file_lines();

// Estrutura para armazenar os dados processados
struct GraphData {
  int graph_number;
  int k;
  std::map<int, std::vector<int>> interference_map;
};

GraphData process_file(const std::vector<std::string> &lines);

// Definindo o tipo de grafo
struct Graph {
  std::unordered_map<int, std::set<int>> adjacency_list;
  int k;
};

Graph build_graph(const GraphData &data);

struct NodeStack {
  int node;
  std::vector<int> neighbors;
  bool possible_spill;

  NodeStack(int node, const std::vector<int> &neighbors, bool possible_spill)
      : node(node), neighbors(neighbors), possible_spill(possible_spill) {}
};

void print_graph(const Graph &g);
GraphData parse_graph_data(const std::vector<std::string> &file_lines);
void print_graph_data(const GraphData &graph_data);
std::vector<std::pair<int, int>> sort_nodes_by_neighbors(const Graph &graph);
#endif // UTILS_HPP
