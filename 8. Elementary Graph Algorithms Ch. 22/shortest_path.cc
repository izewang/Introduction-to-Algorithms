#include "shortest_path.h"

// Call BreadthFirstSearch function to update graph with BFS algorithm,
// then print parents from source to destionation.
void ShortestPath(Graph & graph, int source, int destination) {
    BreadthFirstSearch(graph, source);
    printf("Shortest path from %i to %i: ", source, destination);
    PrintPath(graph, source, destination);
    printf("\n");
}

void PrintPath(Graph & graph, int source, int destination) {
    if (source == destination) {
        printf("%i", source);
    }
    else if (graph.vertices[destination].parent == -1) {
        printf("There is no path from %i to %i.", source, destination);
    }
    else {
        PrintPath(graph, source, graph.vertices[destination].parent);
        printf(" %i", destination);
    }
}
