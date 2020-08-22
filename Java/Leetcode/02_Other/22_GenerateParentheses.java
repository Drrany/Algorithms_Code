

import java.util.ArrayList;
import java.util.List;

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class GenerateParenthesis {

    public static void main(String[] args) {
        generateParenthesis2(4);
    }

    // 方法三 深度优先遍历，效率还可以
    public static List<String> generateParenthesis3(int n) {
        List<String> ans = new ArrayList<>();
        if (n < 1)
            return ans;
        reCur(n, n, new String(), ans);
        return ans;
    }

    public static void reCur(int left, int right, String path, List<String> ans) {

        if (left == 0 && right == 0) {
            ans.add(new String(path));
            return;
        }
        if (left < 0 || right < 0 || left > right)
            return;
        else {
            reCur(left - 1, right, path + "(", ans);
            reCur(left, right - 1, path + ")", ans);
        }
        return;
    }

    // 方法一 效率低，在每个地方插入一对括号
    public static List<String> generateParenthesis(int n) {

        List<String> ans = new ArrayList<>();
        if (n < 1)
            return ans;
        String start = "()";
        ans.add(start);
        for (int i = 2; i <= n; i++) {

            int len = ans.size();

            for (int j = 0; j < len; j++) {
                start = ans.get(0);
                ans.remove(0);

                for (int k = 0; k <= (i - 1); k++) {
                    String tmp = start.substring(0, k) + "()" + start.substring(k);
                    if (ans.contains(tmp))
                        continue;
                    ans.add(new String(tmp));
                }

            }

        }

        return ans;
    }

    // 方法二：动态规划，效率还是很低
    public static List<String> generateParenthesis2(int n) {

        if (n < 1)
            return null;

        List<List<String>> ans = new ArrayList<>();
        ans.add(new ArrayList<>());
        ans.get(0).add("");

        for (int i = 1; i <= n; i++) { // 计算有i对括号时
            List<String> tmp = new ArrayList<>();

            for (int j = 0; j < i; j++) { // ()内部为j对括号

                int sub = i - j - 1; // ()外部为i-j-1对括号

                List<String> str1 = ans.get(j);
                List<String> str2 = ans.get(sub);
                for (String s1 : str1) {
                    for (String s2 : str2) {
                        tmp.add("(" + s1 + ")" + s2);
                    }
                }

            }
            ans.add(tmp);
        }

        return ans.get(n);
    }

}
