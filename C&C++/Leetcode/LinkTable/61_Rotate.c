#include <stdio.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k)
{
    struct ListNode *rear = head;
    int l;
    if (rear)
    {
        l = 1;
        while (rear->next)
        {
            rear = rear->next;
            l++;
        }
        rear->next = head;
        int n = l - (k % l);
        while (n-- > 0)
            head = head->next;
        rear = head;
        while (l-- > 1)
            rear = rear->next;
        rear->next = NULL;
    }

    return head;
}
