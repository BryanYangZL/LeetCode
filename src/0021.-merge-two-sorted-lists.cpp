/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together
the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
 */
#include<gtest/gtest.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

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

TEST(_0021, MergeTwoLists) {
    Solution s;
    List l1 = {1, 2, 4};
    List l2 = {1, 3, 4};
    List cres = {1, 1, 2, 3, 4, 4};
    ListNode *res = s.mergeTwoLists(l1.head, l2.head);
    ASSERT_TRUE(check(cres.head, res));
}