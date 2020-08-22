package Leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

class CombinationTwo {

    public static void findCombination(List<List<Integer>> ans, int start, int target, int[] candidates,
            Stack<Integer> pre) {

        if (target == 0) {
            ans.add(new ArrayList<Integer>(pre));
            return;
        }

        for (int i = start; i < candidates.length && target - candidates[i] >= 0; i++) {

            if (i > start && candidates[i] == candidates[i - 1])//当同级出现相同元素时直接跳过
                continue;

            pre.push(candidates[i]);
            findCombination(ans, i + 1, target - candidates[i], candidates, pre);//这里从i+1开始
            pre.pop();

        }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {

        List<List<Integer>> ans = new ArrayList<>();

        Arrays.sort(candidates);
        Stack<Integer> pre = new Stack<>();
        findCombination(ans, 0, target, candidates, pre);

        return ans;

    }

    public static void main(String[] args) {
        List<List<Integer>> ans = new ArrayList<>();
        text t = new text();
        int[] candidates = { 1, 2, 2, 5, 5 };
        int target = 8;
        ans = t.combinationSum2(candidates, target);
        System.out.println(ans);
    }

}