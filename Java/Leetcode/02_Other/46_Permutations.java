
import java.util.ArrayList;
import java.util.List;


class Permutation {

    static List<List<Integer>> ans;
    static int[] nums;

    public List<List<Integer>> permute(int[] nums) {

        ans = new ArrayList<>();
        this.nums = nums;
        int len = nums.length;
        if (len < 1)
            return ans;
        boolean[] flag = new boolean[len];

        reCur(0, len, flag, new ArrayList<Integer>());
        return ans;
    }

    public static void reCur(int i, int len, boolean[] flag, List<Integer> tmp) {

        if (i == len ) {
            ans.add(new ArrayList<Integer>(tmp));
            return;
        }
        for (int j = 0; j < len; j++) {
            if (flag[j])
                continue;
            flag[j] = true;
            tmp.add(nums[j]);
            reCur(i + 1, len, flag, tmp);
            flag[j] = false;
            tmp.remove(tmp.size() - 1);
        }

        return;
    }

}
