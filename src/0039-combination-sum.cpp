/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
        find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.

Note:
        All numbers (including target) will be positive integers.
        The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
        A solution set is:
[
[7],
[2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
        A solution set is:
[
[2,2,2,2],
[2,3,3],
[3,5]
]
*/
#include <utils.h>

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());  // 方便后续及时退出不必要的循环
        vector<vector<int>> res;
        vector<int> tmp;

        backtracking(0, candidates, target, tmp, res);

        return res;
    }

private:
    void backtracking(int start, vector<int> &candidates, int target, vector<int> &tmp, vector<vector<int>> &res) {
        if (!target) {
            res.push_back(tmp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (target < candidates[i]) {
                break;
            }

            tmp.push_back(candidates[i]);
            backtracking(i, candidates, target - candidates[i], tmp, res);
            tmp.pop_back();
        }
    }
};

TEST(_0039, CombinationSum) {
    Solution s;
    vector<int> case0 = {2, 3, 6, 7};
    vector<vector<int>> cres0 = {{7},
                                 {2, 2, 3}};
    vector<vector<int>> res0 = s.combinationSum(case0, 7);
    ASSERT_TRUE(Check::check(res0, cres0));
}
