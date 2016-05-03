#include <utility> // std::move
#include "counting_sort.h"

void CountingSort(std::vector<int> & nums, int n) {
    std::vector<int> sorted_nums(nums.size());
    std::vector<int> count(n + 1, 0);
    // count[i] is the number of element equal to i.
    for (int i = 0; i < nums.size(); ++i) {
        ++count[nums[i]];
    }
    // count[i] is the number of element eaual to or less than i.
    // the last number which equals to i should locate at index count[i] - 1.
    for (int i = 1; i <= n; ++i) {
        count[i] = count[i - 1] + count[i];
    }
    // Copys each element in nums to its position from back to front.
    for (int i = nums.size() - 1; i >= 0; --i) {
        sorted_nums[count[nums[i]] - 1] = nums[i];
        --count[nums[i]];
    }
    // Moves result to nums.
    nums = std::move(sorted_nums);
}
