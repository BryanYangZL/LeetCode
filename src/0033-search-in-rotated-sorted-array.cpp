/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/
#include <utils.h>

// 使用二分法能达到 O(log n)的复杂度,问题在于如何在翻转后的有序序列中判断target的位置
// 画图分析,可以通过nums[l],mid,target三个的值判断定是处于二分法的左边还是右边
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1, mid;

        while (l <= r) {
            mid = (r + l) / 2;  // 改成(r+l)>>1可以提高在平台上的执行效率,编译器没有对/2进行优化
            if (nums[mid] == target) return mid;

            if (target >= nums[l]) {
                if (nums[mid] >= nums[l] && nums[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if (nums[mid] < nums[l] && nums[mid] > target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }

        return -1;
    }
};

TEST(_0033, Search) {
    Solution s;

    vector<int> case0 = {4, 5, 6, 7, 0, 1, 2};
    ASSERT_EQ(s.search(case0, 0), 4);

    vector<int> case1 = {4, 5, 6, 7, 0, 1, 2};
    ASSERT_EQ(s.search(case1, 3), -1);

    vector<int> case2 = {1, 3};
    ASSERT_EQ(s.search(case2, 3), 1);
}