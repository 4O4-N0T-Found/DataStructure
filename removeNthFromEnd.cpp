// 删除链表的倒数第N个节点，leetcode 19题
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *zero = new ListNode(0);
    zero->next = head;
    ListNode *pre = zero, *p = head, *target, *res;
    int gap = 0;
    while(p != NULL) {
        if(gap < n) {
            p = p->next;
            gap++;
        }
        else {
            p = p->next;
            pre = pre->next;
        }
    }
    target = pre->next;
    pre->next = target->next;
    //delete(target);
    res = zero->next;
    delete(zero);
    return res;
}

void print(ListNode* head) {
    while(head != NULL) {
        cout << head->val << '\t';
        head = head->next;
    }
    cout << '\n';
}

int main() {
    ListNode *head = new ListNode(5);
    ListNode *p = head;
    for(int i=4; i>0; i--) {
        ListNode *temp = new ListNode(i);
        temp->next = NULL;
        p->next = temp;
        p = temp;
    }
    p->next = NULL;
    print(head);
    print(removeNthFromEnd(head, 2));
}