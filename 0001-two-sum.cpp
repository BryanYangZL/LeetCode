/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

        Given nums = [2, 7, 11, 15], target = 9,

        Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include <vector>
#include <unordered_map>

#include<gtest/gtest.h>

using namespace std;

// 对于有序序列可以从前后开始匹配,而对于无序序列需要排序后再使用额外空间记录原Index
// 当前使用unordered_map的hash实现,则比较简单
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res;
        unordered_map<int, int> hash;  // num:idx
        int diff;

        for (int i = 0; i < nums.size(); i++) {
            diff = target - nums[i];
            if (hash.find(diff) != hash.end()) {
                res.push_back(hash[diff]);
                res.push_back(i);
                return res;
            }
            hash[nums[i]] = i;
        }

        return res;
    }
};

TEST(_0001, TwoSum) {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution s;

    vector<int> res = s.twoSum(nums, target);
    ASSERT_TRUE(res.size() == 2 && (res[0] == 0) && (res[1] == 1));
}

