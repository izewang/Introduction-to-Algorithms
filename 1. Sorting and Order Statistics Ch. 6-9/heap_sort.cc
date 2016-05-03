#include <algorithm> // std::swap
#include "heap_sort.h"

// Uses BuildMaxHeap to build heap, then extracts maximum from heap and update heap with MaxHeapfy.
void HeapSort(std::vector<int> &nums) {
    int heap_size = nums.size();
    // Takes linear time to build max heap.
    BuildMaxHeap(nums, nums.size());
    for (int i = nums.size() - 1; i > 0; --i) {
        std::swap(nums[i], nums[0]); // Moves current largest number into its slot
        --heap_size;
        MaxHeapfy(nums, 0, heap_size); // Takes O(log(n)) time to max heapfy.
    }
}
