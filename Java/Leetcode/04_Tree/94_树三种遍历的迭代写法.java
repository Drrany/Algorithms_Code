

import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;



class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Iteratively {

    // 二叉树前序遍历 迭代
    public List<Integer> preorderTraversal(TreeNode root) {

        List<Integer> ans = new ArrayList<>();
        Deque<TreeNode> s = new LinkedList<>();
        TreeNode p = root;

        while (p != null || !s.isEmpty()) {

            while (p != null) {
                ans.add(p.val);
                s.push(p);
                p = p.left;
            }

            p = s.pop().right;
        }

        return ans;

    }


    // 中序遍历 迭代
    public List<Integer> inorderTraversal(TreeNode root) {

        List<Integer> ans = new ArrayList<>();
        Deque<TreeNode> s = new LinkedList<>();
        TreeNode p = root;

        while (p != null || !s.isEmpty()) {

            while (p != null) {
                s.push(p);
                p = p.left;
            }

            ans.add(s.peek().val);
            p = s.pop().right;
        }

        return ans;

    }

    // 后序遍历 迭代
    // 方法1：根节点->右子树->左子树 然后将结果逆序
    public List<Integer> postorderTraversal1(TreeNode root) {

        List<Integer> ans = new ArrayList<>();
        Deque<TreeNode> s = new LinkedList<>();
        TreeNode p = root;

        while (p != null || !s.isEmpty()) {

            while (p != null) {
                ans.add(p.val);
                s.push(p);
                p = p.right;
            }

            p = s.pop().left;
        }

        Collections.reverse(ans);
        return ans;
    }

    // 方法二：给每个节点附加一个标记。在访问其右子树前置为True。之后子树返回时，为True表示从右子树返回，否则从左子树返回
    public List<Integer> postorderTraversal2(TreeNode root) {

        List<Integer> ans = new ArrayList<>();
        Deque<TreeNode> s = new LinkedList<>();
        TreeNode p = root;

        Map<TreeNode, Boolean> flag = new HashMap<>();

        while (p != null || !s.isEmpty()) {

            while (!s.isEmpty() && flag.get(s.peek()))
                ans.add(s.pop().val);

            while (p != null) {
                s.push(p);
                flag.put(p, false);
                p = p.left;
            }

            if (!s.isEmpty()) {
                p = s.peek().right;
                flag.put(s.peek(), true);
            }

        }

        return ans;
    }

    // 方法三：如果当前节点的右节点和上一次遍历的节点相同，那就表明当前是从右节点过来的
    public List<Integer> postorderTraversal3(TreeNode root) {

        List<Integer> ans = new ArrayList<>();
        Deque<TreeNode> s = new LinkedList<>();
        TreeNode p = root;
        TreeNode pre = null;

        while (p != null || !s.isEmpty()) {

            while (p != null) {
                s.push(p);
                p = p.left;
            }

            TreeNode tmp = s.peek();
            if (tmp.right != null && tmp.right != pre)
                p = tmp.right;
            else {
                ans.add(tmp.val);
                pre = tmp;
                s.pop();
            }
        }

        return ans;
    }

    // 方法四：把每个节点 push 两次，然后判断当前 pop 节点和栈顶节点是否相同
    public List<Integer> postorderTraversal4(TreeNode root) {

        List<Integer> ans = new ArrayList<>();
        if (root == null)
            return ans;

        Deque<TreeNode> s = new LinkedList<>();
        s.push(root);
        s.push(root);

        while (!s.isEmpty()) {

            TreeNode p = s.pop();
            if (p == null)
                continue;

            if (!s.isEmpty() && p == s.peek()) {
                s.push(p.right);
                s.push(p.right);
                s.push(p.left);
                s.push(p.left);
            } else
                ans.add(p.val);

        }

        return ans;
    }

}
