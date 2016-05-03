#ifndef bellman_ford_h
#define bellman_ford_h

#include <climits>
#include <iostream>
#include "graph.h"

// Returns false if negative circle is detected. Returns true otherwise.
// Updates each nodes parent and distance of shortes path to src.
bool BellmanFord(WeightedGraph & graph, int src);
// Helper function. Initializes graph given source src.
void InitializeSingleSource(WeightedGraph & graph, int src);
// Updates v's distance if there is a shorter path through u to v.
void Relax(WeightedGraph & graph, int u, int v);
// Prints all nodes' distance to source
void PrintDistances(const WeightedGraph & graph);

#endif
