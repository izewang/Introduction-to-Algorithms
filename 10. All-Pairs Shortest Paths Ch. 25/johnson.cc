#include <climits> // INT_MAX, INT_MIN
#include "johnson.h"
#include "bellman_ford.h"
#include "dijkstra.h"

void Johnson(WeightedGraph & graph, int ** & distances, int ** & parents) {
    WeightedGraph graph_prime(graph.V + 1);
    CopyWeightOfGraph(graph_prime, graph);
    for (int i = 0; i < graph.V; ++i) {
        graph_prime.AddEdge(graph.V, i, 0);
    }
    if (!BellmanFord(graph_prime, graph.V)) {
        printf("Contains a negative circle.\n");
    }
    else {
        int * height = new int[graph.V];
        for (int i = 0; i < graph.V; ++i) {
            height[i] = graph_prime.distance[i];
        }
        // Reweights graph_prime.
        for (int u = 0; u < graph.V; ++u) {
            for (int v = 0; v < graph.V; ++v) {
                if (graph_prime.weight[u][v] != INT_MAX) {
                    graph_prime.weight[u][v] = graph_prime.weight[u][v] + height[u] - height[v];
                }
            }
        }
        for (int u = 0; u < graph.V; ++u) {
            Dijkstra(graph_prime, u);
            for (int v = 0; v < graph.V; ++v) {
                if (graph_prime.distance[v] != INT_MAX) {
                    distances[u][v] = graph_prime.distance[v] + height[v] - height[u];
                    parents[u][v] = graph_prime.parent[v];
                }
                else {
                    distances[u][v] = INT_MAX;
                    parents[u][v] = INT_MIN;
                }
            }
        }
    }
}

void CopyWeightOfGraph(WeightedGraph & to_graph, WeightedGraph & from_graph) {
    if (to_graph.V < from_graph.V) {
        printf("Can not copy from larger graph to smaller graph.\n");
        return;
    }
    to_graph.array = new AdjList[from_graph.V];
    for (int i = 0; i < from_graph.V; ++i) {
        to_graph.parent[i] = from_graph.parent[i];
        to_graph.distance[i] = from_graph.distance[i];
        for (int j = 0; j < from_graph.V; ++j) {
            to_graph.weight[i][j] = from_graph.weight[i][j];
        }
        AdjListNode * current_from_node = from_graph.array[i].head;
        AdjListNode * dummy_node = new AdjListNode(-1);
        dummy_node->next = nullptr;
        AdjListNode * prev_node = dummy_node, * current_to_node;
        while (current_from_node) {
            current_to_node = new AdjListNode(current_from_node->dest);
            prev_node->next = current_to_node;
            prev_node = current_to_node;
            current_from_node = current_from_node->next;
        }
        to_graph.array[i].head = dummy_node->next;
        delete dummy_node;
    }
}
