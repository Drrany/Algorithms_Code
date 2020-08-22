package Leetcode;

import java.util.ArrayList;
import java.util.List;

class Subsets{

    public static void main(String[] args) {

        int[] nums = { 1, 2, 3 };
        List<List<Integer>> a = subsets2(nums);
        System.out.println(a.toArray());

    }

    public static List<List<Integer>> subsets2(int[] nums) {

        List<List<Integer>> ans = new ArrayList<>();

        int len = nums.length;
        int n = 1 << len;
        for (int i = 0; i < n; i++) {

            List<Integer> tmp = new ArrayList<>();
            
            for (int j = 0; j < len; j++) {
                if (((i >> j) & 1) == 1) {
                    tmp.add(nums[j]);
                }

            }
            ans.add(tmp);
        }

        return ans;

    }

    public static List<List<Integer>> subsets(int[] nums) {

        List<List<Integer>> ans = new ArrayList<>();

        int len = nums.length;
        ans.add(new ArrayList<Integer>());

        for (int i = 0; i < len; i++) {

            int n = ans.size();

            for (int j = 0; j < n; j++) {

                List<Integer> tmp = new ArrayList<>(ans.get(j));
                tmp.add(nums[i]);
                ans.add(tmp);

            }

        }

        return ans;

    }

}