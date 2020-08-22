


class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}



class PalindromeList {

    public static void main(String[] args) {
        ListNode p1 = new ListNode(1);
        ListNode p2 = new ListNode(0);
        ListNode p3 = new ListNode(1);
        p1.next = p2;
        p2.next = p3;
        p3.next = null;
        isPalindrome(p1);
    }

    public static boolean isPalindrome(ListNode head) {

        if (head == null || head.next == null)
            return true;

        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode slow = head;
        ListNode fast = dummy;
        ListNode pre = null;

        // 将链表前半部分反转
        while (fast != null && fast.next != null) {

            fast = fast.next.next;

            ListNode tmp = slow.next;
            slow.next = pre;
            pre = slow;
            slow = tmp;

        }

        if (fast == null)
            pre = pre.next;

        while (slow != null) {
            if (pre.val != slow.val)
                return false;
            pre = pre.next;
            slow = slow.next;
        }
        return true;

    }

}
