#include "dag_shortest_path.h"

// Sorts vertices based on reverse order of finish time of depth first search.
std::list<int> TopologicalSort(const WeightedGraph & graph, int src) {
    std::list<int> sorted_list;
    bool * searched_nodes = new bool[graph.V];
    for (int i = 0; i < graph.V; ++i) {
        searched_nodes[i] = false;
    }
    searched_nodes[src] = true;
    TopologicalSortHelper(graph, searched_nodes, graph.V, src, sorted_list);
    delete [] searched_nodes;
    return sorted_list;
}

// Uses depth first search to iterates on vertices and add nodes in reverse order of finishing time.
void TopologicalSortHelper(const WeightedGraph & graph, bool * searched_nodes, int ver_num, int src,
                      std::list<int> & sorted_list) {
    auto adj_list = graph.array[src];
    auto current_node = adj_list.head;
    while (current_node) {
        if (!searched_nodes[current_node->dest]) {
            searched_nodes[current_node->dest] = true;
            TopologicalSortHelper(graph, searched_nodes, ver_num, current_node->dest, sorted_list);
        }
        current_node = current_node->next;
    }
    sorted_list.push_front(src);
}

// Breadth-first search according to logical sorted order.
void DagShortestPath(WeightedGraph & graph, int src) {
    auto sorted_list = TopologicalSort(graph, src);
    InitializeSingleSource(graph, src);
    for (auto iter = sorted_list.begin(); iter != sorted_list.end(); ++iter) {
        auto adj_list = graph.array[*iter];
        auto current_node = adj_list.head;
        while (current_node) {
            Relax(graph, *iter, current_node->dest);
            current_node = current_node->next;
        }
    }
}
