package Leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {

        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        int len = nums.length;

        for (int l = 0; l < len - 3; l++) {
            if (l > 0 && nums[l] == nums[l - 1])
                continue;

            int minl = nums[l] + nums[l + 1] + nums[l + 2] + nums[l + 3];
            if (minl > target)//如果当前最小值都比target大，则直接退出遍历
                break;
            int maxl = nums[l] + nums[len - 3] + nums[len - 2] + nums[len - 1];
            if (maxl < target)//如果当前最大值都比target小，则进入下个循环
                continue;

            int tmptarget = target - nums[l];
            for (int k = l + 1; k < len - 2; k++) {
                if (k > l + 1 && nums[k] == nums[k - 1])
                    continue;

                int mink = nums[k] + nums[k + 1] + nums[k + 2];
                if (mink > tmptarget)
                    break;
                int maxk = nums[k] + nums[len - 1] + nums[len - 2];
                if (maxk < tmptarget)
                    continue;

                int i = k + 1, j = nums.length - 1;
                while (i < j) {

                    int sum = nums[k] + nums[i] + nums[j];
                    if (sum == tmptarget) {
                        ans.add(Arrays.asList(nums[l], nums[k], nums[i], nums[j]));
                    }
                    if (sum < tmptarget || sum == tmptarget) {
                        do {
                            i++;
                        } while (i < j && nums[i] == nums[i - 1]);
                    }
                    if (sum > tmptarget || sum == tmptarget) {
                        do {
                            j--;
                        } while (i < j && nums[j] == nums[j + 1]);
                    }

                }

            }
        }

        return ans;
    }
}