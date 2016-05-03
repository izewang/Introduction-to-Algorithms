#include <climits>
#include "Graph.h"

Graph::Graph(int v_num) : V(v_num) {
    array = new AdjList[v_num]();
}

Graph::~Graph() {
    delete [] array;
}

void Graph::AddEdge(int src, int dest) {
    AdjListNode * new_node = new AdjListNode(dest);
    new_node->next = array[src].head;
    array[src].head = new_node;
}

void Graph::PrintGraph() const {
    for (int i = 0; i < V; ++i) {
        std::cout << "Adjacency list of vertex " << i << ":" << std::endl;
        std::cout << i;
        auto current_node = array[i].head;
        while (current_node) {
            std::cout << " -> " << current_node->dest;
            current_node = current_node->next;
        }
        std::cout << std::endl;
    }
}

WeightedGraph::WeightedGraph(int v_num) : Graph(v_num) {
    parent = new int[v_num];
    distance = new int[v_num];
    weight = new int*[v_num];
    for (int i = 0; i < v_num; ++i) {
        weight[i] = new int[v_num];
        for (int j = 0; j < v_num; ++j) {
            weight[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
}

WeightedGraph::~WeightedGraph() {
    delete [] parent;
    delete [] distance;
    for (int i = 0; i < V; ++i) {
        delete [] weight[i];
    }
    delete [] weight;
}

void WeightedGraph::AddEdge(int src, int dest, int wgt) {
    Graph::AddEdge(src, dest);
    weight[src][dest] = wgt;
}