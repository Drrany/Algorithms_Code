import java.util.ArrayList;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class LowAncestorBST {

    // 方法一：利用二叉搜索树的特性
    public TreeNode lowestCommonAncestor2(TreeNode root, TreeNode p, TreeNode q) {

        TreeNode tmp = root;

        while (true) {
            if ((p.val <= tmp.val && q.val >= tmp.val) || (p.val >= tmp.val && q.val <= tmp.val))
                return tmp;
            if (p.val < tmp.val && q.val < tmp.val)
                tmp = tmp.left;
            else
                tmp = tmp.right;
        }

    }


    // 方法二
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        List<TreeNode> pl = new ArrayList<>();
        List<TreeNode> ql = new ArrayList<>();

        reCur(root, p.val, pl);
        reCur(root, q.val, ql);

        for (int i = pl.size() - 1; i >= 0; i--) {
            if (ql.contains(pl.get(i)))
                return pl.get(i);
        }

        return null;
    }

    public static void reCur(TreeNode p, int val, List<TreeNode> l) {

        l.add(p);
        if (p.val == val)
            return;
        if (p.val > val) {
            reCur(p.left, val, l);
        } else {
            reCur(p.right, val, l);
        }
        return;
    }



}
