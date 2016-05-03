#ifndef longest_common_subsequence_h
#define longest_common_subsequence_h

#include <vector>
#include <string>

// Use dynamic progarmming to compute and print out longest common subsequence of string str1, and str2.
void LongestCommonSubsequence(const std::string & str1, const std::string & str2);
// Helper function to print longest subsequence.
void PrintLongestSubsequence(const std::string & str1, const std::vector<std::vector<char> > & directions, int length1, int length2);

#endif