/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */
#include <utils.h>

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
    List l1 = {2, 4, 3};
    List l2 = {5, 6, 4};
    List cres = {7, 0, 8};
    Solution s;

    ListNode *res = s.addTwoNumbers(l1.head, l2.head);
    ASSERT_TRUE(Check::check(res, cres.head));
}