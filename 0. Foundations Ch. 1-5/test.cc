#include <vector>
#include "insertion_sort.h"
#include "merge_sort.h"
#include "max_subarray.h"
#include "random_shuffle_in_place.h"

// Test function
int main() {
    std::vector<int> nums;
    // Test InsertionSort(std::vector<int> &).
    int num_array_1[] = {0, 9, 7, 4, 5, 1, 3, 2, 6, 8, 1};
    nums.assign(num_array_1, num_array_1 + sizeof(num_array_1) / sizeof(int));
    InsertionSort(nums);
    printf("Insertion Sort Result:\n");
    for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
        printf("%i ", *iter);
    }
    printf("\n");
    
    // Test MergeSort(std::vector<int> &, int, int).
    nums.assign(num_array_1, num_array_1 + sizeof(num_array_1) / sizeof(int));
    MergeSort(nums, 0, nums.size());
    printf("Merge Sort Result:\n");
    for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
        printf("%i ", *iter);
    }
    printf("\n");
    
    // Test MaxSubarray(std::vector<int> &).
    int num_array_2[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    nums.assign(num_array_2, num_array_2 + sizeof(num_array_2) / sizeof(int));
    printf("Max sum of consecutive subarray of test_array is %i. \n", MaxSubarray(nums));
    
    // Test RandomShuffleInPlace(std::vector<int> &).
    nums.assign(num_array_1, num_array_1 + sizeof(num_array_1) / sizeof(int));
    printf("Random Shuffle Result:\n");
    RandomShuffleInPlace(nums);
    for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
        printf("%i ", *iter);
    }
    printf("\n");
    
    return 0;
}
