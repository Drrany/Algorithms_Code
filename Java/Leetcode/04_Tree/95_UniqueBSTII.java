

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

class UniqueBST {

    public static void main(String[] args) {

        generateTrees(3);

    }

    public static List<TreeNode> generateTrees(int n) {

        List<TreeNode> ans = new ArrayList<>();
        if (n < 1)
            return ans;
        ans = reCur(1, n);
        return ans;
    }

    public static List<TreeNode> reCur(int left, int right) {

        List<TreeNode> tmp = new ArrayList<>();
        if (left > right) {
            tmp.add(null);
            return tmp;
        }


        for (int i = left; i <= right; i++) {
            List<TreeNode> arrlf = reCur(left, i - 1);
            List<TreeNode> arrrg = reCur(i + 1, right);

            for (TreeNode lNode : arrlf) {
                for (TreeNode rNode : arrrg) {
                    TreeNode p = new TreeNode(i);
                    p.left = lNode;
                    p.right = rNode;
                    tmp.add(p);
                }
            }

        }

        return tmp;

    }

}
