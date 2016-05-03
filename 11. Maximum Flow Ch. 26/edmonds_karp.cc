#include <climits>
#include "edmonds_karp.h"

void EdmondsKarp(WeightedGraph & w_graph, int src, int dest) {
    ResidualNetworkGraph r_graph(w_graph.V);
    r_graph.ConstructFromWeightedGraph(w_graph);
    while (r_graph.SearchAugmentingPath(src, dest)) {
        int u, v;
        int critical_capacity = INT_MAX;
        r_graph.parent[src] = INT_MIN;
        v = dest;
        while ((u = r_graph.parent[v]) != INT_MIN) {
            critical_capacity = std::min(critical_capacity, r_graph.capacity[u][v]);
            v = u;
        }
        v = dest;
        while ((u = r_graph.parent[v]) != INT_MIN) {
            // Updates flow of graph.
            if (r_graph.IsEdge(u, v)) {
                r_graph.flow[u][v] += critical_capacity;
            }
            else {
                r_graph.flow[v][u] -= critical_capacity;
            }
            // Updates path capacity, adjacency list.
            r_graph.capacity[u][v] -= critical_capacity;
            r_graph.capacity[v][u] += critical_capacity;
            if (r_graph.capacity[u][v] == 0) {
                r_graph.RemoveAdjEdge(u, v);
                r_graph.AddAdjEdge(v, u);
            }
            v = u;
        }
    }
    printf("Flow Matrix:\n");
    for (int i = 0; i < r_graph.V; ++i) {
        for (int j = 0; j < r_graph.V; ++j) {
            printf("%3i ", r_graph.flow[i][j]);
        }
        printf("\n");
    }
}