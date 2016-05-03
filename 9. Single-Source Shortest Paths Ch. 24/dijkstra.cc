#include <climits> // INT_MAX, INT_MIN
#include "dijkstra.h"

// Taking advantages of fibonacci heap's low computation time order of ExtractMin and
// DecreaseKey to implement dijkstra algorithm.
void Dijkstra(WeightedGraph & graph, int src) {
    FibonacciHeap<Vertex> heap;
    FibonacciHeap<Vertex>::HandleType * handles = new FibonacciHeap<Vertex>::HandleType[graph.V];
    // Initialize graph
    for (int i = 0; i < graph.V; ++i) {
        if (i != src) {
            Vertex vertex(i, INT_MAX);
            handles[i] = heap.Insert(vertex);
            graph.distance[i] = INT_MAX;
        }
        else {
            Vertex vertex(i, 0);
            heap.Insert(vertex);
            graph.distance[i] = 0;
        }
        graph.parent[i] = INT_MIN;
    }
    // In each loop adds closest vertex from heap and updates all its neighbours.
    while (!heap.Empty()) {
        auto temp_vertex = heap.Minimum();
        heap.ExtractMin();
        int u = temp_vertex.index;
        auto current_node = graph.array[u].head;
        while (current_node) {
            int v = current_node->dest;
            if (graph.distance[v] - graph.distance[u] > graph.weight[u][v]) {
                graph.distance[v] = graph.weight[u][v] + graph.distance[u];
                heap.DecreaseKey(handles[v], Vertex(v, graph.distance[v]));
                graph.parent[v] = u;
            }
            current_node = current_node->next;
        }
    }
}
