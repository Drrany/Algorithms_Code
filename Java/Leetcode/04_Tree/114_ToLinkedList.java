


class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class TreeToLinkedddList {

    public void flatten(TreeNode root) {

        TreeNode p = root;
        TreeNode tmp = null;
        TreeNode right = null;
        while (p != null) {
            right = p.right;
            p.right = p.left;
            p.left = null;

            tmp = p;
            while (p.right != null)
                p = p.right;
            p.right = right;

            p = tmp.right;
        }
        return;
    }

}
