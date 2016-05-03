#ifndef dijkstra_h
#define dijkstra_h

#include <climits>
#include "fibonacci_heap.h"
#include "graph.h"
#include "bellman_ford.h"

struct Vertex {
    int index, distance;
    Vertex() = default;
    Vertex(int index, int distance) : index(index), distance(distance) {}
    friend bool operator<(const Vertex & lhs, const Vertex & rhs) {
        return lhs.distance < rhs.distance;
    }
    inline friend bool operator>(const Vertex & lhs, const Vertex & rhs) {
        return rhs < lhs;
    }
    inline friend bool operator<=(const Vertex & lhs, const Vertex & rhs) {
        return !(rhs < lhs);
    }
    inline friend bool operator>=(const Vertex & lhs, const Vertex & rhs) {
        return !(lhs < rhs);
    }
};

// Dijkstra algorithm implemented by Fibonacci Heap.
void Dijkstra(WeightedGraph & graph, int src);

#endif
