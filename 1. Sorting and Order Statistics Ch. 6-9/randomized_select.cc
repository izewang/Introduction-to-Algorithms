#include <cstdlib> // rand
#include <ctime> // time
#include "randomized_select.h"
#include "quick_sort.h" // RandimizedPartition, Partition

// Randomely chooses pivot and partitions around pivot. Then compares pivot's order with k to
// recursively determine kth number.
int RandomizedSelect(std::vector<int> & nums, int p, int r, int k) {
    if (r == p) {
        return nums[p];
    }
    int q = RandomizedPartition(nums, p, r); // randomly pick a pivot
    // if pivot is the kth element, return its value
    if (q - p + 1 == k) {
        return nums[q];
    }
    // if kth element is smaller than pivot, find kth value in the former segment
    if (q - p + 1 > k) {
        return RandomizedSelect(nums, p, q - 1, k);
    }
    // else find kth value in the latter segment.
    else {
        return RandomizedSelect(nums, q + 1, r, k - (q - p + 1));
    }
}
