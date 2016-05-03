#include "heap_sort.h"
#include "max_priority_queue.h"
#include "bucket_sort.h"
#include "counting_sort.h"
#include "quick_sort.h"
#include "radix_sort.h"
#include "randomized_select.h"
#include "select_linear_time.h"

// Test function
int main() {
    std::vector<int> nums;
    // Test HeapSort(std::vector<int> &).
    int num_array_1[] = {0, 9, 7, 4, 5, 1, 3, 2, 6, 8, 1};
    nums.assign(num_array_1, num_array_1 + sizeof(num_array_1) / sizeof(int));
    HeapSort(nums);
    printf("Heap Sort Result:\n");
    for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
        printf("%i ", *iter);
    }
    printf("\n");
    
    // Test MaxPriorityQueue.
    nums.assign(num_array_1, num_array_1 + sizeof(num_array_1) / sizeof(int));
    MaxPriorityQueue priority_queue(nums);
    priority_queue.HeapIncreaseKey(priority_queue.Size() - 1, 20);
    priority_queue.MaxHeapInsert(30);
    while (priority_queue.Size() > 0) {
        printf("%i ", priority_queue.HeapExtractMax());
    }
    printf("\n");
    
    // Test BucketSort(std::vector<double> &)
    double num_array_2[] = { 0.124, 0.234, 0.555, 0.643, 0.43, 0.489, 0.912, 0.902, 0.855, 0.746, 0.987, 0.243};
    std::vector<double> nums_2(num_array_2, num_array_2 + sizeof(num_array_2) / sizeof(double));
    BucketSort(nums_2);
    printf("Bucket Sort Result:\n");
    for (auto iter = nums_2.begin(); iter != nums_2.end(); ++iter) {
        printf("%.3f ", *iter);
    }
    printf("\n");
    
    // Test CountingSort(std::vector<int> &).
    nums.assign(num_array_1, num_array_1 + sizeof(num_array_1) / sizeof(int));
    CountingSort(nums, 10);
    printf("Counting Sort Result:\n");
    for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
        printf("%i ", *iter);
    }
    printf("\n");
    
    // Test QuickSort(std::vector<int> &, int, int)
    nums.assign(num_array_1, num_array_1 + sizeof(num_array_1) / sizeof(int));
    QuickSort(nums, 0, nums.size() - 1);
    printf("Quick Sort Result:\n");
    for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
        printf("%i ", *iter);
    }
    printf("\n");
    
    // Test RadixSort(std::vector<int> &, int)
    int num_array_3[] = {100, 31, 213, 973 ,224, 842 ,701, 493};
    nums.assign(num_array_3, num_array_3 + sizeof(num_array_3) / sizeof(int));
    RadixSort(nums, 3);
    printf("Radix Sort Result:\n");
    for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
        printf("%i ", *iter);
    }
    printf("\n");
    
    // Test RandomizedSelect(std::vector<int> &, int, int, int)
    nums.assign(num_array_3, num_array_3 + sizeof(num_array_3) / sizeof(int));
    printf("RandomizedSelect Result:\n");
    for (int i = 0; i < nums.size(); ++i) {
        printf("%i ", RandomizedSelect(nums, 0, nums.size() - 1, i + 1));
    }
    printf("\n");
    
    // Test SelectLinearTime(std::vector<int> &, int, int, int)
    nums.assign(num_array_3, num_array_3 + sizeof(num_array_3) / sizeof(int));
    printf("SelectLinearTime Result:\n");
    for (int i = 0; i < nums.size(); ++i) {
        printf("%i ", SelectLinearTime(nums, 0, nums.size() - 1, i + 1));
    }
    printf("\n");
    
    return 0;
}