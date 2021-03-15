struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummyHead = new ListNode(), *p = dummyHead;
        int carry = 0, sum, a, b;
        while (l1 != nullptr || l2 != nullptr) {
            a = l1 == nullptr ? 0 : l1->val;
            b = l2 == nullptr ? 0 : l2->val;
            sum = a + b + carry;
            carry = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        if (carry != 0) p->next = new ListNode(1);
        return dummyHead->next;
    }
};