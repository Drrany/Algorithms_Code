package Leetcode;

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        ListNode dummyHead = new ListNode(0);
        ListNode p1 = l1, p2 = l2, p = dummyHead;
        int count = 0;
        int sum = 0;

        while (p1 != null || p2 != null) {
            int m1 = (p1 == null) ? 0 : p1.val;
            int m2 = (p2 == null) ? 0 : p2.val;

            sum = m1 + m2 + count;
            count = sum / 10;
            p.next = new ListNode(sum % 10);

            if(p1!=null)
                p1 = p1.next;
            if(p2!=null)
                p2 = p2.next;
            p = p.next;
        }

        if (count == 1)
            p.next = new ListNode(1);

        return dummyHead.next;

    }

}
