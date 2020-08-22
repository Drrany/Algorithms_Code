

import java.util.Queue;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class LayerTraversal {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        TreeNode p1 = new TreeNode(9);
        TreeNode p2 = new TreeNode(20);
        TreeNode p3 = new TreeNode(15);
        TreeNode p4 = new TreeNode(7);
        root.left = p1;
        root.right = p2;
        p2.left = p3;
        p2.right = p4;
    }

    public static List<List<Integer>> levelOrderBottom(TreeNode root) {

        List<List<Integer>> ans = new ArrayList<>();
        if (root == null)
            return ans;

        Queue<TreeNode> p = new LinkedList<>();
        p.offer(root);

        int len = 1;
        int newlen = 1;
        int i = 0;

        List<Integer> a = new ArrayList<>();
        while (!p.isEmpty()) {

            TreeNode tmp = p.poll();
            a.add(tmp.val);
            i++;

            if (tmp.left != null) {
                p.offer(tmp.left);
                newlen++;
            }
            if (tmp.right != null) {
                p.offer(tmp.right);
                newlen++;
            }

            if (i >= len) {
                ans.add(0,new ArrayList<>(a));
                a.clear();
                len = newlen;
            }

        }

        return ans;
    }

}
