#ifndef dag_shortest_path_h
#define dag_shortest_path_h

#include <list>
#include "graph.h"
#include "bellman_ford.h"

// sorts vertices with topological sort algorithm.
std::list<int> TopologicalSort(const WeightedGraph & graph, int src);
void TopologicalSortHelper(const WeightedGraph & graph, bool * searched_nodes, int ver_num, int src,
                           std::list<int> & sorted_list);
// Find single sorce shortest for directed acyclic graph in linear time.
void DagShortestPath(WeightedGraph & graph, int src);

#endif
