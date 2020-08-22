#include <stdio.h>
//efinition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
    struct ListNode *Thead = (struct ListNode *)malloc(sizeof(struct ListNode));
    Thead->next = head;
    struct ListNode *pre = Thead;
    struct ListNode *p1 = NULL;
    struct ListNode *p2 = NULL;

    while (pre && pre->next&&pre->next->next)
    {
        p1=pre->next;
        p2=p1->next;

        pre->next = p2;
        p1->next = p2->next;
        p2->next = p1;

        pre = pre->next->next;
    }

    return Thead->next;
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
    l3 = swapPairs(l1);
    return 0;
}