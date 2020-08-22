#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode **splitListToParts(struct ListNode *root, int k, int *returnSize)
{
    struct ListNode *p = root;
    int len = 0;
    while (p)
    {
        p = p->next;
        len++;
    }

    int i = len / k;
    int mod = len % k;
    *returnSize = k;

    p = root;
    struct ListNode **arr = (struct ListNode **)malloc(sizeof(struct ListNode *) * k);
    for (int j = 1; j <= k; j++)
    {
        arr[j - 1] = p;
        int flag = 0;
        if (mod-- > 0)
            flag++;
        for (int m = 2; m <= i+flag && p; m++)
        {
            p = p->next;
        }
        if (p)
        {
            struct ListNode *q = p->next;
            p->next = NULL;
            p = q;
        }
    }
    return arr;
}

int main()
{
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    //struct ListNode *p5 = (struct ListNode *)malloc(sizeof(struct ListNode));

    l1->val = 1;
    l1->next = p2;
    p2->val = 2;
    p3->val = 3;
    p4->val = 4;
    //p5->val = 5;
    p2->next = p3;
    p3->next = p4;
    p4->next = NULL;
    //p5->next = NULL;

    int size[10];
    splitListToParts(l1, 5, size);
    while (l1)
    {
        printf("%d->", l1->val);
        l1 = l1->next;
    }
    return 0;
}