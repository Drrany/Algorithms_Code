
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class KthSmallesteinBST {

    static int ans;
    static int count;

    public int kthSmallest(TreeNode root, int k) {
        count = k;
        ans = 0;
        reCur(root);

        return ans;
    }

    public static void reCur(TreeNode p) {

        if (p == null || count < 0)
            return;

        reCur(p.left);

        count--;
        if (count == 0)
            ans = p.val;

        reCur(p.right);

    }

}