/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

        Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include <vector>
#include <limits>

#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int closest = 0;
        int min_diff = INT_MAX;  // 用于记录最小的差值
        int left, right;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {   // 从有序序列的两头开始接近的值
                auto sum = nums[i] + nums[left] + nums[right];
                auto diff = abs(sum - target);
                if (diff < min_diff) {
                    closest = sum;
                    min_diff = diff;
                }

                if (sum > target) {
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    return target; // 相等直接退出,跳过不必要的计算;而搜索过程中大于小于target的变化规律不确定,不能跳过
                }
            }
        }

        return closest;
    }
};

TEST(_0016, ThreeSumClosest) {
    Solution s;
    vector<int> case0 = {-1, 2, 1, -4};

    ASSERT_EQ(s.threeSumClosest(case0, 1), 2);
}