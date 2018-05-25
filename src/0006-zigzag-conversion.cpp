/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display
this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
*/
#include <utils.h>

// 把一个锯齿当做一个块
class Solution {
public:
    string convert(string s, int nRows) {
        if (s.size() < 2) return s;

        string res = "";
        int stride = nRows + nRows - 2;
        for (int i = 0; i < nRows; i++) {
            for (int j = i; j < s.size(); j += stride) {
                res += s[j];

                // 除了前后两排有一个元素,其它排都有二个元素
                if (i != 0 && i != (nRows - 1)) {
                    int idx = j + nRows - i + nRows - i - 2; // 计算同一块内同一排第二个元素的坐标
                    if (idx < s.size()) {
                        res += s[idx];
                    }
                }
            }
        }

        return res;
    }
};

TEST(_0006, Convert) {
    Solution s;

    ASSERT_EQ(s.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
}