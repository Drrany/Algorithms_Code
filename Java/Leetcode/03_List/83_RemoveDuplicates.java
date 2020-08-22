
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class RemoveList {

    public ListNode deleteDuplicates(ListNode head) {

        ListNode dummy = new ListNode(Integer.MIN_VALUE);
        ListNode p = dummy;

        while (head != null) {

            while (head != null && p.val == head.val)
                head = head.next;

            if (head == null) {
                p.next = null;
                break;
            }

            p.next = head;
            head = head.next;
            p = p.next;
        }

        return dummy.next;

    }
}