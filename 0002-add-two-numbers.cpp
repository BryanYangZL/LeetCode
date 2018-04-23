/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */

#include<gtest/gtest.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode *push(int val) {
        ListNode *node = new ListNode(val);
        this->next = node;
        return node;
    }
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode node(0);
        ListNode *p = &node;
        int extra = 0;
        int sum = 0;

        while (extra || l1 || l2) {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            extra = sum / 10;
            p->next = new ListNode(sum % 10);

            p = p->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return node.next;
    }
};

TEST(_0002, TwoNumbers) {
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(5);
    Solution s;

    l1->push(4)->push(3);
    l2->push(6)->push(4);

    ListNode *res = s.addTwoNumbers(l1, l2);
    ASSERT_TRUE(res->val == 7 && res->next->val == 0 && res->next->next->val == 8);
}