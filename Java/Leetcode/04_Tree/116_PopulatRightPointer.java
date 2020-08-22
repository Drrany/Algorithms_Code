
import java.util.Deque;
import java.util.LinkedList;



class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {
    }

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class PopulatRightPointer {

    // 方法一：层次遍历
    public Node connect(Node root) {

        Node p = root;
        Deque<Node> s = new LinkedList<>();
        s.offer(p);
        int count = 1;

        while (!s.isEmpty() && root != null) {
            Node pre = s.poll();
            for (int i = 1; i <= count; i++) {
                if (pre.left != null)
                    s.offer(pre.left);
                if (pre.right != null)
                    s.offer(pre.right);

                if (i != count) {
                    Node cur = s.poll();
                    pre.next = cur;
                    pre = cur;
                }
            }
            pre.next = null;
            count = s.size();
        }

        return root;

    }

    // 方法二：递归
    public Node connect2(Node root) {

        if (root == null)
            return null;

        if (root.left != null) {
            root.left.next = root.right;
            if (root.next != null)
                root.right.next = root.next.left;
        }

        connect(root.left);
        connect(root.right);

        return root;
    }

}
