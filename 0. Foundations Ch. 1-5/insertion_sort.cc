#include "insertion_sort.h"

// Inserts each number to the correct place in the subarray before that number.
void InsertionSort(std::vector<int> & nums) {
    for (int i = 1; i < nums.size(); ++i) {
        int key = nums[i];
        // Inserts nums[i] to right place among nums[0], ..., nums[i - 1]
        while (i > 0 && nums[i - 1] > key) {
            nums[i] = nums[i - 1];
            --i;
        }
        nums[i] = key;
    }
}
