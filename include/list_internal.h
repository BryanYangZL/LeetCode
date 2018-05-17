#ifndef LEETCODE_LIST_H
#define LEETCODE_LIST_H

#include <utils.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class List {
public:

    ListNode *head = NULL;

    List() : head(NULL) {}

    List(const initializer_list<int> data) : List() {
        for (auto d : data) {
            ListNode *node = new ListNode(d);
            this->AddNode(node);
        }
    }

private:
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
};

#endif //LEETCODE_LIST_H
