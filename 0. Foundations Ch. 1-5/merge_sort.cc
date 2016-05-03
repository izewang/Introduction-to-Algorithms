#include "merge_sort.h"

// Recursively divides array into two parts and sorts separately, then merges into one sorted array.
void MergeSort(std::vector<int> & nums, int p, int r) {
    if (p < r - 1) {
        int q = p + (r - p) / 2;
        // divide and conquer
        MergeSort(nums, p, q);
        MergeSort(nums, q, r);
        // combine
        Merge(nums, p, q, r);
    }
}

// Compares front element of two sorted subarrays and picks smaller element to form a new sorted array.
void Merge(std::vector<int> & nums, int p, int q, int r) {
    int len1 = q - p, len2 = r - q;
    int i = 0, j = 0, k = p;
    // copy nums[p], ..., nums[q - 1] to left, and copy nums[q], ..., nums[r - 1] to right.
    std::vector<int> left(nums.begin() + p, nums.end() + q);
    std::vector<int> right(nums.begin() + q, nums.end() + r);
    //merge left and right
    while (i < len1 && j < len2) {
        if (left[i] < right[j]) {
            nums[k] = left[i++];
            ++k;
        }
        else {
            nums[k] = right[j++];
            ++k;
        }
    }
    // left reaches end.
    if (i == len1) {
        while (j < len2) {
            nums[k] = right[j++];
            ++k;
        }
    }
    // right reaches end.
    if (j == len2) {
        while (i < len1) {
            nums[k] = left[i++];
            ++k;
        }
    }
}
