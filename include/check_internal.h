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

    // 当前默认是vector<int>是己经排序好的向量
    static bool check(vector<vector<int>> &val1, vector<vector<int>> &val2) {
        int i, j, k;
        if (val1.size() != val2.size()) {
            return false;
        }

        for (i = 0; i < val1.size(); i++) {
            for (j = 0; j < val2.size(); j++) {
                if (val1[i].size() != val2[j].size()) {
                    continue;
                }

                for (k = 0; k < val2[j].size(); k++) {
                    if (val1[i][k] != val2[j][k]) {
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

    // warning: 不能检查出重复数字,暂不解决
    static bool check(vector<int> &val1, vector<int> &val2) {
        int i;

        if (val1.size() != val2.size()) return false;

        for (auto v1:val1) {
            for (i = 0; i < val2.size(); i++) {
                if (v1 == val2[i]) {
                    break;
                }
            }

            if (i == val2.size()) {
                return false;
            }
        }

        return true;
    }

    static bool check_with_order(vector<int> &val1, vector<int> &val2) {
        if (val1.size() != val2.size()) return false;

        for (int i = 0; i < val1.size(); i++) {
            if (val1[i] != val2[i]) {
                return false;
            }
        }

        return true;
    }
};

#endif //LEETCODE_CHECK_H
