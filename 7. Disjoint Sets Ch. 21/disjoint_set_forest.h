#ifndef disjoint_set_forest_h
#define disjoint_set_forest_h

#include <vector>

// Template container class implementing disjoint set forest, supporting MakeSet,
// FindSet and Union method. Data are stored tree structure keeping track of
// nodes' parent, value and rank.
template <typename T>
class DisjointSetForest {
public:
    struct DisjointSetForestNode {
        DisjointSetForestNode(T x) : val{x} {};
        DisjointSetForestNode * parent;
        int rank;
        T val;
    };
    typedef DisjointSetForestNode * HandleType;
    typedef T ValueType;
    
    DisjointSetForest() = default;
    ~DisjointSetForest();
    // Makes a set containing value x.
    HandleType MakeSet(ValueType x);
    // Unions two sets containing node_x and node_y.
    void Union(HandleType node_x, HandleType node_y);
    // Returns representative of node_x
    HandleType FindSet(HandleType node_x);
private:
    // Helper function. Links node_x and node_y in a way that the one with less rank
    // becomes children of the one with greater or equal rank.
    void Link(HandleType node_x, HandleType node_y);
    std::vector<HandleType> sets_; // all sets in DisjointSetForest
};

#include "disjoint_set_forest.cc"

#endif