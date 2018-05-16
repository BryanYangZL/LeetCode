/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
*/
#include <utils.h>

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        const string table[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // 比map更高效
        if (digits.size() == 0) {
            return res;
        }

        res.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            int num = digits[i] - '0';
            if (num < 2 || num > 9) return res;
            const string &candidate = table[num];

            vector<string> tmp;
            for (int j = 0; j < res.size(); j++) {
                for (int k = 0; k < candidate.size(); k++) {
                    tmp.push_back(res[j] + candidate[k]);
                }
            }
            // 交换到结果;tmp在该次循环后会被析构。会消耗额外的内存
            // 如果不使用额外内存,需要事先计算好空间,然后增加特别的条件判断
            // 另一种方法是使用递归的方法,但是存在递归层次不确定的问题
            res.swap(tmp);
        }

        return res;
    }
};

TEST(_0017, LetterCombinations) {
    Solution s;
    string digits = "23";
    vector<string> combinations = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    vector<string> res = s.letterCombinations(digits);

    ASSERT_TRUE(Check::check(res, combinations));
}