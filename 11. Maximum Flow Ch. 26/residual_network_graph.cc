#include <climits> // INT_MAX, INT_MIN
#include <queue> // std::queue<int>
#include "residual_network_graph.h"

void CopyWeightOfGraph(WeightedGraph & to_graph, const WeightedGraph & from_graph) {
    if (to_graph.V < from_graph.V) {
        printf("Can not copy from larger graph to smaller graph.\n");
        return;
    }
    to_graph.array = new AdjList[from_graph.V];
    for (int i = 0; i < from_graph.V; ++i) {
        to_graph.parent[i] = from_graph.parent[i];
        to_graph.distance[i] = from_graph.distance[i];
        for (int j = 0; j < from_graph.V; ++j) {
            to_graph.weight[i][j] = from_graph.weight[i][j];
        }
        AdjListNode * current_from_node = from_graph.array[i].head;
        AdjListNode * dummy_node = new AdjListNode(-1);
        dummy_node->next = nullptr;
        AdjListNode * prev_node = dummy_node, * current_to_node;
        while (current_from_node) {
            current_to_node = new AdjListNode(current_from_node->dest);
            prev_node->next = current_to_node;
            prev_node = current_to_node;
            current_from_node = current_from_node->next;
        }
        to_graph.array[i].head = dummy_node->next;
        delete dummy_node;
    }
}

ResidualNetworkGraph::ResidualNetworkGraph(int v_num) : WeightedGraph(v_num){
    capacity = new int*[v_num];
    flow = new int*[v_num];
    for (int i = 0; i < v_num; ++i) {
        capacity[i] = new int[v_num];
        flow[i] = new int[v_num];
    }
}

ResidualNetworkGraph::~ResidualNetworkGraph() {
    for (int i = 0; i < V; ++i) {
        delete capacity[i];
        delete flow[i];
    }
    delete [] capacity;
    delete [] flow;
}

void ResidualNetworkGraph::ConstructFromWeightedGraph(const WeightedGraph & w_graph) {
    CopyWeightOfGraph(*this, w_graph);
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            capacity[i][j] = (weight[i][j] == INT_MAX) ? INT_MIN : weight[i][j];
            flow[i][j] = 0;
        }
    }
}

void ResidualNetworkGraph::RemoveAdjEdge(int u, int v) {
    AdjListNode * current_node = array[u].head;
    AdjListNode * dummy_node = new AdjListNode(-1);
    dummy_node->next = current_node;
    AdjListNode * prev_node = dummy_node;
    while (current_node) {
        if (current_node->dest == v) {
            prev_node->next = current_node->next;
            delete current_node;
            break;
        }
        current_node = current_node->next;
        prev_node = prev_node->next;
    }
    array[u].head = dummy_node->next;
    delete dummy_node;
}

void ResidualNetworkGraph::AddAdjEdge(int u, int v) {
    AdjListNode * new_node = new AdjListNode(v);
    new_node->next = array[u].head;
    array[u].head = new_node;
}

bool ResidualNetworkGraph::IsEdge(int u, int v) const {
    return weight[u][v] != INT_MAX;
}

bool ResidualNetworkGraph::SearchAugmentingPath(int src, int dest) {
    bool * searched_list = new bool[V];
    for (int i = 0; i < V; ++i) {
        searched_list[i] = false;
    }
    std::queue<int> neighbors;
    neighbors.push(src);
    searched_list[src] = true;
    while (!searched_list[dest] && !neighbors.empty()) {
        int current_vertex = neighbors.front();
        neighbors.pop();
        AdjListNode * current_node = array[current_vertex].head;
        while (current_node) {
            if (!searched_list[current_node->dest]) {
                neighbors.push(current_node->dest);
                searched_list[current_node->dest] = true;
                parent[current_node->dest] = current_vertex;
            }
            current_node = current_node->next;
        }
    }
    bool find_dest = searched_list[dest];
    delete [] searched_list;
    return find_dest;
}
