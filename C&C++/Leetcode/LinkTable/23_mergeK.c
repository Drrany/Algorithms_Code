#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};


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

struct ListNode* mergeK(struct ListNode** lists, int start,int end){
    if(start==end)
        return lists[start];

    int mid = (start + end) / 2;
    struct ListNode *L = (struct ListNode *)malloc(sizeof(struct ListNode));
    L->next = mergeK(lists, mid + 1, end);
    struct ListNode *R = (struct ListNode *)malloc(sizeof(struct ListNode));
    R->next = mergeK(lists, start, mid);

    return mergeTwoLists(L->next, R->next);

}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize<1)
        return NULL;
    return mergeK(lists, 0, listsSize - 1);
}