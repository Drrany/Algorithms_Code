
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

class LargestValueTreeRow {

    static List<Integer> ans;

    public List<Integer> largestValues(TreeNode root) {

        ans = new ArrayList<>();
        reCur(root, 0);
        return ans;
    }

    public static void reCur(TreeNode p, int level) {
        if (p == null)
            return;

        if (ans.size() <= level)
            ans.add(p.val);
        else
            ans.set(level, Math.max(ans.get(level), p.val));

        reCur(p.left, level + 1);
        reCur(p.right, level + 1);

    }

}