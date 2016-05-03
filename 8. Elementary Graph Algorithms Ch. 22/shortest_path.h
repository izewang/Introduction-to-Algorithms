#ifndef shortest_path_h
#define shortest_path_h

#include "breadth_first_search.h"

// Calculate and print shortest path from source to destination.
void ShortestPath(Graph & graph, int source, int destination);
void PrintPath(Graph & graph, int source, int destination);

#endif /* shortest_path_h */