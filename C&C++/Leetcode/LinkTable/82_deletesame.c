#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    struct ListNode *pre = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *cur = head;
    pre->next = head;
    dummy=pre;

    while (cur && cur->next)
    {
        int tmp = cur->val;
        if (tmp == cur->next->val)
        {
            while(cur->next&&tmp==cur->next->val){
                struct ListNode *q=cur;
                cur = cur->next;
                free(q);
            }
                
            pre->next=cur->next;
            cur=cur->next;        
        }
        else{
            pre=cur;
            cur=cur->next;
        }      
    }
    return dummy->next;
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
    l3 = deleteDuplicates(l1);
    return 0;
}