#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void reorderList(struct ListNode *head)
{

    if (!head || !head->next||!head->next->next)
        return;

    struct ListNode *rear = head->next;
    int len = 0;
    head->next = NULL;
    
    while (rear)
    {
        len++;
        struct ListNode *tmp = rear->next;
        rear->next = head->next;
        head->next = rear;
        rear = tmp;
    }


    struct ListNode *mid = head;
    for (int i = 0; i < len / 2; i++)
        mid = mid->next;

    struct ListNode *mrear = mid->next;
    mid->next=NULL;
    while (mrear)
    {
        struct ListNode *tmp = mrear->next;
        mrear->next = mid->next;
        mid->next = mrear;
        mrear = tmp;
    }
    
    struct ListNode *p = head->next;
    mrear=mid->next;
    mid->next=NULL;
    mid=mrear;
    while(mid&&p){
        struct ListNode *tmp=mid->next;
        mid->next=p->next;
        p->next=mid;

        if(mid->next==NULL&&tmp){
            mid->next=tmp;
            break;
        }
        else
             p=mid->next;
        mid=tmp;
    }

    return;
}

int main()
{
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p2 = (struct ListNode *)malloc(sizeof(struct ListNode));

    l1->val = 2;
    l1->next = l2;
    l2->val = 3;
    p1->val = 4;
    p2->val = 6;
    l2->next = p1;
    p1->next = p2;
    p2->next = NULL;

    reorderList(l1);
    while (l1)
    {
        printf("%d->", l1->val);
        l1 = l1->next;
    }
    return 0;
}