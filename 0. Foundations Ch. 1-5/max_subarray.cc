#include <algorithm> // std::max
#include "max_subarray.h"

// Computing the max sum of consecutive subarray of nums, by comparing the sum of start a new subarray and
// the sum of original subarray. Always choose the one the maximize cur_max.
int MaxSubarray(std::vector<int> & nums) {
    int max_subarray; // Max sum of consecutive subarray.
    int cur_max; // Sum of current consecutive subarray.
    // Initialzie cur_max and max_subarray.
    if (nums.size() > 0) {
        cur_max = nums[0];
        max_subarray = cur_max;
    }
    for (int i = 1; i < nums.size(); ++i) {
        cur_max = std::max(nums[i], nums[i] + cur_max); // If nums[i] + curMax < nums[i], start a new subarray.
        max_subarray = std::max(max_subarray, cur_max); // Keeps note of the max sum of consecutive subarray.
    }
    return max_subarray;
}
