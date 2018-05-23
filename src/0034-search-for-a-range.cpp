/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
#include <utils.h>

// 使用二分查找法查找最左边的索引
// 然后再从找到的target左边索引至数组的最右边找target的最右边的索引
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.size() == 0) return vector<int> {-1, -1};

        int l = search_left(nums, target, 0, nums.size() - 1);
        int r = (l == -1) ? -1 : search_right(nums, target, l, nums.size() - 1);

        return vector<int>{l, r};
    }

private:
    int search_left(vector<int> &nums, int target, int l, int r) {
        int mid;

        while (l <= r) { // 查找左边
            mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (l >= nums.size() || nums[l] != target) return -1;

        return l;
    }

    int search_right(vector<int> &nums, int target, int l, int r) {
        int mid;

        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return r;
    }
};

TEST(_0034, SearchRange) {
    Solution s;

    vector<int> case0 = {5, 7, 7, 8, 8, 10};
    vector<int> cres0 = {3, 4};
    int target0 = 8;
    vector<int> res0 = s.searchRange(case0, target0);
    ASSERT_TRUE(Check::check_with_order(res0, cres0));

    vector<int> case1 = {5, 7, 7, 8, 8, 10};
    vector<int> cres1 = {-1, -1};
    int target1 = 6;
    vector<int> res1 = s.searchRange(case1, target1);
    ASSERT_TRUE(Check::check_with_order(res1, cres1));

    vector<int> case2 = {-1};
    vector<int> cres2 = {-1, -1};
    int target2 = 0;
    vector<int> res2 = s.searchRange(case2, target2);
    ASSERT_TRUE(Check::check_with_order(res2, cres2));
}