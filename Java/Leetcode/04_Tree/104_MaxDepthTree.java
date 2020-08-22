

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class MaxDepth {

    public int maxDepth(TreeNode root) {
        return depthRecur(root);
    }

    public static int depthRecur(TreeNode p) {

        if (p == null)
            return 0;
            
        return Math.max(depthRecur(p.left), depthRecur(p.right)) + 1;
    }

}
