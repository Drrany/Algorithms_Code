
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

class PathSumThree {

    public static void main(String[] args) {

        TreeNode root = new TreeNode(0);
        TreeNode p1 = new TreeNode(1);
        TreeNode p2 = new TreeNode(1);
        root.left = p1;
        root.right = p2;
        p1.left = null;
        p1.right = null;
        p2.left = null;
        p2.right = null;
        int n = pathSum(root, 1);
        System.out.println(n);
    }

    public static int pathSum(TreeNode root, int sum) {
        int count = 0;
        Map<Integer, Integer> tmppath = new HashMap<>();
        tmppath.put(0, 1);
        count = reCur(root, sum, 0, tmppath);

        return count;
    }

    public static int reCur(TreeNode p, int sum, int pathsum, Map<Integer, Integer> tmppath) {
        if (p == null)
            return 0;

        int count = 0;

        int tsum = pathsum + p.val;
        count += tmppath.getOrDefault(tsum - sum, 0);
        tmppath.put(tsum, tmppath.getOrDefault(tsum, 0) + 1);

        count += reCur(p.left, sum, tsum, tmppath) + reCur(p.right, sum, tsum, tmppath);

        tmppath.put(tsum, tmppath.get(tsum) - 1);
        return count;
    }

}
