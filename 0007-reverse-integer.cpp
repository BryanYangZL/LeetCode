/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer
 range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the
 reversed integer overflows.
 */

#include<gtest/gtest.h>

class Solution {
public:
    int reverse(int x) {
        long long res = 0;

        while (x != 0) {
            res = 10 * res + x % 10;
            x /= 10;
        }

        if (res > INT_MAX || res < INT_MIN) {
            return 0;
        }

        return res;
    }
};

TEST(_0007, ReverseInteger) {
    Solution s;

    ASSERT_EQ(s.reverse(123), 321);
    ASSERT_EQ(s.reverse(-123), -321);
    ASSERT_EQ(s.reverse(120), 21);
}