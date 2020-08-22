#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

//使用递归的归并排序
/* struct ListNode *sortList(struct ListNode *head)
{
    if (!head || !head->next)
        return head;
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (slow->next && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *mid = slow->next;
    slow->next = NULL;
    struct ListNode *left = sortList(head);
    struct ListNode *right = sortList(mid);
    struct ListNode *tmpH = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *pH = (struct ListNode *)malloc(sizeof(struct ListNode));
    tmpH = pH;
    while (left && right)
    {
        struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (left->val <= right->val)
        {
            tmp = left;
            left = left->next;
        }
        else
        {
            tmp = right;
            right = right->next;
        }
        pH->next = tmp;
        pH = tmp;
    }
    pH->next = left ? left : right;
    return tmpH->next;
} */

struct ListNode *cutList(struct ListNode *List, int n)
{
    if (!List)
        return List;
    struct ListNode *mHead = List;
    struct ListNode *p = List;
    while (p && --n > 0)
        p = p->next;

    if (p)
    {
        mHead = p->next;
        p->next = NULL;
        return mHead;
    }
    
    else return NULL;

}

struct ListNode *mergeList(struct ListNode *LA, struct ListNode *LB)
{
    struct ListNode *pa = LA;
    struct ListNode *pb = LB;
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

//不使用递归，***重要
struct ListNode *sortList(struct ListNode *head)
{
    if (!head)
        return head;
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode *p = head;
    int len = 1;
    while (p->next)
    {
        len++;
        p = p->next;
    }

    for (int i = 1; i < len; i *= 2)
    {
        struct ListNode *current = dummy->next;
        struct ListNode *rear = dummy;
        while (current)
        {
            struct ListNode *left = current;
            struct ListNode *right = cutList(current, i);
            current = cutList(right, i);
            rear->next = mergeList(left, right);
            while (rear->next)
                rear = rear->next;
        }
    }

    return dummy->next;
}

int main()
{
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p5 = (struct ListNode *)malloc(sizeof(struct ListNode));

    l1->val = -1;
    l1->next = p2;
    p2->val = 5;
    p3->val = 3;
    p4->val = 4;
    p5->val=0;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next=NULL;

    sortList(l1);
    while (l1)
    {
        printf("%d->", l1->val);
        l1 = l1->next;
    }
    return 0;
}