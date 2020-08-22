
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



class BTRightSideView {
    static List<Integer> ans;

    public static List<Integer> rightSideView(TreeNode root) {

        ans = new ArrayList<>();
        TreeNode p = root;
        reCur(p, 0);
        return ans;

    }

    public static void reCur(TreeNode p, int level) {

        if (p == null)
            return;

        if (level == ans.size())
            ans.add(p.val);

        reCur(p.right, level + 1);
        reCur(p.left, level + 1);

        return;

    }
}