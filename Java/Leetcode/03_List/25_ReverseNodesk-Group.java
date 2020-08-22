


class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}


class ReverseNodesk {

    public static ListNode reverseKGroup(ListNode head, int k) {

        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode s = dummy, e = dummy;
        while (e != null) {
            int n = k;
            while (e != null && n > 0) {
                e = e.next;
                n--;
            }
            if (e == null)
                break;
            s = reverse(s, e);
            e = s;
        }

        return dummy.next;

    }

    public static ListNode reverse(ListNode prest, ListNode end) {
        ListNode tmp = end.next;
        ListNode next = prest.next;
        while (prest.next != end) {
            ListNode p = prest.next;
            prest.next = p.next;
            p.next = tmp;
            end.next = p;
            tmp = p;
        }

        return next;
    }

}
