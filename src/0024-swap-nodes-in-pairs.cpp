/*
Given a linked list, swap every two adjacent nodes and return its head.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.

Note:
Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
 */
#include <utils.h>

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode dummy(0);
        ListNode *cur = &dummy, *first = head, *second = head->next;

        while (1) {
            first->next = second->next;  // 交换两个node
            second->next = first;
            cur->next = second;
            cur = cur->next->next; // 将当前指针指向原第二个node的下一个元素

            if (cur->next == nullptr || cur->next->next == nullptr) {
                break;
            }

            first = cur->next;
            second = cur->next->next;
        }

        return dummy.next;
    }
};

TEST(_0024, SwapPairs) {
    Solution s;
    List tcase = {1, 2, 3, 4};
    List cres = {2, 1, 4, 3};

    ListNode *res = s.swapPairs(tcase.head);
    ASSERT_TRUE(Check::check(res, cres.head));
}