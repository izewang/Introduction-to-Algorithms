#include "depth_first_search.h"

void DepthFirstSearch(Graph & graph) {
    for (int i = 0; i < graph.vertices.size(); ++i) {
        graph.vertices[i].color = WHITE;
        graph.vertices[i].parent = -1;
    }
    int time = 0;
    for (int i = 0; i < graph.vertices.size(); ++i) {
        if (graph.vertices[i].color == WHITE) {
            DepthFirstVisit(graph, i, time);
        }
    }
}

void DepthFirstVisit(Graph & graph, int source, int & time) {
    ++time;
    graph.vertices[source].time_d = time;
    graph.vertices[source].color = GRAY;
    for (auto iter = graph.adjacency_list[source].begin(); iter != graph.adjacency_list[source].end(); ++iter) {
        if (graph.vertices[*iter].color == WHITE) {
            graph.vertices[*iter].parent = source;
            DepthFirstVisit(graph, *iter, time);
        }
    }
    ++time;
    graph.vertices[source].time_f = time;
    graph.vertices[source].color = BLACK;
}
