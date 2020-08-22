#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode*p1Head=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode*p2Head=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode*p1=p1Head;
    struct ListNode*p2=p2Head;
    struct ListNode*p=head;

    while(p){
        if(p->val<x){
            p1->next=p;
            p1=p;
        }
        else{
            p2->next=p;
            p2=p;
        }
        p=p->next;
    }

    p2->next=NULL;
    p1->next=p2Head->next;
    return p1Head->next;

}

int main()
{
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p2 = (struct ListNode *)malloc(sizeof(struct ListNode));

    l1->val = 2;
    l1->next = l2;
    l2->val = 2;
    p1->val = 4;
    p2->val = 6;
    l2->next = p1;
    p1->next = p2;
    p2->next = NULL;

    struct ListNode *l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l3 = partition(l1,3);
    return 0;
}