#include "optimal_binary_search_tree.h"

void OptimalBinarySearchTree(int node_num,
                             const std::vector<double> & p,
                             const std::vector<double> & q,
                             std::vector<std::vector<int> > & root,
                             std::vector<std::vector<double> > & expectation) {
    std::vector<std::vector<double> > sum_of_probability(node_num + 1, std::vector<double>(node_num + 1));
    for (int i = 0; i <= node_num; ++i) {
        expectation[i][i] = q[i];
        sum_of_probability[i][i] = q[i];
    }
    for (int l = 0; l < node_num; ++l) {
        for (int i = 0; i < node_num - l; ++i) {
            int j = i + l + 1;
            sum_of_probability[i][j] = sum_of_probability[i][j - 1] + p[j - 1] + q[j];
            for (int r = i; r < j; ++r) {
                double tmp = expectation[i][r] + expectation[r + 1][j] + sum_of_probability[i][j];
                if (tmp < expectation[i][j]) {
                    expectation[i][j] = tmp;
                    root[i][j] = r;
                }
            }
        }
    }
}
