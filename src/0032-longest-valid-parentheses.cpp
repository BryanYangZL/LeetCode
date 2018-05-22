/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed)
parentheses substring.

Example 1:
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/
#include <utils.h>

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> parentheses;  // stack用于记录(符号的index
        int max_cnt = 0, cnt = 0;

        parentheses.push(-1); // 方便往前索引一位时使用
        for (int i = 0; i < s.size(); i++) {
            int n = parentheses.top();
            if (n != -1 && s[i] == ')' && s[n] == '(') {  // 从后往前匹配
                parentheses.pop();
                max_cnt = max(max_cnt, i - parentheses.top());
            } else {
                parentheses.push(i);
            }
        }

        max_cnt = max(max_cnt, cnt);

        return max_cnt;
    }
};

TEST(_0032, LongestValidParentheses) {
    Solution s;

    ASSERT_EQ(s.longestValidParentheses("(()"), 2);
    ASSERT_EQ(s.longestValidParentheses(")()())"), 4);
    ASSERT_EQ(s.longestValidParentheses("()(()"), 2);
}