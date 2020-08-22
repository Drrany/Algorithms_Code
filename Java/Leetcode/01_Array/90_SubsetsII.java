package Leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class SubsetTwo {

    public List<List<Integer>> subsetsWithDup(int[] nums) {

        List<List<Integer>> ans = new ArrayList<>();
        ans.add(new ArrayList<>());
        Arrays.sort(nums);//先排序保证相同元素相邻
        int left = 0, right = 1, len = 0;

        for (int i = 0; i < nums.length; i++) {
            List<List<Integer>> ans_tmp = new ArrayList<>();

            if (i > 0 && nums[i] == nums[i - 1])//如果和前一个元素相同
                left = ans.size() - len;//从上一个新解添加的位置开始
            else
                left = 0;//否则从0开始

            right = ans.size();
            len = right - left;

            for (int j = left; j < right; j++) {
                List<Integer> tmp = new ArrayList<>(ans.get(j));
                tmp.add(nums[i]);
                ans_tmp.add(tmp);
            }

            ans.addAll(ans_tmp);
        }

        return ans;

    }

}
