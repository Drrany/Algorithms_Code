#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *sortedListToBST(struct ListNode *head)
{
    if(!head) return NULL;
    struct TreeNode *root=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct ListNode *fast=head;
    struct ListNode *slow=head;
    struct ListNode *pre=head;

    while(fast&&fast->next){
        pre=slow;
        slow=slow->next;
        fast=fast->next->next;
    }

    root->val=slow->val;

    if(pre==slow)
        root->left=NULL;
    else{
        pre->next=NULL;
        root->left=sortedListToBST(head);
    }

    root->right=sortedListToBST(slow->next);

    return root;
}