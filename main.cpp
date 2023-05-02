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

  // print_graph_data(data);

  Graph graph = build_graph(data);
  // print_graph(graph);
  //
  build_stack(graph);
  return 0;
}
