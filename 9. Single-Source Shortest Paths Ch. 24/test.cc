#include <climits> // INT_MAX
#include <iostream>
#include "dijkstra.h"
#include "dag_shortest_path.h"

int main()
{
    // Test of Dijkstra
    // create the graph given in above fugure
    WeightedGraph graph(5);
    graph.AddEdge(0, 1, 6);
    graph.AddEdge(0, 3, 7);
    graph.AddEdge(1, 2, 5);
    graph.AddEdge(1, 3, 8);
    graph.AddEdge(1, 4, 4);
    graph.AddEdge(3, 2, 3);
    graph.AddEdge(3, 4, 9);
    graph.AddEdge(4, 2, 7);
    // print the adjacency list representation of the above graph
    graph.PrintGraph();
    
    Dijkstra(graph, 0);
    PrintDistances(graph);
    
    // Test of DagShortestPath
    // create the graph given in above fugure
    WeightedGraph graph_2(5);
    graph_2.AddEdge(0, 1, 6);
    graph_2.AddEdge(0, 3, 7);
    graph_2.AddEdge(1, 2, 5);
    graph_2.AddEdge(1, 3, 8);
    graph_2.AddEdge(1, 4, -4);
    graph_2.AddEdge(3, 2, -3);
    graph_2.AddEdge(3, 4, 9);
    graph_2.AddEdge(4, 2, 7);
    // print the adjacency list representation of the above graph
    graph_2.PrintGraph();
    DagShortestPath(graph_2, 0);
    PrintDistances(graph_2);
    
    return 0;
}