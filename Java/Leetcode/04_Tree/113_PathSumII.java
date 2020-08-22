

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

class PathSumTwo {

    public List<List<Integer>> pathSum(TreeNode root, int sum) {

        List<List<Integer>> ans = new ArrayList<>();
        reCur(root, sum, new ArrayList<Integer>(), ans);
        return ans;
    }

    public static void reCur(TreeNode p, int tmpsum, List<Integer> path, List<List<Integer>> ans) {
        if (p == null)
            return;

        tmpsum -= p.val;
        path.add(p.val);
        if (p.left == null && p.right == null && tmpsum == 0)
            ans.add(new ArrayList<>(path));

        int size = path.size();
        reCur(p.left, tmpsum, path, ans);
        path = path.subList(0, size);
        reCur(p.right, tmpsum, path, ans);
    }

}
