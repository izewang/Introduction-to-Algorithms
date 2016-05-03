#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <string>

// Constructor, initializes private data members
template <typename T>
FibonacciHeap<T>::FibonacciHeap() : minimum_node_(nullptr), number_(0) {
    
}

// Destructor, frees allocated memories.
template <typename T>
FibonacciHeap<T>::~FibonacciHeap() {
    HandleType root = minimum_node_;
    if (root != nullptr) {
        std::queue<HandleType> current_level;
        current_level.push(root);
        while (!current_level.empty()) {
            std::queue<HandleType> next_level;
            while (!current_level.empty()) {
                HandleType current_node = current_level.front();
                HandleType end_node = current_node;
                current_level.pop();
                do {
                    if (current_node != nullptr) {
                        HandleType temp_node = current_node;
                        next_level.push(current_node->child);
                        current_node = current_node->right;
                        delete temp_node;
                    }
                } while (current_node != nullptr && current_node != end_node);
            }
            current_level = next_level;
        }
    }
}

// Inserts a value into container. Method builds new FibonacciHeapNode and adds it to root list.
// Updates minimum_node_ if necessary.
template <typename T>
typename FibonacciHeap<T>::HandleType FibonacciHeap<T>::Insert(ValueType const & value) {
    FibonacciHeapNode * node = new FibonacciHeapNode(value);
    // If FibonacciHeap is empty
    if (minimum_node_ == nullptr) {
        minimum_node_ = node;
        node->left = node->right = node;
    }
    else {
        // Add new node into root list and updates minimum_node when it is necessary.
        minimum_node_->right->left = node;
        node->right = minimum_node_->right;
        minimum_node_->right = node;
        node->left = minimum_node_;
        if (node->key < minimum_node_->key) {
            minimum_node_ = node;
        }
    }
    ++number_;
    return node;
}

// Returns value of minimum_node_
template <typename T>
typename FibonacciHeap<T>::ValueType const & FibonacciHeap<T>::Minimum() const {
    return minimum_node_->key;
}

// Merge two FibonacciHeap by concatenating root lists of them. Update minimum_node with the
// smaller of the old two minimum_nodes.
template <typename T>
void FibonacciHeap<T>::Union(FibonacciHeap & heap) {
    if (minimum_node_ == nullptr) {
        minimum_node_ = heap.minimum_node_;
    }
    else if (heap.minimum_node_ != nullptr) {
        // Merges two root lists
        minimum_node_->right->left = heap.minimum_node_;
        heap.minimum_node_->right->left = minimum_node_;
        FibonacciHeapNode * temp = minimum_node_->right;
        minimum_node_->right = heap.minimum_node_->right;
        heap.minimum_node_->right = temp;
        // Updates minimum_node_
        if (minimum_node_->key > heap.minimum_node_->key) {
            minimum_node_ = heap.minimum_node_;
        }
    }
    number_ += heap.number_;
    heap.minimum_node_ = nullptr;
}

// Adds all children of minimum_node_ into root list, then calls Consolidate() to sort fibonacci heap
// such that all branches in root list are of different degrees.
template <typename T>
void FibonacciHeap<T>::ExtractMin() {
    FibonacciHeapNode * min = minimum_node_;
    if (min != nullptr) {
        if (min->child != nullptr) {
            FibonacciHeapNode * current_node = min->child;
            // Set all parent pointer of nodes in min's children list as nullptr.
            while (current_node->parent != nullptr) {
                current_node->parent = nullptr;
                current_node = current_node->right;
            }
            // If there is no other nodes in root list besides min, set children list as new root list.
            if (min->right == min) {
                minimum_node_ = min->child;
            }
            // else, merges children list with old root list.
            else {
                min->right->left = min->child;
                min->left->right = min->child->right;
                min->child->right->left = min->left;
                min->child->right = min->right;
                minimum_node_ = min->right;
            }
        }
        else {
            // Remove minimum_node_ from loot list.
            if (min->right == min) {
                minimum_node_ = nullptr;
            }
            else {
                min->right->left = min->left;
                min->left->right = min->right;
                minimum_node_ = min->right;
            }
        }
        if (minimum_node_ != nullptr) {
            Consolidate(); // Makes all branches in root list are of different degrees.
        }
        --number_;
        delete min;
    }
}

//
template <typename T>
void FibonacciHeap<T>::Consolidate() {
    // root_nodes_of_degree stores points to a node with degree equalls to the index.
    std::vector<FibonacciHeapNode *> root_nodes_of_degree(DegreeUpperBound() + 1, nullptr);
    FibonacciHeapNode * current_node = minimum_node_, * dummy_node = new FibonacciHeapNode();
    if (minimum_node_ != nullptr) {
        // Adds dummy_node into root list to make sure all nodes in root list are only visited once,
        // during while loop.
        dummy_node->right = minimum_node_;
        dummy_node->left = minimum_node_->left;
        minimum_node_->left = minimum_node_->left->right = dummy_node;
        while (current_node != dummy_node) {
            int degree = current_node->degree;
            // Whenever current_node's degree equalls to one node identified, Link later one into
            // children list of current_node, such that current_node's degree incremented by 1.
            // Tereminates when current_node's degree is unique from all nodes identified.
            while (root_nodes_of_degree[degree] != nullptr) {
                FibonacciHeapNode * temp_node = root_nodes_of_degree[degree];
                if (current_node->key > temp_node->key) {
                    std::swap(current_node, temp_node);
                }
                Link(temp_node, current_node); // Link temp_node to child list of current_node
                root_nodes_of_degree[degree] = nullptr;
                ++degree;
            }
            root_nodes_of_degree[degree] = current_node;
            current_node = current_node->right;
        }
        minimum_node_ = nullptr;
        current_node = dummy_node->right;
        // Updates minimum_node by iterating on all nodes in root list.
        while (current_node != dummy_node) {
            if (minimum_node_ == nullptr) {
                minimum_node_ = current_node;
            }
            else if (current_node->key < minimum_node_->key) {
                minimum_node_ = current_node;
            }
            current_node = current_node->right;
        }
        // Removes dummy_node.
        dummy_node->right->left = dummy_node->left;
        dummy_node->left->right = dummy_node->right;
        delete dummy_node;
    }
}

template <typename T>
void FibonacciHeap<T>::Link(HandleType const & child_node, HandleType const & parent_node) {
    // Removes child_node from root list
    child_node->left->right = child_node->right;
    child_node->right->left = child_node->left;
    child_node->parent = parent_node;
    // Inserts child_node into parent_node's children list, right to parent_node->child.
    if (parent_node->child != nullptr) {
        child_node->left = parent_node->child;
        child_node->right = parent_node->child->right;
        parent_node->child->right->left = child_node;
        parent_node->child->right = child_node;
    }
    else {
        parent_node->child = child_node;
        child_node->right = child_node->left = child_node;
    }
    child_node->mark = false;
    ++(parent_node->degree);
}

template <typename T>
void FibonacciHeap<T>::Cut(HandleType const & child_node, HandleType const & parent_node) {
    // Cuts child_node from its siblings and parent_node.
    if (child_node->right == child_node) {
        parent_node->child = nullptr;
    }
    else {
        child_node->right->left = child_node->left;
        child_node->left->right = child_node->right;
        parent_node->child = child_node->right;
    }
    // Adds child_node into root list.
    child_node->parent = nullptr;
    child_node->right = minimum_node_->right;
    child_node->left = minimum_node_;
    minimum_node_->right->left = child_node;
    minimum_node_->right = child_node;
    child_node->mark = false;
}

// Recursively moves nodes to root list, as long as node's mark is true. It terminates after encounters
// first node with false mark, and set that node's mark true.
template <typename T>
void FibonacciHeap<T>::CascadingCut(HandleType const & node) {
    FibonacciHeapNode * parent_node = node->parent;
    if (parent_node != nullptr) {
        if (node->mark == false) {
            node->mark = true;
        }
        else {
            Cut(parent_node, node);
            CascadingCut(parent_node);
        }
    }
}

// First updates node's key if new key is smaller than old key, then moves node to root list and updates
// minimum_node_. Finally it calls CascadingCut() to optimize current fibonacci heap structure.
template <typename T>
void FibonacciHeap<T>::DecreaseKey(HandleType const & node, ValueType const & key) {
    if (key > node->key) {
        printf("new key is greater than old key.\n");
    }
    node->key = key;
    FibonacciHeapNode * parent_node = node->parent;
    if (parent_node != nullptr && parent_node->key > key) {
        Cut(node, parent_node);
        CascadingCut(parent_node);
    }
    if (key < minimum_node_->key) {
        minimum_node_ = node;
    }
}

template <typename T>
void FibonacciHeap<T>::Delete(HandleType const & handle) {
    DecreaseKey(handle, INT_MIN);
    ExtractMin();
}

template <typename T>
inline int FibonacciHeap<T>::DegreeUpperBound() {
    return floor(log(number_) / log(1.618));
}

// Prints tree in level order. Mainly used for test. Uses two queues to store current level
// and next level nodes, and terminates when all nodes are printed.
// Nodes in the same list is connected by '-'. Keys are printed in braces.
template <typename T>
void FibonacciHeap<T>::PrintTree() const {
    std::cout << "Begin of heap: " << std::endl;
    HandleType root = minimum_node_;
    if (root == nullptr) {
        std::cout << "nullptr" << std::endl;
    }
    else {
        std::queue<HandleType> current_level;
        current_level.push(root);
        while (!current_level.empty()) {
            std::queue<HandleType> next_level;
            while (!current_level.empty()) {
                HandleType current_node = current_level.front();
                HandleType end_node = current_node;
                current_level.pop();
                do {
                    if (current_node == nullptr) {
                        std::cout << "(nullptr) ";
                    }
                    else {
                        std::cout << "(" << current_node->key << ")-";
                        next_level.push(current_node->child);
                        current_node = current_node->right;
                    }
                } while (current_node != nullptr && current_node != end_node);
                std::cout << '\b' << " ";
            }
            current_level = next_level;
            std::cout << std::endl;
        }
    }
    std::cout << "End of heap" << std::endl;
}

template <typename T>
bool FibonacciHeap<T>::Empty() const {
    return number_ == 0;
}
