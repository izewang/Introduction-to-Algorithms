#include <cmath> // floor()
#include "bucket_sort.h"

// Creates a number of buckets. The number of buckets equals to number of element in array.
// Then push elements into buckets based on its relative position in [0, 1). Sort numbers in
// each bucket by calling InsertionSort() and concatenates together finally. 
void BucketSort(std::vector<double> & nums) {
    // Creates nums.size() buckets.
    std::vector<std::vector<double> > buckets(nums.size(), std::vector<double>());
    // Pushes numbers into buckets.
    for (int i = 0; i < nums.size(); ++i) {
        int index = floor(nums.size() * nums[i]);
        buckets[index].push_back(nums[i]);
    }
    int k = 0;
    for (int i = 0; i < nums.size(); ++i) {
        // Uses insertion_sort for buckets[i] which are not empty.
        if (buckets[i].size() != 0) {
            InsertionSort(buckets[i]);
            // Copies sorted vector into nums.
            for (int j = 0; j < buckets[i].size(); ++j) {
                nums[k++] = buckets[i][j];
            }
        }
    }
}

// InsertionSort which deals with double elements.
void InsertionSort(std::vector<double> & nums) {
    for (int i = 1; i < nums.size(); ++i) {
        double key = nums[i];
        while (i > 0 && nums[i - 1] > key) { // Inserts nums[i] to right place among nums[0], ..., nums[i - 1]
            nums[i] = nums[i - 1];
            --i;
        }
        nums[i] = key;
    }
}
