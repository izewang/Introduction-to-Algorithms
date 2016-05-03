#include <list>
#include "shortest_path.h"
#include "topological_sort.h"
#include "strongly_connected_components.h"

int main() {
    Graph graph;
    graph.vertices.assign(6, Vertex());
    int indices_0[] = {1, 3};
    std::list<int> list_0(indices_0, indices_0 + 2);
    graph.adjacency_list.push_back(list_0);
    std::list<int> list_1(1, 4);
    graph.adjacency_list.push_back(list_1);
    int indices_2[] = {5, 4};
    std::list<int> list_2(indices_2, indices_2 + 2);
    graph.adjacency_list.push_back(list_2);
    std::list<int> list_3(1, 1);
    graph.adjacency_list.push_back(list_3);
    std::list<int> list_4(1, 3);
    graph.adjacency_list.push_back(list_4);
    std::list<int> list_5(1, 5);
    graph.adjacency_list.push_back(list_5);
    ShortestPath(graph, 0, 0);
    ShortestPath(graph, 0, 1);
    ShortestPath(graph, 0, 2);
    ShortestPath(graph, 0, 3);
    ShortestPath(graph, 0, 4);
    ShortestPath(graph, 0, 5);
    ShortestPath(graph, 2, 3);
    ShortestPath(graph, 4, 1);
    ShortestPath(graph, 4, 0);
    std::list<int> sorted_list = TopologicalSort(graph);
    printf("Topological sorted list: ");
    for (auto iter = sorted_list.begin(); iter != sorted_list.end(); ++iter) {
        printf("%i ", *iter);
    }
    printf("\n");
    printf("Strongly connected component:\n");
    std::vector<std::list<int> > result = StronglyConnectedComponents(graph);
    for (int i = 0; i < result.size(); ++i) {
        for (auto iter = result[i].begin(); iter != result[i].end(); ++iter) {
            printf("%i ", *iter);
        }
        printf("\n");
    }
    return 0;
}