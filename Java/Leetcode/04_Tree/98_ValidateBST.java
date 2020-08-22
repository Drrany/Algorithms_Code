


import java.util.Deque;
import java.util.LinkedList;


class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class ValidateBST {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(2);
        TreeNode p1 = new TreeNode(1);
        TreeNode p2 = new TreeNode(3);
        // TreeNode p3 = new TreeNode(0);
        // TreeNode p4 = new TreeNode(2);
        // TreeNode p5 = new TreeNode(4);
        // TreeNode p6 = new TreeNode(6);
        // TreeNode p7 = new TreeNode(3);
        root.left = p1;
        root.right = p2;
        p1.left = null;
        p1.right = null;
        p2.left = null;
        p2.right = null;
        // p3.left = null;
        // p3.right = null;
        // p4.left = null;
        // p4.right = p7;
        // p7.left = null;
        // p7.right = null;
        boolean b = isValidBST(root);
        System.out.println(b);
    }

    // 方法1：二叉搜索树中序遍历是递增的，所以可以中序遍历判断前一数是否小于后一个数.
    // 递归
    static TreeNode cur;

    public static boolean isValidBST(TreeNode root) {

        cur = null;
        return inorder(root);

    }

    public static boolean inorder(TreeNode p) {

        if (p == null)
            return true;

        boolean l = inorder(p.left);

        boolean mid = false;
        if (cur == null || (cur != null && cur.val < p.val)) {
            cur = p;
            mid = true;
        }

        boolean r = inorder(p.right);

        return l && mid && r;

    }

    // 迭代
    public static boolean isValidBST2(TreeNode root) {

        Deque<TreeNode> s = new LinkedList<>();
        TreeNode p = root;

        TreeNode cur = null;
        while (p != null || !s.isEmpty()) {

            while (p != null) {
                s.push(p);
                p = p.left;
            }

            p = s.pop();
            if (cur != null && cur.val >= p.val)
                return false;
            cur = p;

            p = p.right;

        }

        return true;

    }

    // 方法二

    public static boolean isValidBST3(TreeNode root) {

        return reCur(root);

    }

    public static boolean reCur(TreeNode p) {

        if (p == null)
            return true;

        if ((p.left != null && findMax(p.left, p.left.val) >= p.val)
                || (p.right != null && findMin(p.right, p.right.val) <= p.val))
            return false;

        return reCur(p.left) && reCur(p.right);

    }

    public static int findMin(TreeNode p, int min) {
        if (p == null)
            return min;

        if (p.val < min)
            min = p.val;

        int minleft = findMin(p.left, min);
        int minright = findMin(p.right, min);

        return Math.min(minleft, minright);
    }

    public static int findMax(TreeNode p, int max) {
        if (p == null)
            return max;

        if (p.val > max)
            max = p.val;

        int maxleft = findMax(p.left, max);
        int maxright = findMax(p.right, max);

        return Math.max(maxleft, maxright);
    }

}
