#ifndef optimal_binary_search_tree_h
#define optimal_binary_search_tree_h

#include <vector>
#include <climits>

// Optimize binary tree with nodes' probility stores in p and leaves' probility stores in q.
// Results are stored in roots and expectation.
void OptimalBinarySearchTree(int node_num, // number of nodes in binary tree
                             const std::vector<double> & p, // probabilites of key that stores in nodes
                             const std::vector<double> & q, // probabilities of dummies
                             std::vector<std::vector<int> > & root, // constructed tree
                             std::vector<std::vector<double> > & expectation // search expectation
                             );

#endif