#include "edmonds_karp.h"

int main() {
    // create the graph given in above fugure
    WeightedGraph graph(5);
    graph.AddEdge(0, 1, 16);
    graph.AddEdge(0, 3, 7);
    graph.AddEdge(1, 2, 5);
    graph.AddEdge(1, 3, 8);
    graph.AddEdge(1, 4, 4);
    graph.AddEdge(3, 2, 3);
    graph.AddEdge(3, 4, 9);
    //graph.AddEdge(4, 0, 2);
    graph.AddEdge(2, 4, 2);
    
    // print the adjacency list representation of the above graph
    graph.PrintGraph();
    
    EdmondsKarp(graph, 0, 2);
    
    printf("Weight Matrix:\n");
    for (int i = 0; i < graph.V; ++i) {
        for (int j = 0; j < graph.V; ++j) {
            if (graph.weight[i][j] < INT_MAX) {
                printf("%3i ", graph.weight[i][j]);
            }
            else {
                printf("Inf ");
            }
        }
        printf("\n");
    }
    return 0;
}