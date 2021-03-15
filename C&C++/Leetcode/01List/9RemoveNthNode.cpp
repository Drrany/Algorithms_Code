struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *left = head, *right = head, *preLeft = dummyHead;
        for (int i = 0; i < n; ++i)
            right = right->next;
        while (right != nullptr) {
            preLeft = left;
            left = left->next;
            right = right->next;
        }
        // remove left
        preLeft->next = left->next;
        delete left;
        return dummyHead->next;
    }
};