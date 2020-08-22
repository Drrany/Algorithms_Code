#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

int *nextLargerNodes(struct ListNode *head, int *returnSize)
{
    *returnSize = 0;
    if (!head)
    {
        int a[1] = {0};
        return a;
    }
    struct ListNode *p = head;
    while (p)
    {
        (*returnSize)++;
        p = p->next;
    }
    int *a = (int *)malloc(sizeof(int) * (*returnSize));
    int i = -1;
    for (p = head; p; p = p->next)
    {
        i++;
        a[i] = 0;
        struct ListNode *q = p->next;
        while (q)
        {
            if (q->val > p->val)
            {
                a[i] = q->val;
                break;
            }
            q = q->next;
        }
    }

    return a;
}

//单调栈
int *nextLargerNodes2(struct ListNode *head, int *returnSize)
{
    *returnSize = 0;
    if (!head)
        return NULL;
    struct ListNode *p = head;
    while (p)
    {
        (*returnSize)++;
        p = p->next;
    }

    int *stack = (int *)malloc(sizeof(int) * (*returnSize));
    int *a = (int *)malloc(sizeof(int) * (*returnSize));
    int top = 0;
    int i = 0; //链表转数组下标

    p = head;
    stack[top++] = i;//栈存储下标
    a[i++] = p->val;
    while (p->next)
    {
        p = p->next;
        a[i++] = p->val;
        if (top > 0) //若栈不空
        {
            while (top > 0 && (p->val > a[stack[top - 1]]))
            {
                a[stack[top - 1]] = p->val;
                top--;
            }
        }
        stack[top++] = i - 1;
    }
    while (top > 0)
    {
        a[stack[top - 1]] = 0;
        top--;
    }
    return a;
}

int main()
{
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    //struct ListNode *p4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    //struct ListNode *p5 = (struct ListNode *)malloc(sizeof(struct ListNode));

    l1->val = 2;
    l1->next = p2;
    p2->val = 1;
    p3->val = 5;
    //p4->val = 3;
    //p5->val = 0;
    p2->next = p3;
    p3->next = NULL;
    //p4->next = NULL;
    //p5->next = NULL;

    int a;
    nextLargerNodes2(l1, &a);
    while (l1)
    {
        printf("%d->", l1->val);
        l1 = l1->next;
    }
    return 0;
}
