

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}

class MinStack {

    int min;
    ListNode stack;

    /** initialize your data structure here. */
    public MinStack() {
        min = Integer.MAX_VALUE;
        stack = new ListNode(-1);
    }

    public void push(int x) {
        ListNode p = new ListNode(x);
        p.next = stack.next;
        stack.next = p;
        min = x < min ? x : min;
    }

    public void pop() {

        if (min == stack.next.val) {
            min = Integer.MAX_VALUE;
            ListNode p = stack.next.next;
            while (p != null) {
                min = Math.min(min, p.val);
                p = p.next;
            }
        }
        stack.next = stack.next.next;

    }

    public int top() {

        return stack.next.val;

    }

    public int getMin() {

        return min;

    }
}

/**
 * Your MinStack object will be instantiated and called as such: MinStack obj =
 * new MinStack(); obj.push(x); obj.pop(); int param_3 = obj.top(); int param_4
 * = obj.getMin();
 */