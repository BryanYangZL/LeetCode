/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place and use only constant extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

/*
// 求下一个字典序全排列,可以用下面的函数把字典序的全排列打出来
#include <utils.h>
void print_permutation() {
    string s = "123";
    do {
        cout << s << '\n';
    } while(next_permutation(s.begin(), s.end()));
}

TEST(_0031, PrintPermutation) {
    print_permutation();
}
 */

/*
https://www.cnblogs.com/darklights/p/5285598.html

1. 从右往左找到第一个nums[n-1]小于nums[n]的数
2. 从右往n找到第一个数nums[m]大于nums[n-1]
3. 交换nums[n-1]和nums[m]两个值,然后将nums[n-1]后面的数从小往大排列
*/
#include <utils.h>

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int l = nums.size() - 2, r = nums.size() - 1;

        while (l >= 0 && nums[l] >= nums[l + 1]) l--;

        if (l >= 0) {
            while (nums[r] <= nums[l]) r--;
            swap(nums[l], nums[r]);
        }

        sort(nums.begin() + l + 1, nums.end());   // l=-1时为全排列的最后一个,这时重新排序
    }
};

TEST(_0031, NextPermutation) {
    Solution s;

    vector<int> case0 = {1, 2, 3};
    vector<int> cres0 = {1, 3, 2};
    s.nextPermutation(case0);
    ASSERT_TRUE(Check::check_with_order(case0, cres0));

    vector<int> case1 = {3, 2, 1};
    vector<int> cres1 = {1, 2, 3};
    s.nextPermutation(case1);
    ASSERT_TRUE(Check::check_with_order(case1, cres1));

    vector<int> case2 = {1, 1, 5};
    vector<int> cres2 = {1, 5, 1};
    s.nextPermutation(case2);
    ASSERT_TRUE(Check::check_with_order(case2, cres2));
}
