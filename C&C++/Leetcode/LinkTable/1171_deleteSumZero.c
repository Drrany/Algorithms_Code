#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* removeZeroSumSublists(struct ListNode* head){
    if(!head)
        return head;
    struct ListNode *pre = (struct ListNode *)malloc(sizeof(struct ListNode));
    pre->next = head;
    struct ListNode *p = pre;

    while(p){
        int sum = 0;
        struct ListNode *q = p->next;
        while(q){
            sum += q->val;
            if(sum==0)
                p->next = q->next;
            q = q->next;
        }
        p = p->next;
    }

    return pre->next;
}