/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/
#include <utils.h>

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // 先构造优先级队列,取每个list的第一个元素存在队列中。
        auto cmp = [](ListNode *a, ListNode *b) {
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);

        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }

        // 然后依次取出队列中的最小元素,当被取出的元素的list取该List的下一个元素入优先级队列
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while (!pq.empty()) {
            cur->next = pq.top();
            pq.pop();
            if (cur->next->next) pq.push(cur->next->next);
            cur = cur->next;
        }

        return dummy.next;
    }
};

TEST(_0023, MergeKLists) {
    Solution s;
    List l0 = {1, 4, 5};
    List l1 = {1, 3, 4};
    List l2 = {2, 6};
    List cres = {1, 1, 2, 3, 4, 4, 5, 6};

    vector<ListNode *> cl = {l0.head, l1.head, l2.head};
    ListNode *res = s.mergeKLists(cl);
    ASSERT_TRUE(Check::check(res, cres.head));
}

