


class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class RoottoLeaf {


    public int sumNumbers(TreeNode root) {

        int sum = reCur(root, 0);
        return sum;

    }

    public static int reCur(TreeNode p, int path) {

        if (p == null)
            return 0;

        if (p.left == null && p.right == null)
            return path * 10 + p.val;

        return reCur(p.left, path * 10 + p.val) + reCur(p.right, path * 10 + p.val);

    }

}
