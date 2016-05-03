#ifndef johnson_h
#define johnson_h

#include "graph.h"

void Johnson(WeightedGraph & graph, int ** & distances, int ** & parents);
void CopyWeightOfGraph(WeightedGraph & to_graph, WeightedGraph & from_graph);

#endif
