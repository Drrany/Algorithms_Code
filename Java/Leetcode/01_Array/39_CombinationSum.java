package Leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

class Combination {

    public static void findCombination(List<List<Integer>> ans, int start, int target, int[] candidates,
            Stack<Integer> pre) {

        if (target == 0) {
            ans.add(new ArrayList<Integer>(pre));// 直接加pre的话，当pre中的值变化时ans中的值也会变化，因此需要先将值复制一份再直接传递值
            return;
        }

        for (int i = start; i < candidates.length && target - candidates[i] >= 0; i++) {

            pre.push(candidates[i]);
            findCombination(ans, i, target - candidates[i], candidates, pre);
            pre.pop();

        }
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {

        List<List<Integer>> ans = new ArrayList<>();

        Arrays.sort(candidates);
        Stack<Integer> pre = new Stack<>();
        findCombination(ans, 0, target, candidates, pre);
        return ans;

    }

}