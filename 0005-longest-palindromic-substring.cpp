/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
 */

#include<gtest/gtest.h>

using namespace std;

/*
 *  回文字符串为中心对称,所以以每个位置为中心遍历一次.注意需要考虑"aba"和"abba"两种情况
 */
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;

        for (int i = 0; i < s.size() - 1; i++) {
            expand(s, i, i);
            expand(s, i, i+1);
        }

        return s.substr(_left, _right - _left + 1);
    }

private:
    inline void expand(string &s, int left, int right)
    {
        while(left >= 0 && right <= s.size()) {
            if (s[left] != s[right]) {
                break;
            }

            if ((right - left + 1) > _max) {
                _max = right - left + 1;
                _right = right;
                _left = left;
            }

            left--; right++;
        }
    }

    int _max = 0;
    int _left = 0;
    int _right = 0;
};

TEST(_0005, LongestPalindrome)
{
    Solution s1;
    Solution s2;

    ASSERT_EQ(s1.longestPalindrome("cbbd"), "bb");
    ASSERT_EQ(s2.longestPalindrome("babad"), "bab");
}
