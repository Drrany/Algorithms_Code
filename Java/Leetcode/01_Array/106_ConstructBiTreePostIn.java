package Leetcode;

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

class ConstructPostIn {

    static Map<Integer, Integer> index = new HashMap<>();

    public static void main(String[] args) {
        text t = new text();
        int[] inorder = { 9, 3, 15, 20, 7 };
        int[] postorder = { 9, 15, 7, 20, 3 };
        t.buildTree(inorder, postorder);
    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {

        int len = inorder.length;
        for (int i = 0; i < len; i++)
            index.put(inorder[i], i);
        return reCur(postorder, inorder, 0, len, 0, len);

    }

    public static TreeNode reCur(int[] postorder, int[] inorder, int p_start, int p_end, int i_start, int i_end) {

        if (p_start == p_end)
            return null;

        TreeNode t = new TreeNode(postorder[p_end - 1]);
        int i = index.get(postorder[p_end - 1]);
        int rightnum = i_end - i;
        t.left = reCur(postorder, inorder, p_start, p_end - rightnum, i_start, i);
        t.right = reCur(postorder, inorder, p_end - rightnum, p_end - 1, i + 1, i_end);
        return t;
    }

}
