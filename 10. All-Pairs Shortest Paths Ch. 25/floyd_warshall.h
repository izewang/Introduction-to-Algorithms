#ifndef floyd_warshall_h
#define floyd_warshall_h

#include <climits> // INT_MIN, INT_MAX
#include <utility> // std::swap
#include "graph.h"

void FloydWarshall(WeightedGraph & graph, int ** & distances, int ** & parents);

#endif
