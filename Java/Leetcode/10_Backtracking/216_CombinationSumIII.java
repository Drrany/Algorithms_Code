

import java.util.ArrayList;
import java.util.List;

class CombinationSumIII {

    static List<List<Integer>> ans;

    public List<List<Integer>> combinationSum3(int k, int n) {

        ans = new ArrayList<>();
        if (n < k || n > k * 9)
            return ans;

        reCur(k, n, 1, new ArrayList<Integer>());
        return ans;
    }

    public static void reCur(int k, int rest, int start, List<Integer> path) {

        if (k == 0 && rest == 0) {
            ans.add(new ArrayList<>(path));
            return;
        }

        for (int i = start; i <= 9 && i <= rest && k > 0; i++) {

            path.add(i);
            reCur(k - 1, rest - i, i + 1, path);
            path.remove(path.size() - 1);

        }

        return;

    }

}