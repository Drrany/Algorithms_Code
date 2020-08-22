#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

int add(struct ListNode *l1, struct ListNode *l2){
    if(!l1&&!l2)
        return 0;
    int sum=l1->val+l2->val+add(l1->next,l2->next);
    if(sum>9){
        l1->val=sum%10;
        return 1;
    }
    else{
        l1->val=sum;
        return 0;
    }
}


struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    int len1 = 0;
    int len2 = 0;
    while (p1)
    {
        len1++;
        p1 = p1->next;
    }
    while (p2)
    {
        len2++;
        p2 = p2->next;
    }
    if(len2<len1){
        while(len2<len1){
            struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
             tmp->val=0;
             tmp->next=l2;
             l2=tmp;
             len2++;
        }
    }
    else if(len1<len2){
        while(len1<len2){
            struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
             tmp->val=0;
             tmp->next=l1;
             l1=tmp;
             len1++;
        }
    }
    int co=add(l1,l2);
    if(co){
        struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp->val=1;
        tmp->next=l1;
        l1=tmp;
    }
    return l1;
}