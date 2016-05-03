#ifndef quick_sort_h
#define quick_sort_h

#include <vector>

// Sort nums from nums[p] to nums[r] in place with quick sort algorithm, where pivot are randomly chosen.
void QuickSort(std::vector<int> & nums, int p, int r);
// Randomly chooses pivot with index ranges in [p, r], and partition around pivot. Returns index
// of pivot after partition.
int RandomizedPartition(std::vector<int> & nums, int p, int r);
// Splits subarray nums[p] to nums[r], taking nums[r] as pivot, such that numbers before
// pivot are smaller than pivot and numbers after pivot are greater than pivot. Returns
// index of pivot.
int Partition(std::vector<int> & nums, int p, int r);

#endif