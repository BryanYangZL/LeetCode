/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

        The solution set must not contain duplicate quadruplets.

Example:

        Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]
*/
#include <vector>

#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int l = j + 1;
                int r = nums.size() - 1;
                int two_sum_target = target - nums[i] - nums[j];
                while (l < r) {
                    vector<int> two_sum = twoSum(nums, l, r, two_sum_target);
                    if (two_sum.size() == 2) {
                        vector<int> four_sum{nums[i], nums[j], two_sum[0], two_sum[1]};
                        if (!is_duplicate(res, four_sum)) {  // 能不能在搜索过程中就去重? 合成string通过map去重呢?
                            res.push_back(four_sum);
                        }
                    }
                    r--; // 向左移,搜索下一个符合要求的数字
                }
            }
        }

        return res;
    }

    vector<int> twoSum(vector<int> &nums, int &l, int &r, int target) {
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum < target) {
                l++;
            } else if (sum > target) {
                r--;
            } else {
                return vector<int>{nums[l], nums[r]};
            }
        }

        return vector<int>{};
    }

    inline bool is_duplicate(vector<vector<int>> &res, vector<int> &four_sum) {
        for (int k = 0; k < res.size(); k++) {
            if (res[k][0] == four_sum[0] && res[k][1] == four_sum[1] &&
                res[k][2] == four_sum[2] && res[k][3] == four_sum[3]) {
                return true;
            }
        }

        return false;
    }
};

bool check(vector<vector<int>> val1, vector<vector<int>> val2) {
    int i, j, k;
    if (val1.size() != val2.size()) {
        return false;
    }

    for (i = 0; i < val1.size(); i++) {
        for (j = 0; j < val2.size(); j++) {
            for (k = 0; k < val2[j].size(); k++) {
                if (val1[i][k] != val2[j][k]) { // 因为己经是排序好的,所以依次比较就行
                    break;
                }
            }

            if (k == val2[j].size()) {
                break;
            }
        }

        if (j == val2.size()) {
            return false;
        }
    }

    return true;
}

TEST(_0018, FourSum) {
    Solution s;

    vector<int> case0 = {1, 0, -1, 0, -2, 2};
    int target0 = 0;
    vector<vector<int>> res0 = {{-1, 0,  0, 1},
                                {-2, -1, 1, 2},
                                {-2, 0,  0, 2}};
    ASSERT_TRUE(check(s.fourSum(case0, target0), res0));
}

