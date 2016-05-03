#ifndef heap_h
#define heap_h

#include <vector>

// Floats down number at position i to maintain heap structure. Takes O(h) computing time.
void MaxHeapfy(std::vector<int> & tree, int i, int heap_size);
// Builds heap from array. Takes linear time.
void BuildMaxHeap(std::vector<int> & tree, int heap_size);

#endif
