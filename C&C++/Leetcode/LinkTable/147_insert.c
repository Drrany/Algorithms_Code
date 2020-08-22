#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};


struct ListNode* insertionSortList(struct ListNode* head){
    if(!head||!head->next)
        return head;

    struct ListNode*pHead=(struct ListNode *)malloc(sizeof(struct ListNode));
    pHead->next=head;
    struct ListNode*p=head->next;
    //struct ListNode*pre=head; //可以直接使用head
    while(p){
        if(p->val<head->val){
            struct ListNode*q=pHead;
            while(q!=p && q->next->val<p->val)
                q=q->next;
            
            struct ListNode*tmp=p->next;
            p->next=q->next;
            q->next=p;
            p=tmp;
            head->next=p;
        }
        else {
            head=p;
            p=p->next;
        }
    }
    return pHead->next;

}