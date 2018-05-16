/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

        Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

        Given n will always be valid.
*/
#include <utils.h>

// 利用双指针p0,p1,p1=p0+n,这样当p1到达尾部时p0就是指向倒数第Nth个
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p0 = head, *p1 = head;

        for (int i = 0; i < n; i++) {
            p1 = p1->next;
        }

        if (p1 == NULL) {
            return head->next;
        }

        while (p1->next != NULL) {
            p0 = p0->next;
            p1 = p1->next;
        }

        p0->next = p0->next->next;

        return head;
    }
};

// 网站上讨论的算法更简捷,保存的是next指针
class Solution1 {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode **t1 = &head, *t2 = head;
        for (int i = 0; i < n; ++i) {
            t2 = t2->next;
        }
        while (t2 != NULL) {
            t1 = &((*t1)->next);
            t2 = t2->next;
        }
        *t1 = (*t1)->next;
        return head;
    }
};

TEST(_0019, RemoveNthFromEnd) {
    Solution s;

    List case0 = {1, 2, 3, 4, 5};
    List cres0 = {1, 2, 3, 4};
    auto res0 = s.removeNthFromEnd(case0.head, 1);  // 最后一个
    ASSERT_TRUE(Check::check(cres0.head, res0));

    List case1 = {1, 2, 3, 4, 5};
    List cres1 = {1, 2, 3, 5};
    auto res1 = s.removeNthFromEnd(case1.head, 2);
    ASSERT_TRUE(Check::check(cres1.head, res1));

    List case2 = {1, 2, 3, 4, 5};
    List cres2 = {2, 3, 4, 5};
    auto res2 = s.removeNthFromEnd(case2.head, 5); // 第一个
    ASSERT_TRUE(Check::check(cres2.head, res2));

    List case3 = {1};
    List cres3 = {};
    auto res3 = s.removeNthFromEnd(case3.head, 1);  // 仅一个元素的列表
    ASSERT_TRUE(Check::check(cres3.head, res3));

    Solution1 s1;
    List case4 = {1, 2, 3, 4, 5};
    List cres4 = {1, 2, 3, 5};
    auto res4 = s.removeNthFromEnd(case4.head, 2);
    ASSERT_TRUE(Check::check(cres4.head, res4));
}