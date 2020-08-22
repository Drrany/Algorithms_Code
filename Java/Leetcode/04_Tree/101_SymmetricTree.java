class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class SymmetricTree {

    public boolean isSymmetric(TreeNode root) {
        if (root == null)
            return true;
        return isSymmetricRecur(root.left, root.right);
    }

    public static boolean isSymmetricRecur(TreeNode p1, TreeNode p2) {

        if (p1 == null && p2 != null || p1 != null && p2 == null)
            return false;
        else if (p1 == null && p2 == null)
            return true;
        else if (p1.val == p2.val) {
            return isSymmetricRecur(p1.right, p2.left) && isSymmetricRecur(p1.left, p2.right);
        } else
            return false;

    }

}