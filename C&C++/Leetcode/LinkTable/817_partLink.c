#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

int numComponents(struct ListNode *head, int *G, int GSize)
{
    if (!head)
        return 0;
    int Lflag[1000] = {0};
    int Gflag[1000] = {0};
    int n = 0;
    struct ListNode *p = head;
    int i = -1;
    while (p)
    {
        while (i < GSize-1)
        {
            i++;
            if (Gflag[i])
                continue;   
            else
            {
                if (p->val == G[i])
                {
                    Lflag[n]++;
                    Gflag[i]++;
                    break;
                }
            }
        }
        i = -1;
        n++;
        p = p->next;
    }

    int cn = 0;
    i = 0;
    while (i < n)
    {
        while (!Lflag[i] && i < n)
            i++;
        if (i >= n-1 && !Lflag[i])
            return cn;
        cn++;
        while (Lflag[i] && i < n)
            i++;
    }
    return cn;
}

int main()
{
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    //struct ListNode *p4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    //struct ListNode *p5 = (struct ListNode *)malloc(sizeof(struct ListNode));

    l1->val = 0;
    l1->next = p2;
    p2->val = 1;
    p3->val = 2;
    //p4->val = 3;
    //p5->val = 0;
    p2->next = p3;
    p3->next = NULL;
    //p4->next = NULL;
    //p5->next = NULL;

    int a[] = {1, 0};
    int n = numComponents(l1, a, 2);
    printf("%d\n", n);
    while (l1)
    {
        printf("%d->", l1->val);
        l1 = l1->next;
    }
    return 0;
}
