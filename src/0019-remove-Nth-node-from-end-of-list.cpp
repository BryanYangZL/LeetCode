/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

        Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

        Given n will always be valid.
*/
#include<gtest/gtest.h>

using namespace std;

struct ListNode { // 单链表要遍历到最后一个才能知道哪个是倒数Nth
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

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

class List {
public:
    List() : head(NULL) {}

    List(const initializer_list<int> data) : List() {
        for (auto d : data) {
            ListNode *node = new ListNode(d);
            this->AddNode(node);
        }
    }

    List &AddNode(ListNode *node) {
        ListNode *p = head;

        if (head == NULL) {
            head = node;
            return *this;
        }

        while (p->next != NULL) {
            p = p->next;
        }

        p->next = node;

        return *this;
    }

    ListNode *head = NULL;
};

static bool check(ListNode *head0, ListNode *head1) {
    while (head0 != NULL && head1 != NULL) {
        if (head0->val != head1->val) {
            return false;
        }
        head0 = head0->next;
        head1 = head1->next;
    }

    return head0 == NULL && head1 == NULL;
}

TEST(_0019, RemoveNthFromEnd) {
    Solution s;

    List case0 = {1, 2, 3, 4, 5};
    List cres0 = {1, 2, 3, 4};
    auto res0 = s.removeNthFromEnd(case0.head, 1);  // 最后一个
    ASSERT_TRUE(check(cres0.head, res0));

    List case1 = {1, 2, 3, 4, 5};
    List cres1 = {1, 2, 3, 5};
    auto res1 = s.removeNthFromEnd(case1.head, 2);
    ASSERT_TRUE(check(cres1.head, res1));

    List case2 = {1, 2, 3, 4, 5};
    List cres2 = {2, 3, 4, 5};
    auto res2 = s.removeNthFromEnd(case2.head, 5); // 第一个
    ASSERT_TRUE(check(cres2.head, res2));

    List case3 = {1};
    List cres3 = {};
    auto res3 = s.removeNthFromEnd(case3.head, 1);  // 仅一个元素的列表
    ASSERT_TRUE(check(cres3.head, res3));

    Solution1 s1;
    List case4 = {1, 2, 3, 4, 5};
    List cres4 = {1, 2, 3, 5};
    auto res4 = s.removeNthFromEnd(case4.head, 2);
    ASSERT_TRUE(check(cres4.head, res4));
}