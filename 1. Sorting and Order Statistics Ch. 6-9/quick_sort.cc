#include <utility> // std::swap
#include <ctime> // time
#include <cstdlib> // srand, rand
#include "quick_sort.h"

// Randomly picks pivot and divides nums around pivot and conquers both segments.
void QuickSort(std::vector<int> & nums, int p, int r) {
    if (p < r) {
        // Divide
        int q = RandomizedPartition(nums, p, r);
        // Conquer
        QuickSort(nums, p, q - 1);
        QuickSort(nums, q + 1, r);
    }
}

// Randomly selects a number and swaps with the last element.
int RandomizedPartition(std::vector<int> & nums, int p, int r) {
    srand(time(NULL));
    int i = rand() % (r - p + 1) + p;
    std::swap(nums[i], nums[r]);
    return Partition(nums, p, r);
}

// Compares each number from nums[p] to nums[r - 1], and moves thoes smaller than nums[r]
// to front part. Moves nums[r] next to last element smaller than it in the end.
int Partition(std::vector<int> & nums, int p, int r) {
    int i = p; // first index after last element identified that is smaller than pivot.
    int x = nums[r]; // x is pivot
    for (int j = p; j < r; ++j) {
        // Compares numbers with pivot, if smaller than x, move to index i.
        if (nums[j] < x) {
            std::swap(nums[i++], nums[j]);
        }
    }
    std::swap(nums[r], nums[i]);
    return i;
}
