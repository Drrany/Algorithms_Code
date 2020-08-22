
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class PathSum {

    public boolean hasPathSum(TreeNode root, int sum) {
        return reCur(root, sum);
    }

    public static boolean reCur(TreeNode p, int subsum) {
        if (p == null)
            return false;
        int sub = subsum - p.val;
        if (p.left == null && p.right == null && sub == 0)
            return true;
        return reCur(p.left, sub) || reCur(p.right, sub);
    }

}
