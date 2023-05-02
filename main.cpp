#include "utils.hpp"
#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <vector>

int main() {
  std::vector<std::string> lines = get_file_lines();
  GraphData data = parse_graph_data(lines);

  print_graph_data(data);

  Graph graph = build_graph(data);
  print_graph(graph);

  std::vector<std::pair<int, int>> sorted_nodes = sort_nodes_by_neighbors(graph);
  // Imprimir os nós ordenados pelo número de vizinhos
  for (const auto& pair : sorted_nodes) {
    std::cout << "Node: " << pair.first << ", Neighbors: " << pair.second << std::endl;
  }


  return 0;
}
