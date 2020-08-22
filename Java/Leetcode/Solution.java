package Leetcode;

import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

import java.util.Iterator;

import java.util.Deque;
import java.util.LinkedList;

import java.util.List;
import java.lang.reflect.Array;
import java.util.ArrayList;

import java.util.Map;
import java.util.HashMap;

import java.util.PriorityQueue;
import java.util.Queue;

import java.util.Set;
import java.util.TreeSet;
import java.util.HashSet;

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

class Solution {

    public static void main(String[] args) {
        int a = threeSumClosest(new int[] { 1, 2, 5, 10, 11 }, 12);
        System.out.println(a);
    }

    public static int threeSumClosest(int[] nums, int target) {

        Arrays.sort(nums);
        int len = nums.length;
        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < len - 2; i++) {
            int left = i + 1, right = len - 1;
            int sum = 0;

            while (left < right) {
                sum = nums[left] + nums[right] + nums[i];
                if (Math.abs(ans - target) > Math.abs(sum + nums[i] - target))
                    ans = sum + nums[i];
                if (sum > target)
                    right--;
                else if (sum < target)
                    left++;
                else
                    return target;
            }
        }

        return ans;

    }
}
