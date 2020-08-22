

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class SameTree {

    public static boolean flag;

    public boolean isSameTree(TreeNode p, TreeNode q) {

        return isSameRcur(p, q);

    }

    public static boolean isSameRcur(TreeNode p, TreeNode q) {

        if (p == null && q != null || p != null && q == null)
            return false;
        else if (p == null && q == null)
            return true;
        else {
            if (p.val == q.val) {
                return isSameRcur(p.left, q.left)&&isSameRcur(p.right, q.right);
            } else
                return false;
        }

    }

}