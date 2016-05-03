#ifndef residual_network_graph_h
#define residual_network_graph_h

#include "graph.h"

/*
in "graph.h":
struct Graph {
    int V;
    AdjList * array;
    
    Graph(int v_num);
    ~Graph();
    void AddEdge(int src, int dest);
    void PrintGraph() const;
};

struct WeightedGraph : public Graph {
    int * parent, * distance;
    int ** weight;
    
    WeightedGraph(int v_num);
    ~WeightedGraph();
    void AddEdge(int src, int dest, int weight);
};
*/

struct ResidualNetworkGraph : public WeightedGraph {
    int ** capacity;
    int ** flow;
    
    ResidualNetworkGraph(int v_num);
    ~ResidualNetworkGraph();
    void ConstructFromWeightedGraph(const WeightedGraph & w_graph);
    void RemoveAdjEdge(int u, int v);
    void AddAdjEdge(int u, int v);
    bool IsEdge(int u, int v) const;
    bool SearchAugmentingPath(int src, int dest);
};

void CopyWeightOfGraph(WeightedGraph & to_graph, const WeightedGraph & from_graph);

#endif
