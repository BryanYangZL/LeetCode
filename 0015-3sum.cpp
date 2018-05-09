/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

        The solution set must not contain duplicate triplets.

Example:

        Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]
*/

#include <vector>

#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
    }
};

static bool check(vector<vector<int>> &v1, vector<vector<int>> &v2) {
    int i, j;

    if (v1.size() != v2.size()) {
        return false;
    }

    for (i = 0; i < v1.size(); i++) {
        for (j = 0; j < v2.size(); j++) {

        }

        if (j == v2.size()) {
            return false;
        }
    }

    return true;
}

TEST(_0015, ThreeSum) {
    Solution s;

    vector<int> case0 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res0 = {{-1, 0,  1},
                                {-1, -1, 2}};
    vector<vector<int>> res0_ = s.threeSum(case0);

    ASSERT_EQ(check(res0, res0_), true);
}