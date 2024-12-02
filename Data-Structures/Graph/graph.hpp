#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <unordered_map>
#include <list>
#include <stdexcept>

template <typename T>
class Graph {
public:
    void add_vertex(const T& vertex) {
        adj_list[vertex] = std::list<T>();
    }

    void add_edge(const T& src, const T& dest) {
        if (adj_list.find(src) == adj_list.end() || adj_list.find(dest) == adj_list.end()) {
            throw std::invalid_argument("Both vertices must exist in the graph.");
        }
        adj_list[src].push_back(dest);
        adj_list[dest].push_back(src);  // Because it's an undirected graph
    }

    const std::list<T>& get_neighbors(const T& vertex) const {
        if (adj_list.find(vertex) == adj_list.end()) {
            throw std::invalid_argument("Vertex not found in the graph.");
        }
        return adj_list.at(vertex);
    }

    size_t size() const {
        return adj_list.size();
    }

private:
    std::unordered_map<T, std::list<T>> adj_list;
};

#endif

