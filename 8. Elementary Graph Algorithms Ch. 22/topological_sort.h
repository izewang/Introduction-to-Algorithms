#ifndef topological_sort_h
#define topological_sort_h

#include <list>
#include "graph.h"

std::list<int> TopologicalSort(Graph & graph);
void ModifiedDepthFirstSearch(Graph & graph, std::list<int> & sorted_list);
void ModifiedDepthFirstVisit(Graph & graph, int source, int & time, std::list<int> & sorted_list);

#endif /* topological_sort_h */