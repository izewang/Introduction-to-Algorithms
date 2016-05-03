#include "longest_common_subsequence.h"

// Use two 2-dimensional arrays to keep track of the length of common subsequences and previous step.
void LongestCommonSubsequence(const std::string & str1, const std::string & str2) {
    // Create two empty 2-d arrays
    // longest_common_subsequence_length[i][j] keep track of the lenght of longest common subsequence of
    // str1[0 : i - 1] and str2[0 : j - 1], directions[i][j] keep track of previous step.
    std::vector<std::vector<int> > longest_common_subsequence_length(str1.size() + 1, std::vector<int>(str2.size() + 1, 0));
    std::vector<std::vector<char> > directions(str1.size() + 1, std::vector<char>(str2.size() + 1));
    for (int i = 1; i <= str1.size(); ++i) {
        for (int j = 1; j <= str2.size(); ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                // extend longest common subsequence by character str1[i - 1].
                longest_common_subsequence_length[i][j] = longest_common_subsequence_length[i - 1][j - 1] + 1;
                directions[i][j] = '\\';
            }
            // otherwise longest common subsequence is the same with the one of str1[0 : i - 1]
            // and str2[0 : j - 2], or the one of str1[0 : i - 2] and str2[0 : j - 1].
            else if (longest_common_subsequence_length[i][j - 1] > longest_common_subsequence_length[i - 1][j]) {
                longest_common_subsequence_length[i][j] = longest_common_subsequence_length[i][j - 1];
                directions[i][j] = '-';
            }
            else {
                longest_common_subsequence_length[i][j] = longest_common_subsequence_length[i - 1][j];
                directions[i][j] = '|';
            }
        }
    }
    // Call helper function PrintLongestSubsequence to print result.
    PrintLongestSubsequence(str1, directions, str1.size(), str2.size());
    printf("\n");
}

void PrintLongestSubsequence(const std::string & str1, const std::vector<std::vector<char> > & directions, int length1, int length2) {
    if (length1 == 0 || length2 == 0) {
        return;
    }
    if (directions[length1][length2] == '\\') {
        // str1[length1] == str2[length2]
        PrintLongestSubsequence(str1, directions, length1 - 1, length2 - 1);
        // last character print last.
        printf("%c", str1[length1 - 1]);
    }
    else if (directions[length1][length2] == '|') {
        PrintLongestSubsequence(str1, directions, length1 - 1, length2);
    }
    else {
        PrintLongestSubsequence(str1, directions, length1, length2 - 1);
    }
}
