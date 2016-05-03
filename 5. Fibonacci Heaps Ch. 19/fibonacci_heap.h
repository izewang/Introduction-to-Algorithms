#ifndef fibonacci_heap_h
#define fibonacci_heap_h

// Implements a Fibonacci Heap container, supporting fast Union method besides regular heap methods.
// The template parater T is the type to be managed by this container.
// Sample Usage:
//     FibonacciHeap<int> fibonacci_heap;
template <typename T>
class FibonacciHeap {
public:
    // Tree node structure, which is used to store data and status needed by member functions.
    struct FibonacciHeapNode {
        FibonacciHeapNode() = default;
        FibonacciHeapNode(T const & value) : parent(nullptr), child(nullptr), left(nullptr), right(nullptr), degree(0), mark(false), key(value) {}
        FibonacciHeapNode * parent, * child, * left, * right;
        int degree;
        bool mark; // Whether node lost a child since last time it was made child of another node.
        T key;
    };
    typedef FibonacciHeapNode * HandleType;
    typedef T ValueType;
    
    FibonacciHeap();
    ~FibonacciHeap();
    // Inserts a element into container, and returns a handle to that node. Doesn't invalidate other handles.
    HandleType Insert(ValueType const & value);
    // Returns a const reference to minimum of heap.
    ValueType const & Minimum() const;
    // Merges current fibonacci heap with another.
    void Union(FibonacciHeap & heap);
    // Removes minimum from fibonacci heap. heap is set to be empty after union.
    void ExtractMin();
    // Decreases key value of given element.
    void DecreaseKey(HandleType const & node, ValueType const & key);
    // Deletes an element from container, given its handle.
    void Delete(HandleType const & handle);
    // Prints tree structure to screen, in level order. Mainly used for test.
    void PrintTree() const;
    // Returns whether this fibonacci heap is empty.
    bool Empty() const;
private:
    // Sorts fibonacci heap in a way such that all branches in root list are of different degrees.
    void Consolidate();
    // Moves child node from its original position to child list of parent node,
    // while maintaining a valid fibonacci heap structure.
    // It assumes that child and parent are all in root list, thus doesn't update node of child->parent
    void Link(HandleType const & child, HandleType const & parent);
    // Removes child node from parent node, and moves child node to root list.
    void Cut(HandleType const & child, HandleType const & parent);
    // Recursively moves nodes from bottom to top to rootlist, whenever the node's mark is true.
    // Terminates when reaches top or mark is false.
    void CascadingCut(HandleType const & node);
    // Returns degree upper bound.
    int DegreeUpperBound();
    // Handle of minimum element in fibonacci heap.
    HandleType minimum_node_;
    // The total number of elements in fibonacci heap.
    int number_;
};

#include "fibonacci_heap.cc"

#endif
