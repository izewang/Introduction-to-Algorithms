#include <list>
#include <vector>
#include "graph.h"
#include "strongly_connected_components.h"

std::vector<std::list<int> > StronglyConnectedComponents(Graph & graph) {
    std::list<int> sorted_list = TopologicalSort(graph);
    Graph transposed_graph = TransposeGraph(graph);
    std::vector<std::list<int> > strongly_connected_components;
    for (auto iter = sorted_list.begin(); iter != sorted_list.end(); ++iter) {
        transposed_graph.vertices[*iter].color = WHITE;
    }
    for (auto iter = sorted_list.begin(); iter != sorted_list.end(); ++iter) {
        if (transposed_graph.vertices[*iter].color == WHITE) {
            std::list<int> sc_component;
            DepthFirstSearchHelper(transposed_graph, *iter, sc_component);
            strongly_connected_components.push_back(sc_component);
        }
    }
    return strongly_connected_components;
}

Graph TransposeGraph(Graph & origin_graph) {
    Graph transposed_graph;
    transposed_graph.vertices = origin_graph.vertices;
    transposed_graph.adjacency_list.assign(origin_graph.vertices.size(), std::list<int>());
    for (int i = 0; i < transposed_graph.vertices.size(); ++i) {
        for (auto iter = origin_graph.adjacency_list[i].begin(); iter != origin_graph.adjacency_list[i].end(); ++iter) {
            transposed_graph.adjacency_list[*iter].push_back(i);
        }
    }
    return transposed_graph;
}

void DepthFirstSearchHelper(Graph & graph, int source, std::list<int> & sc_component) {
    graph.vertices[source].color = GRAY;
    for (auto iter = graph.adjacency_list[source].begin(); iter != graph.adjacency_list[source].end(); ++iter) {
        if (graph.vertices[*iter].color == WHITE) {
            DepthFirstSearchHelper(graph, *iter, sc_component);
        }
    }
    graph.vertices[source].color = BLACK;
    sc_component.push_back(source);
}
