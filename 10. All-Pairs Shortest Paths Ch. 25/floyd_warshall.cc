#include "floyd_warshall.h"

void FloydWarshall(WeightedGraph & graph, int ** & distances_prev, int ** & parents_prev) {
    int ** distances_cur = new int*[graph.V];
    int ** parents_cur = new int*[graph.V];
    for (int i = 0; i < graph.V; ++i) {
        distances_cur[i] = new int[graph.V];
        parents_cur[i] = new int[graph.V];
        for (int j = 0; j < graph.V; ++j) {
            distances_prev[i][j] = graph.weight[i][j];
            if (i == j || graph.weight[i][j] == INT_MAX) {
                parents_prev[i][j] = INT_MIN;
            }
            else {
                parents_prev[i][j] = i;
            }
        }
    }
    for (int k = 0; k < graph.V; ++k) {
        for (int i = 0; i < graph.V; ++i) {
            for (int j = 0; j < graph.V; ++j) {
                int new_distance;
                if (distances_prev[i][k] == INT_MAX || distances_prev[k][j] == INT_MAX) {
                    new_distance = INT_MAX;
                }
                else {
                    new_distance = distances_prev[i][k] + distances_prev[k][j];
                }
                if (new_distance < distances_prev[i][j]) {
                    distances_cur[i][j] = new_distance;
                    parents_cur[i][j] = parents_prev[k][j];
                }
                else {
                    distances_cur[i][j] = distances_prev[i][j];
                    parents_cur[i][j] = parents_prev[i][j];
                }
            }
        }
        std::swap(distances_prev, distances_cur);
        std::swap(parents_prev, parents_cur);
    }
    for (int i = 0; i < graph.V; ++i) {
        delete distances_cur[i];
        delete parents_cur[i];
    }
    delete [] distances_cur;
    delete [] parents_cur;
}
