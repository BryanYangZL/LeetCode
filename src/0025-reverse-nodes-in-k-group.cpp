/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a
        multiple of k then left-out nodes in the end should remain as it is.

Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

Note:
Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
 */
#include <utils.h>

class Solution0 {  // 使用递归或者使用内存保存列表都使用了额外的空间
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || k == 1) return head;

        ListNode dummy(0);
        ListNode *cur = head, *ghead = &dummy, *tmp, *nex = head;  // ghead保存groud的header
        dummy.next = head;

        int cnt = 0; // 用于需要处理的node总数
        while (cur != nullptr) {
            cnt++;
            cur = cur->next;
        }

        while (cnt >= k) {
            cur = nex;
            nex = cur->next;

            for (int i = 1; i < k; i++) {  // 翻转kgroup
                tmp = nex->next;
                nex->next = cur;
                cur = nex;
                nex = tmp;
            }

            ghead->next->next = nex;  // 把翻转后列表链接回去,相对而言这种方法比较烦琐,不如方法1高效
            tmp = ghead->next;
            ghead->next = cur;
            ghead = tmp;

            cnt -= k;
        }

        return dummy.next;
    }
};

class Solution1 {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || k == 1) return head;

        ListNode dummy(0);
        ListNode *cur = head, *ghead = &dummy, *nex = head;
        dummy.next = head;


        int cnt = 0; // 用于需要处理的node总数
        while (cur != nullptr) {
            cnt++;
            cur = cur->next;
        }

        while (cnt >= k) {
            cur = ghead->next;
            nex = cur->next;
            for (int i = 1; i < k; ++i) {
                cur->next = nex->next; // 一直保存group第一个元素的next,直接到最后,省却链接到后面
                nex->next = ghead->next;
                ghead->next = nex;  // 一直串起来,省却链接前面元素
                nex = cur->next;
            }
            ghead = cur;
            cnt -= k;
        }
        return dummy.next;
    }
};

TEST(_0025, ReverseKGroup0) {
    Solution0 s;

    List tcase0 = {1, 2, 3, 4, 5};
    List cres0 = {2, 1, 4, 3, 5};
    int k0 = 2;
    ListNode *res0 = s.reverseKGroup(tcase0.head, k0);
    ASSERT_TRUE(Check::check(res0, cres0.head));

    List tcase1 = {1, 2, 3, 4, 5};
    List cres1 = {3, 2, 1, 4, 5};
    int k1 = 3;
    ListNode *res1 = s.reverseKGroup(tcase1.head, k1);
    ASSERT_TRUE(Check::check(res1, cres1.head));
}

TEST(_0025, ReverseKGroup1) {
    Solution1 s;

    List tcase0 = {1, 2, 3, 4, 5};
    List cres0 = {2, 1, 4, 3, 5};
    int k0 = 2;
    ListNode *res0 = s.reverseKGroup(tcase0.head, k0);
    ASSERT_TRUE(Check::check(res0, cres0.head));

    List tcase1 = {1, 2, 3, 4, 5};
    List cres1 = {3, 2, 1, 4, 5};
    int k1 = 3;
    ListNode *res1 = s.reverseKGroup(tcase1.head, k1);
    ASSERT_TRUE(Check::check(res1, cres1.head));
}