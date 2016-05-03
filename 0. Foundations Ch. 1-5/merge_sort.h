#ifndef merge_sort_h
#define merge_sort_h

#include <vector>

// Sorts array starting from nums[p], to nums[r], by merge sort.
void MergeSort(std::vector<int> & nums, int p, int r);
// Merges array of array from nums[p] to nums[q - 1] and nums[q] to nums[r - 1].
void Merge(std::vector<int> & nums, int p, int q, int r);

#endif