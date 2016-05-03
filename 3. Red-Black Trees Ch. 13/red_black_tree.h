#ifndef red_black_tree_h
#define red_black_tree_h

#include <memory> // std::unique_ptr

// Implements Red-Black Binary Search Tree container, supporting Insert and Delete in O(log(n)) computing time.
// Data are sotred in TreeNode according to their key of KeyType. Memory are managed by unique_ptr.
// TreeNode keep track of nodes' color, left & right unique_ptr and parent pointer. Insert() and Delete() function
// make sure that each modification maintains its Red-Black Tree structure:
// 0. TreeNode's color is either kBLACK or kRED.
// 1. Root are kBLACK, Leaves(nil) are kBLACK.
// 2. kRED TreeNode's children are kBLACK
// 3. each path from root_ to leaf has same number of kBLACK TreeNodes.
// Sample Usage:
//     RedBlackTree<int, int> rbtree;
//     rbtree.Insert(0, 1);
//     std::cout << "rbtree contains 0 :" << rbtree.Contains(0) << std::endl;
template <typename KeyType, typename ValueType>
class RedBlackTree {
public:
    RedBlackTree() {
        nil_.reset(new TreeNode());
    }
    RedBlackTree(const RedBlackTree &) = delete;
    RedBlackTree(RedBlackTree &&) = default;
    RedBlackTree & operator=(const RedBlackTree &) = delete;
    RedBlackTree & operator=(RedBlackTree &&) = default;
    ~RedBlackTree() {
        DeleteTree(root_);
        nil_.reset();
    }
    
    // If key exists, updates value, otherwise, creates a new TreeNode(key, value) inside RedBlackTree.
    void Insert(const KeyType & key, const ValueType & value);
    // Removes node with given key.
    void Delete(const KeyType & key);
    // Returns bool variable indicating whether there exisit a node whoes Key equals to key.
    bool Contains(KeyType key) const;
    // Returns ValueType value whoes key inside RedBlackTree equals to key.
    ValueType Search(KeyType key) const;
    // Print out RedBlackTree structure in order. Used for debug.
    void InorderTreeWalk() const;
    // Print out RedBlackTree structure in level order. Used for debug.
    void LevelorderTreeWalk() const;
private:
    enum Color {kRed, kBlack};
    // Maintains tree structure and store data and node's color.
    struct TreeNode {
        TreeNode () : color(kBlack), parent(nullptr) {}
        TreeNode(KeyType key, ValueType value) : key(key), value(value), color(kBlack), parent(nullptr) {}
        std::unique_ptr<TreeNode> left, right;
        TreeNode * parent;
        Color color;
        KeyType key;
        ValueType value;
    };
    typedef TreeNode * HandleType;
    
    // Rotates subtree rooted at node, such that node->right becomes new root of subtree.
    void LeftRotate(HandleType node);
    // Rotates subtree rooted at node, such that node->left becomes new root of subtree.
    void RightRotate(HandleType node);
    // Fixes situation where two kRED nodes are adjacent in a path from root to leaf.
    void InsertFixup(HandleType node);
    // Deletes node from RedBlackTree.
    void DeleteNode(HandleType node);
    // Makes from_node the new child of to_node's parent, also frees memory of to_nodes.
    void Transplant(HandleType to_node, HandleType from_node);
    // Fixes situation where the path from node to root has one less kBLACK node than other paths.
    void DeleteFixup(HandleType node);
    // Returns Handle of TreeNode with minimal key in subtree rooted at node.
    HandleType Minimum(HandleType node) const;
    // Returns Handle of TreeNode with key equals to key in subtree rooted at node.
    HandleType Search(int key, HandleType node) const;
    void InorderTreeWalk(HandleType node) const;
    // Frees memory allocated by unique_ptr.
    void DeleteTree(std::unique_ptr<TreeNode> & node);
    
    // root and empty leaf of RedBlackTree.
    std::unique_ptr<TreeNode> root_, nil_;
};

#include "red_black_tree.cc"

#endif
