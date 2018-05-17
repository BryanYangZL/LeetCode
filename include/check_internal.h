#ifndef LEETCODE_CHECK_H
#define LEETCODE_CHECK_H

#include <utils.h>

class Check {
public:
    // 检查两个list是否相等
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

    static bool check(vector<string> &val1, vector<string> &val2) {
        int i, j;

        if (val1.size() != val2.size()) {
            return false;
        }

        for (i = 0; i < val1.size(); i++) {
            for (j = 0; j < val2.size(); j++) {
                if (val1[i] == val2[j]) {
                    break;
                }
            }

            if (j == val2.size()) {
                return false;
            }
        }

        return true;
    }

    static bool check(vector<vector<int>> &val1, vector<vector<int>> &val2) {
        int i, j, k;
        if (val1.size() != val2.size()) {
            return false;
        }

        for (i = 0; i < val1.size(); i++) {
            for (j = 0; j < val2.size(); j++) {
                if (val1[i].size() != val2[j].size()) {
                    break;
                }

                for (k = 0; k < val2[j].size(); k++) {
                    if (val1[i][k] != val2[j][k]) { // 因为己经是排序好的,所以依次比较就行
                        break;
                    }
                }

                if (k == val2[j].size()) {
                    break;
                }
            }

            if (j == val2.size()) {
                return false;
            }
        }

        return true;
    }
};

#endif //LEETCODE_CHECK_H
