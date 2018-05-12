/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:
    All given inputs are in lowercase letters a-z.
*/

#include <string>

#include<gtest/gtest.h>

using namespace std;

// 方法1: 将第一个字符串依次与后同的进行比较,每次仅比较上次相同的最短字符串长度
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() <= 0) {
            return "";
        }

        // 可以优化成取最短字符串长度为minL
        unsigned long minL = strs[0].size(); // 肯定不会超过其中任意字符串的长度
        vector<string>::const_iterator it = strs.begin();
        for (it++; it != strs.end(); it++) {
            minL = min(minL, (*it).size());
            for (unsigned long i = 0; i < minL; i++) {
                if ((*it)[i] != strs[0][i]) {
                    minL = i;
                    break;
                }
            }
        }

        return strs[0].substr(0, minL);
    }
};

TEST(_0014, LongestCommonPrefix) {
    Solution s;

    vector<string> strs0 = {"flower", "flow", "flight"};
    ASSERT_EQ(s.longestCommonPrefix(strs0), "fl");

    vector<string> strs1 = {"dog", "racecar", "car"};
    ASSERT_EQ(s.longestCommonPrefix(strs1), "");

    vector<string> strs2 = {"aa", "ab"};
    ASSERT_EQ(s.longestCommonPrefix(strs2), "a");
}