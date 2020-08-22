

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class DeleteNodeinBST {


    public static TreeNode deleteN(TreeNode p) {

        if (p.left == null)
            p = p.right;
        else if (p.right == null)
            p = p.left;
        else {
            TreeNode t = p.right;
            TreeNode pret = p;
            while (t.left != null) {
                pret = t;
                t = t.left;
            }
            p.val = t.val;
            if (pret != p)
                pret.left = t.right;
            else
                pret.right = t.right;
        }

        return p;

    }

    public static TreeNode deleteNode(TreeNode root, int key) {

        if (root == null)
            return root;

        if (root.val == key)
            root = deleteN(root);
        else if (root.val < key)
            root.right = deleteNode(root.right, key);
        else
            root.left = deleteNode(root.left, key);

        return root;

    }

}