
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

class TreePaths {

    // 方法一：好麻烦 不知道为什么效率高
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ans = new ArrayList<>();
        if (root == null)
            return ans;

        List<String> path = new ArrayList<>();
        reCur(root, path, ans);
        return ans;
    }

    public static void reCur(TreeNode p, List<String> path, List<String> ans) {

        path.add(Integer.valueOf(p.val).toString());
        if (p.left == null && p.right == null) {

            StringBuilder tmp = new StringBuilder();
            int len = path.size();

            for (int i = 0; i < len - 1; i++)
                tmp.append(path.get(i) + "->");
            tmp.append(path.get(len - 1));
            ans.add(tmp.toString());

            path.remove(len - 1);
            return;
        }
        if (p.left != null)
            reCur(p.left, path, ans);
        if (p.right != null)
            reCur(p.right, path, ans);

        path.remove(path.size() - 1);
        return;

    }

    // 方法二 简单点：
    public List<String> binaryTreePaths2(TreeNode root) {
        List<String> ans = new ArrayList<>();
        if (root == null)
            return ans;

        String path = new String();
        reCur2(root, path, ans);
        return ans;
    }

    public static void reCur2(TreeNode p, String path, List<String> ans) {

        if (p == null)
            return;
        if (p.left == null && p.right == null) {

            path += Integer.valueOf(p.val).toString();
            ans.add(path);
            path = path.substring(0, path.length() - 1);
            return;
        }
        path += Integer.valueOf(p.val).toString()+"->";
        reCur2(p.left, path, ans);
        reCur2(p.right, path, ans);

        path = path.substring(0, path.length() - 2);
        return;

    }

}
