#ifndef graph_h
#define graph_h

#include <iostream>

struct AdjListNode {
    int dest;
    AdjListNode * next;
    
    AdjListNode(int dest) : dest(dest) {}
};

struct AdjList {
    struct AdjListNode * head;
    
    AdjList() : head(nullptr) {}
};

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

#endif
