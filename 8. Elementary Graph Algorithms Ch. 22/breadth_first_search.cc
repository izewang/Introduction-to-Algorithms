#include <queue>
#include <climits>
#include "breadth_first_search.h"

void BreadthFirstSearch(Graph & graph, int source) {
    // Initialize graph.
    for (auto iter = graph.vertices.begin(); iter != graph.vertices.end(); ++iter) {
        iter->color = WHITE;
        iter->parent = -1;
        iter->distance = INT_MAX;
    }
    // Start search from source.
    graph.vertices[source].color = GRAY;
    graph.vertices[source].distance = 0;
    // Add source into queue.
    std::queue<int> indices_queue;
    indices_queue.push(source);
    // Enqueue and update all WHITE neighbour vertices of first vertex in indices_queue,
    // until indices_queue is empty.
    while (!indices_queue.empty()) {
        int cur_vertex_index = indices_queue.front();
        indices_queue.pop();
        Vertex & cur_vertex = graph.vertices[cur_vertex_index];
        for (auto iter = graph.adjacency_list[cur_vertex_index].begin(); iter != graph.adjacency_list[cur_vertex_index].end(); ++iter) {
            Vertex & temp_vertex = graph.vertices[*iter];
            // Update temp_vertex's color, distance and parent, if its color is WHITE
            if (temp_vertex.color == WHITE) {
                temp_vertex.color = GRAY;
                temp_vertex.distance = cur_vertex.distance + 1;
                temp_vertex.parent = cur_vertex_index;
                indices_queue.push(*iter);
            }
        }
        cur_vertex.color = BLACK;
    }
}
