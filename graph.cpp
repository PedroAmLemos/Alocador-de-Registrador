#include "graph.hpp"
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <utility>
#include <vector>

// Função para construir o grafo de interferência a partir da estrutura
// GraphData
Graph build_graph(const GraphData &data) {
  std::cout << "----------------------------------------" << std::endl;
  Graph graph;
  graph.k = data.k;
  std::cout << "K = " << data.k << std::endl;

  for (const auto &pair : data.interference_map) {
    int node = pair.first;
    const std::vector<int> &neighbors = pair.second;

    for (int neighbor : neighbors) {
      if (neighbor < graph.k) {
        graph.nodes[node].unavailable_registers.insert(neighbor);
      }
      graph.nodes[node].neighbors.insert(neighbor);
      // graph.nodes[neighbor].neighbors.insert(node);
    }
  }

  return graph;
}

// Função para imprimir o grafo de interferência
void print_graph(const Graph &g) {
  std::cout << "Grafo de Interferência:" << std::endl;
  std::cout << "K= " << g.k << std::endl;
  for (const auto &node : g.nodes) {
    std::cout << "Nó " << node.first << ": ";
    for (const int &neighbor : node.second.neighbors) {
      std::cout << neighbor << " ";
    }
    std::cout << " -- Nao disponiveis ";
    for (const int &r : node.second.unavailable_registers) {
      std::cout << r << " ";
    }
    std::cout << std::endl;
  }
}

// Função auxiliar para ordenar pares pelo número de vizinhos
bool compare_by_neighbors(const std::pair<int, int> &a,
                          const std::pair<int, int> &b) {
  return a.second < b.second;
}

// Função auxiliar para ordenar pares pelo número de vizinhos
bool compare_by_number(const std::pair<int, int> &a,
                       const std::pair<int, int> &b) {
  return a.first < b.first;
}

// int find_min(Graph &graph) {
//   int min_node_id = -1;
//   int min_neighbors = std::numeric_limits<int>::max();
//
//   for (auto node : graph.nodes) {
//     int node_id = node.first;
//     int neighbors = 0;
//
//     // Conta apenas os vizinhos que não são pré-coloridos
//     for (auto neighbor : node.second.neighbors) {
//       if (neighbor >= graph.k) {
//         neighbors++;
//       }
//     }
//
//     if (neighbors < min_neighbors) {
//       min_neighbors = neighbors;
//       min_node_id = node_id;
//     }
//   }
//   return min_node_id;
// }

int find_min(Graph &graph) {
  int min_node_id = -1;
  int min_neighbors = std::numeric_limits<int>::max();

  for (auto node : graph.nodes) {
    int node_id = node.first;
    int neighbors = node.second.neighbors.size();

    if (neighbors < min_neighbors) {
      min_neighbors = neighbors;
      min_node_id = node_id;
    }
  }
  return min_node_id;
}

int find_max(Graph &graph) {
  int min_node_id = -1;
  int min_neighbors = std::numeric_limits<int>::min();

  for (auto node : graph.nodes) {
    int node_id = node.first;
    int neighbors = node.second.neighbors.size();

    if (neighbors > min_neighbors) {
      min_neighbors = neighbors;
      min_node_id = node_id;
    }
  }
  return min_node_id;
}

void remove_number_from_neighbors(Graph &graph, int number) {
  for (auto &node_entry : graph.nodes) {
    GraphNode &node = node_entry.second;
    node.neighbors.erase(number);
  }
  graph.nodes.erase(number);
}
