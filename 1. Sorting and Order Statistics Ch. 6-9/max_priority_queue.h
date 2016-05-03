#ifndef max_priority_queue_h
#define max_priority_queue_h

#include "heap.h"

// A simple max priority_queue stores int type variables. Uses std::vector<int> to store data
// in max heap structure. Provides basic priority queue methods.
class MaxPriorityQueue {
public:
    MaxPriorityQueue() = default;
    // Construct MaxPriorityQueue from vector<int>.
    MaxPriorityQueue(const std::vector<int> & nums);
    // Inserts a key.
    void MaxHeapInsert(int key);
    // Increases a key at index i
    void HeapIncreaseKey(int i, int key);
    // Returns maximum and removes it from queue.
    int HeapExtractMax();
    // Returns maximum.
    int HeapMaximum() const;
    // Returns number of element in queue_.
    int Size() const;
private:
    friend void MaxHeapfy(std::vector<int> & tree, int i, int heap_size);
    friend void BuildMaxHeap(std::vector<int> & tree, int heap_size);
    // queue_ stores data in MaxPriorityQueue.
    std::vector<int> queue_;
};

#endif
