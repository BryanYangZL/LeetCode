/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
*/
#include <vector>
#include <string>

#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }

private:
    void addingpar(vector<string> &v, string str, int n, int m) {
        if (n == 0 && m == 0) {
            v.push_back(str);
            return;
        }
        if (m > 0) { addingpar(v, str + ")", n, m - 1); }
        if (n > 0) { addingpar(v, str + "(", n - 1, m + 1); }
    }
};

static bool check(vector<string> val0, vector<string> val1) {
    int i, j;

    for (i = 0; i < val0.size(); i++) {
        for (j = 0; j < val1.size(); j++) {
            if (val0[i] == val1[j]) {
                break;
            }
        }

        if (j == val1.size()) {
            return false;
        }
    }

    return true;
}

TEST(_0022, GenerateParenthesis) {
    Solution s;
    vector<string> cres = {
            "((()))",
            "(()())",
            "(())()",
            "()(())",
            "()()()"
    };

    ASSERT_TRUE(check(cres, s.generateParenthesis(3)));
}