/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

#include<gtest/gtest.h>

class Solution {
public:
    bool isPalindrome(int x) {
        int palindrome = 0;
        int rev = x;

        if (x < 0) return false;

        while (rev > 0) {
            palindrome = palindrome * 10 + rev % 10;
            rev /= 10;
        }

        return palindrome == x;
    }
};

TEST(_0009, PalindromeNumer) {
    Solution s;

    ASSERT_EQ(s.isPalindrome(121), true);
    ASSERT_EQ(s.isPalindrome(-121), false);
    ASSERT_EQ(s.isPalindrome(10), false);
}

