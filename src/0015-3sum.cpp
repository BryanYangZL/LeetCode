/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

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
#include <utils.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());  // 先从小到大进行排序,这样方便后序去重。是否先对数组进行去重会比较方便呢?会占用过多空间?

        // 至少要3个数字,后面的两个数不需要判断.但因为nums.size()返回值为无符号数所以不能直接减2,由后面的判断进行筛除
        for (int i = 0; i < nums.size();) {
            int left = i + 1, right = nums.size() - 1;

            while (left < right) {  // 由于是有序数组,所以从两头开始遍历查找两个数等于-first
                auto sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {  // 找到相加等于为0的三个值
                    res.push_back(vector<int> {nums[i], nums[left], nums[right]});

                    // 两个后面相加的字符需要去重
                    do { left++; } while (left < right && nums[left] == nums[left - 1]);
                    do { right--; } while (right > left && nums[right] == nums[right + 1]);
                }
            }

            do { i++; } while (i < nums.size() && nums[i] == nums[i - 1]); // 开始的字符去重
        }

        return res;
    }
};


TEST(_0015, ThreeSum) {
    Solution s;

    vector<int> case0 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> cres0 = {{-1, -1, 2},
                                {-1, 0,  1}};
    vector<vector<int>> res0 = s.threeSum(case0);

    ASSERT_EQ(Check::check(res0, cres0), true);
}