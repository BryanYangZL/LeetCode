/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together
the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
 */
#include <utils.h>

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode tmp(0);
        ListNode *head = &tmp;

        while (l1 && l2) {
            if (l1->val > l2->val) {
                head->next = l2;
                l2 = l2->next;
            } else {
                head->next = l1;
                l1 = l1->next;
            }

            head = head->next;
        }

        head->next = l1 ? l1 : l2;

        return tmp.next;
    }
};

TEST(_0021, MergeTwoLists) {
    Solution s;
    List l1 = {1, 2, 4};
    List l2 = {1, 3, 4};
    List cres = {1, 1, 2, 3, 4, 4};
    ListNode *res = s.mergeTwoLists(l1.head, l2.head);
    ASSERT_TRUE(Check::check(cres.head, res));
}