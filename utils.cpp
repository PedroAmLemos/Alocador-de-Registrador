#include "utils.hpp"
#include <algorithm>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

std::vector<std::string> get_file_lines() {
  std::vector<std::string> lines;
  std::string line;

  while (std::getline(std::cin, line)) {
    lines.push_back(line);
  }
  return lines;
}

GraphData parse_graph_data(const std::vector<std::string> &file_lines) {
  GraphData graph_data;

  // Iterar sobre as linhas do arquivo
  for (const std::string &line : file_lines) {
    // Se a linha contém a palavra "Grafo", extrair o número do grafo
    if (line.find("Grafo") != std::string::npos) {
      // Criar um objeto istringstream para facilitar a extração de dados da
      // string
      std::istringstream iss(line);
      std::string temp;
      // Extrair a palavra "Grafo" e o número do grafo para a estrutura
      // graph_data
      iss >> temp >> graph_data.graph_number;
    }
    // Se a linha contém "K=", extrair o valor de K
    else if (line.find("K=") != std::string::npos) {
      // Criar um objeto istringstream para facilitar a extração de dados da
      // substring que começa após "K=" (ou seja, a partir do índice 2 da string
      // line)
      std::istringstream iss(line.substr(2));
      // Extrair o valor de K para a estrutura graph_data
      iss >> graph_data.k;
    }
    // Caso contrário, assumir que a linha contém informações sobre os nós e
    // seus vizinhos
    else {
      // Criar um objeto istringstream para facilitar a extração de dados da
      // string
      std::istringstream iss(line);
      int node, neighbor;
      std::string arrow;

      // Extrair o número do nó e a seta ("-->") da linha
      iss >> node >> arrow;

      // Enquanto houver vizinhos para extrair na linha
      while (iss >> neighbor) {
        // Adicionar o vizinho à lista de vizinhos do nó na estrutura graph_data
        graph_data.interference_map[node].push_back(neighbor);
      }
    }
  }

  // Retornar a estrutura graph_data preenchida com os dados extraídos das
  // linhas do arquivo
  return graph_data;
}

// Função para imprimir os dados lidos do arquivo, armazenados em uma struct
// GraphData
void print_graph_data(const GraphData &graph_data) {
  std::cout << "Grafo " << graph_data.graph_number << ":\n";
  std::cout << "K=" << graph_data.k << std::endl;
  for (const auto &pair : graph_data.interference_map) {
    int node = pair.first;
    const std::vector<int> &neighbors = pair.second;

    std::cout << node << " --> ";
    for (int neighbor : neighbors) {
      std::cout << neighbor << " ";
    }
    std::cout << std::endl;
  }
}

// Função para construir o grafo de interferência a partir da estrutura
// GraphData
Graph build_graph(const GraphData &data) {
  Graph graph;
  graph.k = data.k;

  for (const auto &pair : data.interference_map) {
    int node = pair.first;
    const std::vector<int> &neighbors = pair.second;

    for (int neighbor : neighbors) {
      graph.adjacency_list[node].insert(neighbor);
      graph.adjacency_list[neighbor].insert(node);
    }
  }

  return graph;
}

// Função para imprimir o grafo de interferência
void print_graph(const Graph &g) {
  std::cout << "Grafo de Interferência:" << std::endl;
  std::cout << "K= " << g.k << std::endl;
  for (const auto &node : g.adjacency_list) {
    std::cout << "Nó " << node.first << ": ";
    for (const int &neighbor : node.second) {
      std::cout << neighbor << " ";
    }
    std::cout << std::endl;
  }
}

std::stack<NodeStack> create_stack_from_graph(Graph graph) {
  std::stack<NodeStack> stack;

  return stack;
}

// Função auxiliar para ordenar pares pelo número de vizinhos
bool compare_by_neighbors(const std::pair<int, int> &a,
                          const std::pair<int, int> &b) {
  return a.second < b.second;
}

std::vector<std::pair<int, int>> sort_nodes_by_neighbors(const Graph &graph) {
  std::vector<std::pair<int, int>> node_neighbor_count;

  // Criar um vetor de pares (nó, número de vizinhos)
  for (const auto &entry : graph.adjacency_list) {
    int node = entry.first;
    int neighbor_count = entry.second.size();
    node_neighbor_count.push_back(std::make_pair(node, neighbor_count));
  }

  // Ordenar o vetor pelo número de vizinhos
  std::sort(node_neighbor_count.begin(), node_neighbor_count.end(),
            compare_by_neighbors);

  return node_neighbor_count;
}
