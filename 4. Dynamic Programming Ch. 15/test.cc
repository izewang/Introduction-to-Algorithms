#include <cstdio> // printf
#include "longest_common_subsequence.h"
#include "optimal_binary_search_tree.h"

// Test function
int main() {
    // Test for LongestCommonSubsequence(std::string, std::string).
    printf("Test LongestCommonSubsequence:\n");
    std::string str1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    std::string str2 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    LongestCommonSubsequence(str1, str2);
    
    // Test for OptimalBinarySearchTree
    printf("Test OptimalBinarySearchTree:\n");
    int node_num = 5;
    double p_array[] = {0.15, 0.1, 0.05, 0.1, 0.2};
    double q_array[] = {0.05, 0.1, 0.05, 0.05, 0.05, 0.1};
    std::vector<double> p(p_array, p_array + 5);
    std::vector<double> q(q_array, q_array + 6);
    std::vector<std::vector<double> > expectation(node_num + 1, std::vector<double>(node_num + 1, INT_MAX));
    std::vector<std::vector<int> > root(node_num + 1, std::vector<int>(node_num + 1));
    OptimalBinarySearchTree(node_num, p, q, root, expectation);
    printf("%i\n", root[0][2]);
}