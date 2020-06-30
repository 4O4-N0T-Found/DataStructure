// 降序输出一个乱序链表（无重复元素），并释放空间。
#include <iostream>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

void sortDesc(LinkList head) {
    while(head->next!=NULL) {
        LNode *pre = head, *p = head->next, *max_pre;
        int max = INT_MIN;
        while(p!=NULL) {
            if(p->data > max) {
                max = p->data;
                max_pre = pre;
            }
            pre = p;
            p = p->next;
        }
        p = max_pre->next;
        cout << p->data << '\t';
        max_pre->next = p->next;
        free(p);
    }
    free(head);
}

int main() {
    LNode *head = (LNode *)malloc(sizeof(LNode));
    LNode *A = (LNode *)malloc(sizeof(LNode));
    LNode *B = (LNode *)malloc(sizeof(LNode));
    LNode *C = (LNode *)malloc(sizeof(LNode));
    head->next = A;
    A->next = B;
    B->next = C;
    C->next = NULL;
    A->data = 500;
    B->data = 199;
    C->data = 3000;
    sort(head);
}