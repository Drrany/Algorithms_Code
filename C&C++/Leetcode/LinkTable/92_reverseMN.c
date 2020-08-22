#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseBetween(struct ListNode *head, int m, int n)
{
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->next = head;
    struct ListNode *mnHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    mnHead->next = NULL;
    int k=m;

    while (p && m > 1)
    {
        p = p->next;
        m--;
        n--;
    }
    struct ListNode *mp = p;
    p = p->next;
    int flag = 0;
    struct ListNode *np = (struct ListNode *)malloc(sizeof(struct ListNode));
    while (p && n > 0)
    {
        n--;
        struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
        q->val = p->val;
        q->next = mnHead->next;
        mnHead->next = q;
        p = p->next;
        if (!flag)
        {
            np = mnHead->next;
            flag = 1;
        }
    }
    np->next = p;
    mp->next = mnHead->next;
    if(k==1)    return mp->next;
    else  return head;
}

struct ListNode *reverseBetween2(struct ListNode *head, int m, int n)
{
    struct ListNode *pHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    pHead->next=head;
    struct ListNode *pre = pHead;

    while (pre && m > 1)
    {
        pre = pre->next;
        m--;
        n--;
    }

    struct ListNode *np = pre->next;
    
    while (pre && n > 1)
    {
        n--;
        struct ListNode *tmp=np->next;
        np->next=np->next->next;
        tmp->next=pre->next;
        pre->next=tmp;
    }

    return pHead->next;
}

int main()
{
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p2 = (struct ListNode *)malloc(sizeof(struct ListNode));

    l1->val = 2;
    l1->next = l2;
    l2->val = 3;
    p1->val = 4;
    p2->val = 6;
    l2->next = p1;
    p1->next = p2;
    p2->next = NULL;

    struct ListNode *l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l3 = reverseBetween2(l1, 1, 4);
    while (l3)
    {
        printf("%d->", l3->val);
        l3 = l3->next;
    }
    return 0;
}