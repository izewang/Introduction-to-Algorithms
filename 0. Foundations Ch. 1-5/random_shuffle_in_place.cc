#include <cstdlib> // rand
#include <ctime> // time
#include "random_shuffle_in_place.h"

// For each position, randomly pick a position and swap numbers in these two positions.
void RandomShuffleInPlace(std::vector<int> & nums) {
    srand(time(NULL));
    for (int i = 0; i < nums.size(); ++i) {
        // Randomly pick a position from 0 to nums.size() - 1.
        int j = rand() % nums.size();
        if (j != i) { // swap nums[i] and nums[j].
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
}
