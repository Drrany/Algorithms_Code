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

class ConstructBiTree {

    static Map<Integer,Integer> index = new HashMap<>();

    public TreeNode buildTree(int[] preorder, int[] inorder) {

        int len = preorder.length;
        for (int i = 0; i < len; i++)
            index.put(inorder[i], i);
            
        return reCur(preorder, inorder, 0, len, 0, len);

    }

    public static TreeNode reCur(int[] preorder, int[] inorder, int p_start, int p_end, int i_start, int i_end) {

        if (p_start == p_end)
            return null;

        TreeNode t = new TreeNode(preorder[p_start]);
        int i = index.get(preorder[p_start]);
        int lefnum = i - i_start;
        t.left = reCur(preorder, inorder, p_start + 1, p_start + 1 + lefnum, i_start, i);
        t.right = reCur(preorder, inorder, p_start + 1 + lefnum, p_end, i + 1, i_end);
        return t;
    }

}
