#include <climits> // INT_MAX, INT_MIN
#include "johnson.h"
#include "floyd_warshall.h"


// Test Function
int main() {
    // Test forFloydWarshall
    // Create the graph given in above fugure
    WeightedGraph graph(5);
    graph.AddEdge(0, 1, 6);
    graph.AddEdge(0, 3, 7);
    graph.AddEdge(1, 2, 5);
    graph.AddEdge(1, 3, 8);
    graph.AddEdge(1, 4, 4);
    graph.AddEdge(3, 2, 3);
    graph.AddEdge(3, 4, 9);
    graph.AddEdge(4, 2, 7);
    // Prints the adjacency list representation of the above graph
    graph.PrintGraph();
    // Calls FloydWarshall
    int ** distances = new int*[graph.V];
    int ** parents = new int*[graph.V];
    for (int i = 0; i < graph.V; ++i) {
        distances[i] = new int[graph.V];
        parents[i] = new int[graph.V];
    }
    FloydWarshall(graph, distances, parents);
    // Prints results
    printf("Distance Matrix:\n");
    for (int i = 0; i < graph.V; ++i) {
        for (int j = 0; j < graph.V; ++j) {
            if (distances[i][j] < INT_MAX) {
                printf("%3i ", distances[i][j]);
            }
            else {
                printf("Inf ");
            }
        }
        printf("\n");
    }
    printf("Parent Matrix:\n");
    for (int i = 0; i < graph.V; ++i) {
        for (int j = 0; j < graph.V; ++j) {
            if (parents[i][j] != INT_MIN) {
                printf("%3i ", parents[i][j]);
            }
            else {
                printf("Nil ");
            }
        }
        printf("\n");
    }
    // Free allocated memories
    for (int i = 0; i < graph.V; ++i) {
        delete distances[i];
        delete parents[i];
    }
    delete [] distances;
    delete [] parents;
    
    // Test for Johnson
    // create the graph given in above fugure
    WeightedGraph graph_2(5);
    graph_2.AddEdge(0, 1, -16);
    graph_2.AddEdge(0, 3, 7);
    graph_2.AddEdge(1, 2, 5);
    graph_2.AddEdge(1, 3, 8);
    graph_2.AddEdge(1, 4, 4);
    graph_2.AddEdge(2, 1, -2);
    graph_2.AddEdge(3, 2, 3);
    graph_2.AddEdge(3, 4, 9);
    graph_2.AddEdge(4, 2, 7);
    // Prints the adjacency list representation of the above graph
    graph_2.PrintGraph();
    // Calls johnson
    distances = new int*[graph_2.V];
    parents = new int*[graph_2.V];
    for (int i = 0; i < graph_2.V; ++i) {
        distances[i] = new int[graph_2.V];
        parents[i] = new int[graph_2.V];
    }
    Johnson(graph, distances, parents);
    // Prints results
    printf("Distance Matrix:\n");
    for (int i = 0; i < graph_2.V; ++i) {
        for (int j = 0; j < graph_2.V; ++j) {
            if (distances[i][j] < INT_MAX) {
                printf("%3i ", distances[i][j]);
            }
            else {
                printf("Inf ");
            }
        }
        printf("\n");
    }
    printf("Parent Matrix:\n");
    for (int i = 0; i < graph_2.V; ++i) {
        for (int j = 0; j < graph_2.V; ++j) {
            if (parents[i][j] != INT_MIN) {
                printf("%3i ", parents[i][j]);
            }
            else {
                printf("Nil ");
            }
        }
        printf("\n");
    }
    // Free allocated memories
    for (int i = 0; i < graph_2.V; ++i) {
        delete distances[i];
        delete parents[i];
    }
    delete [] distances;
    delete [] parents;
    
    return 0;
}
