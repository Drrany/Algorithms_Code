#include <stdio.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head)
{
    if (!head)
        return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;
    int flag = 0;
    while (slow->next && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            flag = 1;
            break;
        }
    }
    

    if (!flag)
        return NULL;
    else
    {
        struct ListNode *pre = head;
        while (pre != fast)
        {
            pre = pre->next;
            fast = fast->next;
        }
        return pre;
    }
}