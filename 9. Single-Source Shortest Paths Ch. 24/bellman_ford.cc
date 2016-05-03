#include <climits> // IN_MAX
#include "bellman_ford.h"

// Repeatedly updates all nodes's shortest path to src V times.
bool BellmanFord(WeightedGraph & graph, int src) {
    InitializeSingleSource(graph, src);
    for (int i = 0; i < graph.V - 1; ++i) {
        for (int u = 0; u < graph.V; ++u) {
            auto current_node = graph.array[u].head;
            while (current_node) {
                Relax(graph, u, current_node->dest);
                current_node = current_node->next;
            }
        }
    }
    for (int u = 0; u < graph.V; ++u) {
        auto current_node = graph.array[u].head;
        while (current_node) {
            if (graph.distance[current_node->dest] > graph.distance[u] + graph.weight[u][current_node->dest]) {
                return false;
            }
            current_node = current_node->next;
        }
    }
    return true;
}

// Initializes nodes' parent and distance.
void InitializeSingleSource(WeightedGraph & graph, int src) {
    for (int i = 0; i < graph.V; ++i) {
        graph.parent[i] = INT_MIN;
        graph.distance[i] = INT_MAX;
    }
    graph.distance[src] = 0;
}

// If path from u to v gives a shorter path for v to src, updates parent and distance for v.
void Relax(WeightedGraph & graph, int u, int v) {
    if (graph.distance[u] != INT_MAX && graph.weight[u][v] != INT_MAX
        && graph.distance[v] > graph.distance[u] + graph.weight[u][v]) {
        graph.distance[v] = graph.distance[u] + graph.weight[u][v];
        graph.parent[v] = u;
    }
}

void PrintDistances(const WeightedGraph & graph) {
    for (int i = 0; i < graph.V; ++i) {
        std::cout << i << "'s distance to source is " << graph.distance[i] << std::endl;
    }
}
