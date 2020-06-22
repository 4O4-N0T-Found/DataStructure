// 两两交换链表中相邻的节点，leetcode 24题。
// 1 2 3 4 -> 2 1 4 3
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* swapPairs(ListNode* head) {
    ListNode *res =new ListNode(-1);
    res->next = head;
    ListNode *pre = res, *first, *second;
    while(pre->next != NULL && pre->next->next != NULL) {
        first = pre->next;
        second = first->next;
        pre->next = second;
        first->next = second->next;
        second->next = first;
        pre = first;
    }
    return res->next;
}

void print(ListNode *p) {
    while(p != NULL) {
        cout << p->val << '\t';
        p = p->next;
    }
    cout << '\n';
}

int main() {
    ListNode *list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    print(list);
    print(swapPairs(list));
}