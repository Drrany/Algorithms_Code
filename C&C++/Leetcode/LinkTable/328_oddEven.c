#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *oddEvenList(struct ListNode *head)
{

    if (!head || !head->next || !head->next->next)
        return head;

    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *cur = dummy;
    struct ListNode *preodd = dummy->next;
    do
    {
        cur=cur->next;
        preodd=preodd->next;

        struct ListNode *odd = preodd->next;
        preodd->next = preodd->next->next;
        odd->next = cur->next;
        cur->next = odd;

    } while (preodd && preodd->next && preodd->next->next);

    return dummy->next;
}