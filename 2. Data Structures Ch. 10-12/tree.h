#ifndef tree_h
#define tree_h

// Binary search tree class, keeps structure such that for each TreeNode, left child's key is
// smaller than current node's key, right child's key is greater than current node's key.
// memory allocation is not handled by class.
// Usage:
//     Tree tree;
//     Tree::TreeNode * node = new Tree::TreeNode(5);
//     tree.Insert(node);
//     printf("Tree's minimum is %i.\n", tree.Minimum());
class Tree {
public:
    struct TreeNode {
        TreeNode(int key) : key(key), left(nullptr), right(nullptr), parent(nullptr) {}
        TreeNode * left, * right, * parent;
        int key;
    };
    typedef TreeNode * HandleType;
    
    Tree() : top_(nullptr) {}
    // Returns handle of node with minimal key value.
    HandleType Minimum(HandleType) const;
    // Returns handle of node with maximal key value.
    HandleType Maximum(HandleType) const;
    // Returns handle of node which is next to current node in order.
    HandleType Successor(HandleType) const;
    // Returns handle of node which is right before current node in order.
    HandleType Predecessor(HandleType) const;
    // Returns handle of node with key value equals to key.
    HandleType Search(int key) const;
    // Returns handle of top_ node.
    HandleType Top() const;
    // Inserts given node into tree.
    void Insert(HandleType);
    // Removes given node from tree.
    void Remove(HandleType);
private:
    HandleType top_; // root of tree.
    // Returns handle of node with key value equals to key, under subtree of node. Returns nullptr
    // if is not found.
    HandleType Search(HandleType node, int key) const;
    // Replace node u with node v, maintaining children relations.
    void Transplant(HandleType u, HandleType v);
};

#endif
