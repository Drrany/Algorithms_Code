
import java.util.HashMap;
import java.util.Map;


class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class HouseRobberIII {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        TreeNode p1 = new TreeNode(4);
        TreeNode p2 = new TreeNode(5);
        TreeNode p3 = new TreeNode(1);
        TreeNode p4 = new TreeNode(3);
        TreeNode p5 = new TreeNode(1);
        // TreeNode p6 = new TreeNode(6);
        // TreeNode p7 = new TreeNode(3);
        root.left = p1;
        root.right = p2;
        p1.left = p3;
        p1.right = p4;
        p2.left = null;
        p2.right = p5;
        p3.left = null;
        p3.right = null;
        p4.left = null;
        p4.right = null;
        p5.left = null;
        p5.right = null;
        int a = rob(root);
        System.out.println(a);
    }

    public static int rob(TreeNode root) {

        Map<TreeNode, Integer> dp = new HashMap<>();
        reCur(root, dp);
        return dp.getOrDefault(root, 0);

    }

    public static void reCur(TreeNode p, Map<TreeNode, Integer> dp) {
        if (p == null)
            return;

        reCur(p.left, dp);
        reCur(p.right, dp);

        int value = p.val;
        if (p.left != null)
            value += dp.getOrDefault(p.left.right, 0) + dp.getOrDefault(p.left.left, 0);
        if (p.right != null)
            value += dp.getOrDefault(p.right.right, 0) + dp.getOrDefault(p.right.left, 0);

        value = Math.max(value, dp.getOrDefault(p.right, 0) + dp.getOrDefault(p.left, 0));
        dp.put(p, value);
        return;
    }

}