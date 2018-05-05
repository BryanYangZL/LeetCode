/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
 */

#include <vector>

#include<gtest/gtest.h>

using namespace std;

// 从两边开始搜索,如果要比之前的容量大,则必须比两边的一边要高,所以前短边往中间移动
class Solution {
public:
    int maxArea(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            max_area = max(max_area, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};

// 穷举法作参照组
class SolutionN2 {
public:
    int maxArea(vector<int> &height) {
        int max_area = 0;

        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                max_area = max(max_area, (j - i) * min(height[i], height[j]));
            }
        }

        return max_area;
    }
};

TEST(_0011, MaxArea) {
    Solution s;
    SolutionN2 sc;

    vector<int> case01 = {3, 24, 29, 6};
    ASSERT_EQ(s.maxArea(case01), sc.maxArea(case01));

    vector<int> case02 = {5, 4, 9, 7};
    ASSERT_EQ(s.maxArea(case02), sc.maxArea(case02));
}