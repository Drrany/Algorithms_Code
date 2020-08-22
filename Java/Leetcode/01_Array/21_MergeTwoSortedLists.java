package Leetcode;

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class MergeTwoLists {

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {

        ListNode dummmy = new ListNode(0);
        dummmy.next = reCur(l1, l2);
        return dummmy.next;

    }

    public static ListNode reCur(ListNode l1, ListNode l2) {
        if (l1 == null && l2 == null)
            return null;
        else if (l1 == null)
            return l2;
        else if (l2 == null)
            return l1;
        else if (l1.val < l2.val){
            l1.next = reCur(l1.next, l2);
            return l1;
        }
        else {
            l2.next = reCur(l1, l2.next);
            return l2;
        }
    }

}
