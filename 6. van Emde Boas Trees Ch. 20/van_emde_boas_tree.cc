#include "van_emde_boas_tree.h"

// Allocates memories for all nodes and initializs.
VanEmdeBoasTree::VanEmdeBoasTreeNode::VanEmdeBoasTreeNode(int x) : u(x), min(-1), max(-1) {
    if (u > 2) {
        int upper_square_root_of_u = UpperSquareRoot(u);
        int lower_square_root_of_u = LowerSquareRoot(u);
        cluster.assign(upper_square_root_of_u, nullptr);
        for (int i = 0; i < upper_square_root_of_u; ++i) {
            cluster[i] = new VanEmdeBoasTreeNode(lower_square_root_of_u);
        }
        summary = new VanEmdeBoasTreeNode(upper_square_root_of_u);
    }
}

// Free allocated memories in constructor.
VanEmdeBoasTree::VanEmdeBoasTreeNode::~VanEmdeBoasTreeNode() {
    if (u > 2) {
        delete summary;
        for (int i = 0; i < cluster.size(); ++i) {
            delete cluster[i];
        }
    }
}

// Helper function used in VanEmdeBoasTreeNode
inline int VanEmdeBoasTree::VanEmdeBoasTreeNode::LowerSquareRoot(int u) const {
    return (int)pow(2, (int)floor(log2(u) / 2));
}

inline int VanEmdeBoasTree::VanEmdeBoasTreeNode::UpperSquareRoot(int u) const {
    return (int)pow(2, (int)ceil(log2(u) / 2));
}

inline int VanEmdeBoasTree::VanEmdeBoasTreeNode::High(int x) const {
    return floor(x / LowerSquareRoot(u));
}

inline int VanEmdeBoasTree::VanEmdeBoasTreeNode::Low(int x) const {
    return x % LowerSquareRoot(u);
}

inline int VanEmdeBoasTree::VanEmdeBoasTreeNode::Index(int x, int y) const {
    return x * LowerSquareRoot(u) + y;
}

// Public methods
int VanEmdeBoasTree::Minimum() const {
    return Minimum(root_);
}

int VanEmdeBoasTree::Maximum() const {
    return Maximum(root_);
}

bool VanEmdeBoasTree::Member(int x) const {
    return Member(root_, x);
}

int VanEmdeBoasTree::Successor(int x) const {
    return Successor(root_, x);
}

int VanEmdeBoasTree::Predecessor(int x) const {
    return Predecessor(root_, x);
}

void VanEmdeBoasTree::Insert(int x) {
    Insert(root_, x);
}

void VanEmdeBoasTree::Delete(int x) {
    Delete(root_, x);
}

VanEmdeBoasTree::VanEmdeBoasTree(int u) {
    root_ = new VanEmdeBoasTreeNode(u);
}

int VanEmdeBoasTree::Minimum(VanEmdeBoasTreeNode * node) const {
    return node->min;
}

int VanEmdeBoasTree::Maximum(VanEmdeBoasTreeNode * node) const {
    return node->max;
}

// Recursively find x in tree rooted at node.
bool VanEmdeBoasTree::Member(VanEmdeBoasTreeNode * node, int x) const {
    if (x == node->min || x == node->max) {
        return true;
    }
    else if (node->u == 2) {
        return false;
    }
    else {
        bool a = Member(node->cluster[node->High(x)], node->Low(x));
        return a;
    }
}

int VanEmdeBoasTree::Successor(VanEmdeBoasTreeNode * node, int x) const {
    // Base case.
    if (node->u == 2) {
        if (x == 0 && node->max == 1) {
            return 1;
        }
        else {
            return -1; // No successor in node.
        }
    }
    // If x is smaller than current minimum.
    else if (node->min != -1 && x < node->min) {
        return node->min;
    }
    else {
        int max_low = Maximum(node->cluster[node->High(x)]);
        // If successor is in current subtree.
        if (max_low != -1 && node->Low(x) < max_low) {
            int offset = Successor(node->cluster[node->High(x)], node->Low(x));
            return node->Index(node->High(x), offset);
        }
        // If successor is not in current subtree.
        else {
            int successor_cluster = Successor(node->summary, node->High(x));
            if (successor_cluster == -1) {
                return -1;
            }
            else {
                int offset = Minimum(node->cluster[successor_cluster]);
                return node->Index(successor_cluster, offset);
            }
        }
    }
}

int VanEmdeBoasTree::Predecessor(VanEmdeBoasTreeNode * node, int x) const {
    // Base case.
    if (node->u == 2) {
        if (x == 1 && node->min == 0) {
            return 0;
        }
        else {
            return -1; // No predecessor in node.
        }
    }
    // If x is greater than current maximum.
    else if (node->max != -1 && x > node->max) {
        return node->max;
    }
    else {
        int min_low = Minimum(node->cluster[node->High(x)]);
        // If successor is in current subtree.
        if (min_low != -1 && node->Low(x) > min_low) {
            int offset = Predecessor(node->cluster[node->High(x)], node->Low(x));
            return node->Index(node->High(x), offset);
        }
        // If successor is not in current subtree.
        else {
            int predecessor_cluster = Predecessor(node->summary, node->High(x));
            if (predecessor_cluster == -1) { // Because min in not stored in cluster.
                if (node->min != -1 && x > node->min) {
                    return node->min;
                }
                return -1;
            }
            else {
                int offset = Maximum(node->cluster[predecessor_cluster]);
                return node->Index(predecessor_cluster, offset);
            }
        }
    }
}

void VanEmdeBoasTree::EmptyTreeInsert(VanEmdeBoasTreeNode * node, int x) {
    node->min = x;
    node->max = x;
}

void VanEmdeBoasTree::Insert(VanEmdeBoasTreeNode * node, int x) {
    // If node is empty.
    if (node->min == -1) {
        EmptyTreeInsert(node, x);
    }
    else {
        // Updates min data.
        if (x < node->min) {
            std::swap(x, node->min);
        }
        if (node->u > 2) {
            if (Minimum(node->cluster[node->High(x)]) == -1) {
                EmptyTreeInsert(node->cluster[node->High(x)], node->Low(x));
                Insert(node->summary, node->High(x));
            }
            else {
                Insert(node->cluster[node->High(x)], node->Low(x));
            }
        }
        if (x > node->max) {
            node->max = x;
        }
    }
}

void VanEmdeBoasTree::Delete(VanEmdeBoasTreeNode * node, int x) {
    // If only one element in node.
    if (node->min == node->max) {
        node->min = -1;
        node->max = -1;
    }
    // If there are two elements in base structue.
    else if (node->u == 2) {
        if (x == 0) {
            node->min = 1;
        }
        else {
            node->max = 0;
        }
    }
    else {
        // If x is minimum of node, set min and x to second smallest value.
        if (node->min == x) {
            int first_cluster = Minimum(node->summary);
            if (first_cluster != -1) {
                x = node->Index(first_cluster, Minimum(node->cluster[first_cluster]));
                node->min = x;
            }
            else {
                node->min = -1;
            }
        }
        // Delete x from cluster
        Delete(node->cluster[node->High(x)], node->Low(x));
        // Update summary.
        // If cluster[node->High(x)] is empty, need to update summary.
        if (Minimum(node->cluster[node->High(x)]) == -1) {
            Delete(node->summary, node->High(x));
            // Update max of node.
            if (x == node->max) {
                int summary_max = Maximum(node->summary);
                if (summary_max == -1) {
                    node->max = node->min;
                }
                else {
                    node->max = node->Index(summary_max, Maximum(node->cluster[summary_max]));
                }
            }
        }
        // If cluster[node->High(x)] is not empty, update max of node.
        else if (x == node->max) {
            node->max = node->Index(node->High(x), Maximum(node->cluster[node->High(x)]));
        }
    }
}
