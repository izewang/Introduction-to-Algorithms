#include "tree.h"

// Returns leftest node of tree.
Tree::HandleType Tree::Minimum(HandleType n) const {
    if (n == nullptr) {
        return n;
    }
    while (n->left != nullptr) {
        n = n->left;
    }
    return n;
}

// Returns rightest node of tree.
Tree::HandleType Tree::Maximum(HandleType n) const {
    if (n == nullptr) {
        return n;
    }
    while (n->right != nullptr) {
        n = n->right;
    }
    return n;
}

// Returns Minimum of right child if it's not empty, otherwise look up first parent node whose
// left subtree contains current node.
Tree::HandleType Tree::Successor(HandleType n) const {
    if (n->right != nullptr) {
        return Minimum(n->right);
    }
    HandleType p = n->parent;
    while (p != nullptr && n == p->right) {
        n = p;
        p = p->parent;
    }
    return p;
}

// Returns Maximum of left child if it's not empty, otherwise look up first parent whose right
// subtree contains current node.
Tree::HandleType Tree::Predecessor(HandleType n) const {
    if (n->left != nullptr) {
        return Maximum(n->left);
    }
    HandleType p = n->parent;
    while (p != nullptr && n == p->left) {
        n = p;
        p = p->parent;
    }
    return p;
}

// Calls Search(HandleType, int) to find handle of node with key value equals to key.
Tree::HandleType Tree::Search(int key) const {
    return Search(top_, key);
}

Tree::HandleType Tree::Top() const {
    return top_;
}

// Compares node's key from top to bottom to find right leaf postion, and links leaf node
// with given node.
void Tree::Insert(HandleType n) {
    HandleType cur = top_;
    HandleType p = nullptr;
    while (cur != nullptr) {
        p = cur;
        if (cur->key > n->key) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }
    n->parent = p;
    if (p == nullptr) {
        top_ = n;
    }
    else if (p->key < n->key) {
        p->right = n;
    }
    else {
        p->left = n;
    }
}

// If either left or right child is empty, replace current node with remaining child.
// otherwise, replace current node with successor node.
void Tree::Remove(HandleType n) {
    if (n->left == nullptr) {
        Transplant(n, n->right);
    }
    else if (n->right == nullptr) {
        Transplant(n, n->left);
    }
    else {
        HandleType suc = Minimum(n->right);
        if (suc != n->right) {
            Transplant(suc, suc->right);
            suc->right = n->right;
            n->right->parent = suc;
        }
        Transplant(n, suc);
        suc->left = n->left;
        n->left->parent = suc;
    }
}

// Compares key with nodes' key, and find node recursively in O(h) time.
Tree::HandleType Tree::Search(HandleType n, int key) const {
    if (n == nullptr || n->key == key) {
        return n;
    }
    if (key < n->key) {
        return Search(n->left, key);
    }
    else {
        return Search(n->right, key);
    }
}

// Updates u's parent node's pointer, such that they connects to v correctly.
void Tree::Transplant(HandleType u, HandleType v) {
    if (u->parent == nullptr) {
        top_ = v;
    }
    else if (u->parent->left == u) {
        u->parent->left = v;
    }
    else {
        u->parent->right = v;
    }
    if (v != nullptr) {
        v->parent = u->parent;
    }
}