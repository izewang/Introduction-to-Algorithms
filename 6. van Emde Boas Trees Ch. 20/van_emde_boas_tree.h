#ifndef van_emde_boas_tree_h
#define van_emde_boas_tree_h

#include <vector>
#include <cmath>
#include <utility>

// Implement of Van Emde Boas Tree, supporting Minimum, Maximum, successor, Predecessor
// Insert, Delete, Member methods in O(lglgn) time.
class VanEmdeBoasTree {
public:
    VanEmdeBoasTree(int u); // Set maximum number when initialize tree.
    // Returns minimal number in tree.
    int Minimum() const;
    // Returns maximal number in tree.
    int Maximum() const;
    // Returns boolean variable indicating whether x is in tree.
    bool Member(int x) const;
    // Returns successor of x stored in tree.
    int Successor(int x) const;
    // Returns predecessor of x stored in tree.
    int Predecessor(int x) const;
    // Inserts x into tree.
    void Insert(int x);
    // Removes x from tree.
    void Delete(int x);
private:
    // Tree node
    struct VanEmdeBoasTreeNode {
        VanEmdeBoasTreeNode(int x);
        ~VanEmdeBoasTreeNode();
        int LowerSquareRoot(int u) const;
        int UpperSquareRoot(int u) const;
        int High(int x) const;
        int Low(int x) const;
        int Index(int x, int y) const;
        int u;
        int min, max;
        VanEmdeBoasTreeNode * summary;
        std::vector<VanEmdeBoasTreeNode *> cluster;
    };
    // Returns minimum in subtree rooted at node.
    int Minimum(VanEmdeBoasTreeNode * node) const;
    // Returns maximum in subtree rooted at node.
    int Maximum(VanEmdeBoasTreeNode * node) const;
    // Returns boolean variable indicating whether x is in subtree rooted at node
    bool Member(VanEmdeBoasTreeNode * node, int x) const;
    // Returns successor of x stored in subtree rooted at node.
    int Successor(VanEmdeBoasTreeNode * node, int x) const;
    // Returns predecessor of x stored in subtree rooted at node.
    int Predecessor(VanEmdeBoasTreeNode * node, int x) const;
    // Helper function, inserts x into empty tree rooted at node.
    void EmptyTreeInsert(VanEmdeBoasTreeNode * node, int x);
    // Inserts x into subtree rooted at node.
    void Insert(VanEmdeBoasTreeNode * node, int x);
    // Delete x from subtree rooted at node.
    void Delete(VanEmdeBoasTreeNode * node, int x);
    
    VanEmdeBoasTreeNode * root_;
};

#endif
