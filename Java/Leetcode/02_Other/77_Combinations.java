import java.util.ArrayList;
import java.util.List;

class Combinations {

    static List<List<Integer>> ans;

    public List<List<Integer>> combine(int n, int k) {

        ans = new ArrayList<>();
        if (n < 1)
            return ans;

        reCur(1, n, k, new ArrayList<Integer>());
        return ans;
    }

    public static void reCur(int i, int n, int k, List<Integer> tmp) {

        if (k == 0) {
            ans.add(new ArrayList<Integer>(tmp));
            return;
        }
        for (int j = i; j <= n && (k <= n - i + 1); j++) {
            tmp.add(j);
            reCur(j + 1, n, k - 1, tmp);
            tmp.remove(tmp.size() - 1);
        }

        return;
    }

}
