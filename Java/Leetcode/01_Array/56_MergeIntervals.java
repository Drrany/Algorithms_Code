package Leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class MergeInterval {

    public static void main(String[] args) {
        int[][] intervals={
            {1,4},{0,2},{3,5}
        };
        merge(intervals);
    }

    public static int[][] merge(int[][] intervals) {

        int len = intervals.length;
        if (len < 2)
            return intervals;
        List<int[]> ans = new ArrayList<>();
        Arrays.sort(intervals, (x, y) -> x[0] - y[0]);//排序

        int i = 0;
        int n = 0;
        while (i < len) {

            int[] a = new int[2];

            a[0] = intervals[i][0];//因为第一个元素已经排好序了，所以a[0]可确定

            int j = i + 1;
            a[1] = intervals[i][1];
            while (j < len && a[1] >= intervals[j][0]) {//如果后一个数组的b[0]小于a[1]
                j++;
                a[1] = Math.max(a[1],intervals[j - 1][1]);//a[1]更新为a[1]和b[1]中较大的那个
            }
            n++;
            i = j;

            ans.add(a);
        }

        return ans.toArray(new int[n][]);

    }

}
