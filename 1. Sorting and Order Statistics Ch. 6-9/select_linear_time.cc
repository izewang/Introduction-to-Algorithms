#include <cstdlib>
#include <algorithm>
#include "select_linear_time.h"
#include "quick_sort.h" // Partition

// Calls SelectIndexLinearTime to find index and returns its number.
int SelectLinearTime(std::vector<int> & nums, int p, int r, int k) {
    return nums[SelectIndexLinearTime(nums, p, r, k)];
}

int SelectIndexLinearTime(std::vector<int> & nums, int p, int r, int k) {
    // If only one element left in nums, return its index.
    if (r == p) {
        return p;
    }
    int i = p;
    // Sorts every five elements, swaps medium element into positions starting at p, i - 1 is the last element of mediums.
    for (int j = p; j <= r; j += 5) {
        InsertionSort(nums, j, std::min(j + 4, r));
        int mid_index = (j + 4 < r) ? (j + 2) : (j + (r - j) / 2);
        std::swap(nums[i], nums[mid_index]);
        ++i;
        
    }
    // Recursively finds the medium's index and partition around that element.
    int mid_index = SelectIndexLinearTime(nums, p, i - 1, (i - 1 - p) / 2 + 1);
    std::swap(nums[r], nums[mid_index]);
    int q = Partition(nums, p, r); // q is median of medians of 5-segments.
    // If q is kth element, done.
    if (k == q - p + 1) {
        return q;
    }
    // If q is previous k, finds k - (q - p + 1)th element in the upper segment
    else if (k > q - p + 1) {
        return SelectIndexLinearTime(nums, q + 1, r, k - (q - p + 1));
    }
    // Otherwise, finds kth element in lower segment
    else {
        return SelectIndexLinearTime(nums, p, q - 1, k);
    }
}

// Insertion sorts nums[p], ... , num[r]
void InsertionSort(std::vector<int> & nums, int p, int r) {
    for (int i = p; i <= r; ++i) {
        int key = nums[i];
        while (i > p && nums[i - 1] > key) { // insert nums[i] to right place among nums[0], ..., nums[i - 1]
            nums[i] = nums[i - 1];
            --i;
        }
        nums[i] = key;
    }
}
