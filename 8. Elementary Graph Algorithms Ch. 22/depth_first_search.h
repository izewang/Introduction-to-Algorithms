#ifndef depth_first_search_h
#define depth_first_search_h

#include "graph.h"

// Update graph starting from source with DFS algorithm.
void DepthFirstSearch(Graph & graph);
// Helper function used to mark a node is discovered and finished.
void DepthFirstVisit(Graph & graph, int source, int & time);

#endif /* depth_first_search_h */