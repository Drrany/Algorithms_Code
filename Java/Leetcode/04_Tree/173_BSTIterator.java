

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

class BSTIterator {

    TreeNode root;
    TreeNode p;
    TreeNode pre;
    List<Integer> ans;
    int count = 0;

    public BSTIterator(TreeNode root) {

        this.root = root;
        ans = new ArrayList<>();

        p = root;
        Deque<TreeNode> s = new LinkedList<>();

        while (!s.isEmpty() || p != null) {

            while (p != null) {
                s.push(p);
                p = p.left;
            }

            p = s.pop();
            ans.add(p.val);
            p = p.right;
        }

    }

    /** @return the next smallest number */
    public int next() {
        return ans.get(count++);
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {

        if (count <= ans.size() - 1)
            return true;
        else
            return false;

    }
}

