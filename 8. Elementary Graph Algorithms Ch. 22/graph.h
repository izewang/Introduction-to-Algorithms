#ifndef graph_h
#define graph_h

#include <vector>
#include <list>
#include <climits>

enum Colors {BLACK, GRAY, WHITE};

struct Vertex {
    Colors color;
    int time_d, time_f;
    int distance;
    int parent;
    Vertex() : color{WHITE}, time_d{0}, time_f{0}, distance{INT_MAX}, parent{-1} {}
};

struct Graph {
    std::vector<Vertex> vertices;
    std::vector<std::list<int> > adjacency_list;
};

#endif /* graph_h */