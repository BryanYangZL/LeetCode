/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together.Twelve is written as, XII, which is
simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII.
 Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same
 principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: C = 100, L = 50, XXX = 30 and III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#include <map>
#include <string>

#include<gtest/gtest.h>

using namespace std;

// 方法1: 从最高位开始不断迭代查找表中的对应值
class Solution1 {
public:
    string intToRoman(int num) {
        string result = "";
        const map<int, string> roman = {
                {1,    "I"},
                {5,    "V"},
                {10,   "X"},
                {50,   "L"},
                {100,  "C"},
                {500,  "D"},
                {1000, "M"},
                {4,    "IV"},
                {9,    "IX"},
                {40,   "XL"},
                {90,   "XC"},
                {400,  "CD"},
                {900,  "CM"},
        };

        while (num > 0) {
            // upper_bound得到key大于num的迭代器,然后用prev取这个迭代器前一个元素
            auto iter = prev(roman.upper_bound(num));
            num -= iter->first;
            result += iter->second;
        }

        return result;
    }
};

// 方法2: 由于在3999以内,所以可以将3999内全部列成表

// 方法3: 根据方法2可以作简化的表。观察原始规则可以得出十制的数的每一位可以由罗马数字单独表示出来
class Solution3 {
public:
    string intToRoman(int num) {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
    }
};


TEST(_0012, IntToRoman) {
    Solution1 s1;
    ASSERT_EQ(s1.intToRoman(3), "III");
    ASSERT_EQ(s1.intToRoman(4), "IV");
    ASSERT_EQ(s1.intToRoman(9), "IX");
    ASSERT_EQ(s1.intToRoman(58), "LVIII");
    ASSERT_EQ(s1.intToRoman(1994), "MCMXCIV");

    Solution3 s3;
    ASSERT_EQ(s3.intToRoman(3), "III");
    ASSERT_EQ(s3.intToRoman(4), "IV");
    ASSERT_EQ(s3.intToRoman(9), "IX");
    ASSERT_EQ(s3.intToRoman(58), "LVIII");
    ASSERT_EQ(s3.intToRoman(1994), "MCMXCIV");
}