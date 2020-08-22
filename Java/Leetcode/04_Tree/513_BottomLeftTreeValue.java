
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class BottomLeftTreeValue {

    static int ans;
    static int alevel;

    public int findBottomLeftValue(TreeNode root) {
        ans = root.val;
        alevel = 1;
        reCur(root, 1);
        return ans;
    }

    public static void reCur(TreeNode p, int level) {
        if (p == null)
            return;

        if (level > alevel) {
            ans = p.val;
            alevel = level;
        }

        reCur(p.left, level + 1);
        reCur(p.right, level + 1);

    }

}