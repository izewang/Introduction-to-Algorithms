#include <cstdlib>
#include <climits> // INT_MIN
#include <utility> // std::swap
#include "max_priority_queue.h"

// Copys nums to queue_ and calls BuildMaxHeap to build heap.
MaxPriorityQueue::MaxPriorityQueue(const std::vector<int> & nums) : queue_(nums) {
    BuildMaxHeap(queue_, queue_.size());
}

// Inserts key in the last of queue_, and calls HeapIncreaseKey to update structure.
void MaxPriorityQueue::MaxHeapInsert(int key) {
    queue_.push_back(INT_MIN);
    HeapIncreaseKey(queue_.size() - 1, key);
}

// Updates key at index i, and floats up until parent is greater than key.
void MaxPriorityQueue::HeapIncreaseKey(int i, int key) {
    if (queue_[i] > key) {
        printf("New key is smaller than current value.\n");
        exit(1);
    }
    // Updates new key
    queue_[i] = key;
    // Finds new key's location by comparing to its parent. Terminates when key is
    // smaller than its parent.
    int parent = (i + 1) / 2 - 1; // Parent's index.
    while (i > 0 && queue_[i] > queue_[parent]) {
        std::swap(queue_[i], queue_[parent]);
        i = parent;
        parent = (i + 1) / 2 - 1;
    }
}

// Switches last number to the first place then call max_heapfy to update its location
int MaxPriorityQueue::HeapExtractMax() {
    // MaxPriorityQueue may be empty.
    if (queue_.size() < 1) {
        printf("Heap underflow.\n");
        exit(1);
    }
    int heap_max = queue_[0];
    queue_[0] = queue_[queue_.size() - 1];
    queue_.pop_back();
    MaxHeapfy(queue_, 0, queue_.size());
    return heap_max;
}

// Returns front element in queue_.
int MaxPriorityQueue::HeapMaximum() const {
    return queue_[0];
}

// Returns size of queue_.
int MaxPriorityQueue::Size() const {
    return queue_.size();
}
