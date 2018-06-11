/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations
 in candidates where the candidate numbers sums to target. Each number in candidates may only be used once in the combination.

Note:
        All numbers (including target) will be positive integers.
        The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
        A solution set is:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
        A solution set is:
[
[1,2,2],
[5]
]
*/
#include <utils.h>

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> res;
        vector<int> tmp;

        sort(num.begin(), num.end());
        combination(res, 0, target, tmp, num);

        return res;
    }

private:
    void combination(vector<vector<int>> &res, const int order, const int target, vector<int> &tmp,
                     const vector<int> &num) {
        if (target == 0) {
            res.push_back(tmp);
            return;
        }

        for (int i = order; i < num.size(); i++) {
            if (num[i] > target) break;
            if (i > order && num[i] == num[i - 1]) continue; // 当前位置相同数字只算一次,以此来去重
            tmp.push_back(num[i]);
            combination(res, i + 1, target - num[i], tmp, num);
            tmp.pop_back();
        }
    }
};

TEST(_0040, CombinationSum) {
    Solution s;

    vector<int> case0 = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> cres0 = {{1, 7},
                         {1, 2, 5},
                         {2, 6},
                         {1, 1, 6}};
    vector<vector<int>> res0 = s.combinationSum2(case0, 8);
    ASSERT_TRUE(Check::check(res0, cres0));

    vector<int> case1 = {2,5,2,1,2};
    vector<vector<int>> cres1 = {{1,2,2},{5}};
    vector<vector<int>> res1 = s.combinationSum2(case1, 5);
    ASSERT_TRUE(Check::check(res1, cres1));
}