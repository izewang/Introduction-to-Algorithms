#include "heap.h"

// Compares value at position i and its children, if i is not the maximum,
// floats down until it's larger than all its children.
void MaxHeapfy(std::vector<int> & tree, int i, int heap_size) {
    int l = (i + 1) * 2 - 1, r = l + 1; // left and right subtree index.
    int temp_max = i;
    // Find max node among current node and its children.
    if (l < heap_size && tree[l] > tree[i]) {
        temp_max = l;
    }
    if (r < heap_size && tree[r] > tree[temp_max]) {
        temp_max = r;
    }
    // Swaps number at i and temp_max, and floats down node i.
    if (temp_max != i) {
        int temp = tree[i];
        tree[i] = tree[temp_max];
        tree[temp_max] = temp;
        MaxHeapfy(tree, temp_max, heap_size);
    }
}

// Builds max heap from bottom to top, by calling MaxHeapfy for each non-leaf node.
void BuildMaxHeap(std::vector<int> & tree, int heap_size) {
    for (int i = (heap_size) / 2 - 1; i >= 0; --i) {
        MaxHeapfy(tree, i, heap_size);
    }
}

