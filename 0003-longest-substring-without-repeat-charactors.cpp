/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <vector>
#include <string>

#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = -1;
        vector<int> idx(256, -1);
        int max_len = 0;

        for (int i = 0; i < s.size(); i++) {
            if (idx[s[i]] > start) {
                start = idx[s[i]];
            }

            idx[s[i]] = i;
            max_len = max(max_len, i - start);
        }

        return max_len;
    }
};

TEST(_0003, LongestSubstring) {
    Solution s;

    ASSERT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
    ASSERT_EQ(s.lengthOfLongestSubstring("bbbbb"), 1);
    ASSERT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);
    ASSERT_EQ(s.lengthOfLongestSubstring("c"), 1);
}

