#include "graph.hpp"
#include "stack.hpp"
#include "utils.hpp"
#include <iomanip>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> lines = get_file_lines();

  GraphData data = parse_graph_data(lines);
  int k = data.k;

  std::cout << "Graph " << data.graph_number << " -> Physical Registers: " << k
            << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  std::vector<int> results;
  do {
    Graph graph = build_graph(data);
    std::stack<NodeStack> stack = build_stack(graph);
    results.push_back(rebuild_graph(graph, stack));
    data.k -= 1;
  } while (data.k >= 2);

  std::cout << "----------------------------------------" << std::endl;
  std::cout << "----------------------------------------";
  int maxDigits = num_digits(k);
  for (int result : results) {
    std::cout << std::endl
              << "Graph " << data.graph_number
              << " -> K = " << std::setw(maxDigits) << k;
    if (result == 1) {
      std::cout << ": Successful Allocation";
    } else {
      std::cout << ": SPILL";
    }
    k--;
  }

  return 0;
}
