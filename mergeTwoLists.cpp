// 两个升序链表合并为一个升序链表，leetcode 21题
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *res = new ListNode(-1), *tail = res;;
    while(l1 != NULL && l2 != NULL) {
        if(l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if(l1 != NULL) {
        tail->next = l1;
    }
    else if(l2 != NULL) {
        tail->next = l2;
    }
    return res->next;
}

void print(ListNode *l) {
    while(l) {
        cout << l->val << '\t';
        l = l->next;
    }
    cout << '\n';
}

int main() {
    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    print(l1);
    print(l2);
    ListNode *l3 = mergeTwoLists(l1, l2);
    print(l3);
}
