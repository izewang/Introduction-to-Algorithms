#ifndef select_linear_time_h
#define select_linear_time_h

#include <vector>

// Returns kth number from nums[p] ... nums[r], worst case takes linear time.
int SelectLinearTime(std::vector<int> & nums, int p, int r, int k);
// Returns kth number's in index from nums[p] ... nums[r]
int SelectIndexLinearTime(std::vector<int> & nums, int p, int r, int k);
// Sorts numbers from nums[p] to nums[r] with insertion sort algorithm.
void InsertionSort(std::vector<int> & nums, int p, int r);

#endif
