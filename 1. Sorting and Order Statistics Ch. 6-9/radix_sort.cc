#include "radix_sort.h"

// Counts frequency of each number on digit d and copys each number to its sorted index
// from back to front.
void CountingSortOnDigit(std::vector<int> & nums, int d) {
    std::vector<int> sorted_nums(nums.size());
    std::vector<int> count(10, 0);
    int divisor = 1;
    for (int i = 0; i < d - 1; ++i) {
        divisor *= 10;
    }
    for (int i = 0; i < nums.size(); ++i) {
        ++count[(nums[i] / divisor) % 10];
    }
    // count[i] is the number of elements  whose dth digit equals to i.
    for (int i = 1; i < count.size(); ++i) {
        count[i] = count[i - 1] + count[i];
    }
    // count[i] is the number of elements whose dth digit is less than or equal to i.
    for (int i = nums.size() - 1; i >= 0; --i) {
        int index = (nums[i] / divisor) % 10;
        sorted_nums[count[index] - 1] = nums[i];
        --count[index];
    }
    nums = std::move(sorted_nums);
}

// Sorts numbers from least significant digit to most significant digit.
void RadixSort(std::vector<int> & nums, int d) {
    for (int i = 1; i <= d; ++i) {
        CountingSortOnDigit(nums, d);
    }
}
