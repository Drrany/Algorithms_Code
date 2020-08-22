#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

//递归实现
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    if (!l1)
        return l2;
    else if (!l2)
        return l1;
    else
    {
        if (l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
}

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *pa = l1;
    struct ListNode *pb = l2;
    struct ListNode *LC = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *pc = LC;
    while (pa && pb)
    {
        struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (pa->val <= pb->val)
        {
            tmp = pa;
            pa = pa->next;
        }
        else
        {
            tmp = pb;
            pb = pb->next;
        }
        pc->next = tmp;
        pc = tmp;
    }
    pc->next = pa ? pa : pb;
    return LC->next;
}