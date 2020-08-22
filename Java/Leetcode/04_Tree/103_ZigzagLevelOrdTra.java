

import java.util.ArrayList;
import java.util.Deque;
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

class ZigzagLevel {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        TreeNode p1 = new TreeNode(9);
        TreeNode p2 = new TreeNode(20);
        TreeNode p3 = new TreeNode(15);
        TreeNode p4 = new TreeNode(7);
        // TreeNode p5 = new TreeNode(4);
        // TreeNode p6 = new TreeNode(6);
        // TreeNode p7 = new TreeNode(3);
        root.left = p1;
        root.right = p2;
        p1.left = null;
        p1.right = null;
        p2.left = p3;
        p2.right = p4;
        p3.left = null;
        p3.right = null;
        p4.left = null;
        p4.right = null;
        zigzagLevelOrder(root);
    }

    public static List<List<Integer>> zigzagLevelOrder(TreeNode root) {

        List<List<Integer>> ans = new ArrayList<>();
        if (root == null)
            return ans;

        Deque<TreeNode> s = new LinkedList<>();
        TreeNode p = root;

        int leftline = 0;
        int rightline = 1;
        int level = 1;

        s.offer(p);
        List<Integer> a = new LinkedList<>();

        while (!s.isEmpty()) {

            TreeNode tmp = s.poll();
            leftline++;
            if (level % 2 == 0)
                a.add(0, tmp.val);
            else
                a.add(tmp.val);


            if (tmp.left != null)
                s.offer(tmp.left);

            if (tmp.right != null)
                s.offer(tmp.right);


            if (leftline >= rightline) {
                rightline += s.size();
                ans.add(new ArrayList<Integer>(a));
                a.clear();

                level++;
            }

        }

        return ans;

    }

}
