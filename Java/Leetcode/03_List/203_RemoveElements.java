

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class RemoveElements {

    public ListNode removeElements(ListNode head, int val) {

        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode p = dummy;
        ListNode q = p.next;
        while (p != null && q != null) {
            if (q.val == val)
                p.next = q.next;
            else   p = q;
            q = p.next;
        }

        return dummy.next;

    }
}
