#include "stack.hpp"
#include "utils.hpp"
#include "graph.hpp"
#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <vector>

int main() {
  std::vector<std::string> lines = get_file_lines();

  GraphData data = parse_graph_data(lines);
  std::cout << "Graph " << data.graph_number << " -> Physical Registers: "<< data.k << std::endl;
  std::cout << "----------------------------------------" << std::endl;

  Graph graph = build_graph(data);
  
  std::stack<NodeStack> stack = build_stack(graph);

  return 0;
}
