/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
*/
#include <utils.h>

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> table = {{'}', '{'},  // 用hashmap会快一些,更快的应该是直接用数组进行映射
                                 {')', '('},
                                 {']', '['}};

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '{' || c == '(' || c == '[') {
                st.push(c);
            } else {
                if (st.empty() || table[c] != st.top()) {
                    return false;
                }
                st.pop();
            }
        }

        if (!st.empty()) {
            return false;
        }

        return true;
    }
};

TEST(_0020, IsValid) {
    Solution s;

    ASSERT_TRUE(s.isValid("()"));
    ASSERT_TRUE(s.isValid("()[]{}"));
    ASSERT_FALSE(s.isValid("(]"));
    ASSERT_FALSE(s.isValid("([)]"));
    ASSERT_TRUE(s.isValid("{[]}"));
}