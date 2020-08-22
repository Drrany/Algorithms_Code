#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *dummyHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    struct ListNode *p = dummyHead;
    int count = 0;

    while (p1 || p2)
    {
        int m1 = p1 ? p1->val : 0;
        int m2 = p2 ? p2->val : 0;
        struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
        q->next = NULL;

        int sum = (m1) + (m2) + count;
        q->val = sum % 10;
        count = sum / 10;

        if(p1)
            p1 = p1->next;
        if(p2)
            p2 = p2->next;
        p->next = q;
        p = q;
        
    }

    if (count)
    {
        struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
        q->val = count;
        q->next = NULL;
        p->next = q;
    }

    return dummyHead->next;
}

int main()
{
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->val = 2;
    l2->val = 5;
    struct ListNode *p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    p1->val = 4;
    p2->val = 6;
    p1->next = NULL;
    p2->next = NULL;
    l1->next = p1;
    l2->next = p2;
    l3 = addTwoNumbers(l1, l2);
    return 0;
}