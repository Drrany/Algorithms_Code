
import java.util.Deque;
import java.util.LinkedList;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class MaxWidthBTree {

    public int widthOfBinaryTree(TreeNode root) {

        Deque<TreeNodePos> q = new LinkedList<>();
        int maxcount = 0, left = 0;
        q.add(new TreeNodePos(root, 1));
        while (!q.isEmpty()) {
            int width = q.size();
            TreeNodePos t = q.poll();
            left = t.pos;
            for (int i = 0; i < width; i++) {
                if (t.node.left != null)
                    q.add(new TreeNodePos(t.node.left, t.pos * 2));
                if (t.node.right != null)
                    q.add(new TreeNodePos(t.node.right, t.pos * 2 + 1));
                if (i != width - 1)
                    t = q.poll();
            }
            maxcount = Math.max(maxcount, t.pos - left + 1);

        }
        return maxcount;

    }

}

class TreeNodePos {
    TreeNode node;
    int pos;

    TreeNodePos(TreeNode p, int pos) {
        this.node = p;
        this.pos = pos;
    }
}