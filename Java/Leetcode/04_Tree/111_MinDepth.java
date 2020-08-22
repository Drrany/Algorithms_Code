
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class MinDepth {

    public int minDepth(TreeNode root) {

        return reCur(root);

    }

    public static int reCur(TreeNode p) {

        if (p == null)
            return 0;
        if (p.left == null && p.right == null)
            return 1;

        int left = reCur(p.left);
        int right = reCur(p.right);

        if (p.left == null)
            return right + 1;
        if (p.right == null)
            return left + 1;
        return Math.min(left, right) + 1;

    }

}
