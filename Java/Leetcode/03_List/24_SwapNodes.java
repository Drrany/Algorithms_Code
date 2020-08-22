
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class SwapPairs {

    // 方法一 直接换
    public ListNode swapPairs(ListNode head) {

        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode p = dummy;
        while (p.next != null && p.next.next != null) {
            ListNode q = p.next;
            p.next = q.next;
            q.next = p.next.next;
            p.next.next = q;
            p = p.next.next;
        }

        return dummy.next;

    }

    // 方法二：递归
    public ListNode swapPairs2(ListNode head) {

        if (head == null || head.next == null)
            return head;

        ListNode p = head.next;
        head.next = swapPairs(head.next.next);
        p.next = head;
        return p;
    }

}