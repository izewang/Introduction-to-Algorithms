#ifndef radix_sort_h
#define radix_sort_h

#include <vector>

// Sorts nums according to dth digit starting from right with counting sort algorithm.
void CountingSortOnDigit(std::vector<int> & nums, int d);
// Sort nums from least significant digit to most significant digit with counting sort algorithm.
// d is the largest number of digits of nums.
void RadixSort(std::vector<int> & nums, int d);

#endif