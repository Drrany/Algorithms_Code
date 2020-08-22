#include <stdio.h>
#include <stdlib.h>

typedef struct linknode
{
    int val;
    struct linknode *next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList *myLinkedListCreate()
{
    MyLinkedList *head = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    head->next = NULL;
    return head;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList *obj, int index)
{
    if (index < 0)
        return -1;
    MyLinkedList *p = obj->next;
    while (p && index-- > 0)
        p = p->next;
    if (p && index == -1)
        return p->val;
    else
        return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    MyLinkedList *tmp = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    tmp->val = val;
    tmp->next = NULL;
    if (!obj->next)
        obj->next = tmp;
    else
    {
        tmp->next = obj->next;
        obj->next = tmp;
    }
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    MyLinkedList *tmp = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    tmp->val = val;
    tmp->next = NULL;
    MyLinkedList *p = obj->next;
    if (!p)
        obj->next = tmp;
    else
    {
        while (p && p->next)
            p = p->next;
        p->next = tmp;
    }
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    MyLinkedList *tmp = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    tmp->val = val;
    tmp->next=NULL;
    if (index < 1)
    {
        tmp->next = obj->next;
        obj->next = tmp;
        return;
    }
    MyLinkedList *p = obj->next;
    while (p && index-- > 1)
        p = p->next;
    if (!p)
        return;
    else
    {
        tmp->next = p->next;
        p->next = tmp;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    if (index < 0 || !obj->next)
        return;
    if (index == 0)
    {
        MyLinkedList *tmp = obj->next;
        obj->next = obj->next->next;
        free(tmp);
    }

    MyLinkedList *p = obj->next;

    while (p && index-- > 1)
        p = p->next;
    if (!p || !p->next)
        return;
    MyLinkedList *tmp = p->next;
    p->next = tmp->next;
    free(tmp);
}

void myLinkedListFree(MyLinkedList *obj)
{
    MyLinkedList *p = obj;
    while (p)
    {
        MyLinkedList *q = p->next;
        free(p);
        p = q;
    }
}

int main()
{
    MyLinkedList *obj = myLinkedListCreate();
    myLinkedListAddAtIndex(obj, 0, 10);
    myLinkedListAddAtIndex(obj, 0, 20);
    myLinkedListAddAtIndex(obj, 1, 20);
    int a = myLinkedListGet(obj, 0);

    myLinkedListFree(obj);
    return 0;
}