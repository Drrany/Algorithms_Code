
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class BalanceBinTree {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        TreeNode p1 = new TreeNode(2);
        TreeNode p2 = new TreeNode(2);
        TreeNode p3 = new TreeNode(3);
        TreeNode p4 = new TreeNode(3);
        TreeNode p5 = new TreeNode(4);
        TreeNode p6 = new TreeNode(4);
        root.left = p1;
        root.right = p2;
        p1.left = p3;
        p1.right = p4;
        p3.left = p5;
        p3.right = p6;
    }


    public static boolean isBalanced(TreeNode root) {
        int flag = reCur(root);
        if (flag == -1)
            return false;
        return true;
    }

    public static int reCur(TreeNode p) {

        if (p == null)
            return 0;

        int left = reCur(p.left);
        int right = reCur(p.right);

        if (left == -1 || right == -1 || Math.abs(left - right) > 1)
            return -1;

        return Math.max(left, right) + 1;
    }

}
