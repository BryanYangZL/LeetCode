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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

    }
};

TEST(_0023, MergeKLists) {
    Solution s;
    List l0 = {1, 4, 5};
    List l1 = {1, 3, 4};
    List l2 = {2, 6};
    List cres = {1, 1, 2, 3, 4, 4, 5, 6};

    vector<ListNode *> cl = {l0.head, l1.head, l2.head};
    //ASSERT_TRUE(Check::check(s.mergeKLists(cl), cres.head));
}

