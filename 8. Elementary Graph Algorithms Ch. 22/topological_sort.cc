#include <list>
#include "topological_sort.h"

std::list<int> TopologicalSort(Graph & graph) {
    std::list<int> sorted_list;
    ModifiedDepthFirstSearch(graph, sorted_list);
    return sorted_list;
}

void ModifiedDepthFirstSearch(Graph & graph, std::list<int> & sorted_list) {
    for (int i = 0; i < graph.vertices.size(); ++i) {
        graph.vertices[i].color = WHITE;
        graph.vertices[i].parent = -1;
    }
    int time = 0;
    for (int i = 0; i < graph.vertices.size(); ++i) {
        if (graph.vertices[i].color == WHITE) {
            ModifiedDepthFirstVisit(graph, i, time, sorted_list);
        }
    }
}

void ModifiedDepthFirstVisit(Graph & graph, int source, int & time, std::list<int> & sorted_list) {
    ++time;
    graph.vertices[source].time_d = time;
    graph.vertices[source].color = GRAY;
    for (auto iter = graph.adjacency_list[source].begin(); iter != graph.adjacency_list[source].end(); ++iter) {
        if (graph.vertices[*iter].color == WHITE) {
            graph.vertices[*iter].parent = source;
            ModifiedDepthFirstVisit(graph, *iter, time, sorted_list);
        }
    }
    ++time;
    graph.vertices[source].time_f = time;
    graph.vertices[source].color = BLACK;
    sorted_list.push_front(source);
}