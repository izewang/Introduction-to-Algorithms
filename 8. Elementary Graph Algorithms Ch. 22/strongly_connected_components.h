#ifndef strongly_connected_components_h
#define strongly_connected_components_h

#include <list>
#include <vector>
#include "graph.h"
#include "topological_sort.h"

std::vector<std::list<int> > StronglyConnectedComponents(Graph & graph);
Graph TransposeGraph(Graph & origin_graph);
void DepthFirstSearchHelper(Graph & graph, int source, std::list<int> & sc_component);

#endif /* strongly_connected_components_h */