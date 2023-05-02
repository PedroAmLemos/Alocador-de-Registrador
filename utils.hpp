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

GraphData parse_graph_data(const std::vector<std::string> &file_lines);
void print_graph_data(const GraphData &graph_data);
int num_digits(int n);
#endif // UTILS_HPP
