
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class CountCompleteTreeNodes {

    public int countNodes(TreeNode root) {

        if (root == null)
            return 0;

        int left = levelCount(root.left);
        int right = levelCount(root.right);

        if (left == right)
            return countNodes(root.right) + (1 << left);
        else
            return countNodes(root.left) + (1 << right);
    }

    public static int levelCount(TreeNode p) {

        int level = 0;
        while (p != null) {
            p = p.left;
            level++;
        }

        return level;
    }

}