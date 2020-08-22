package Leetcode;

import java.util.ArrayList;
import java.util.List;

class InsertInterval {

    public int[][] insert(int[][] intervals, int[] newInterval) {

        List<int[]> ans = new ArrayList<>();
        int n = 0;
        int len = intervals.length;
        int i = 0;
        if (len < 1) {//如果intervals为空，直接返回插入区间
            ans.add(newInterval);
            return ans.toArray(new int[1][]);
        }

        while (i < len) {

            int[] a = new int[2];
            a[0] = intervals[i][0];
            a[1] = intervals[i][1];

            if (newInterval[0] >= a[0] && newInterval[0] <= a[1]) {//如果插入区间左侧位于第i个区间中间

                while (i < len - 1 && newInterval[1] >= intervals[i + 1][0]) {
                    i++;
                    a[1] = Math.max(a[1], intervals[i][1]);
                }

                a[1] = Math.max(newInterval[1], a[1]);

            } else if (newInterval[0] < a[0]) {//若插入区间左侧位于第i个区间右侧

                if ((i > 0 && newInterval[0] > intervals[i - 1][1]) || (i == 0)) {//若插入区间左侧位于第i-1和第i个区间之间

                    if (newInterval[1] < a[0]) {//若插入区间右侧也位于第i个区间右侧，将插入区间加入数组
                        int[] b = { newInterval[0], newInterval[1] };
                        ans.add(b);
                    } else {//否则其有重叠部分

                        a[0] = newInterval[0];
                        while (i < len - 1 && newInterval[1] >= intervals[i + 1][0]) {
                            i++;
                            a[1] = Math.max(a[1], intervals[i][1]);
                        }

                        a[1] = Math.max(newInterval[1], a[1]);
                    }
                }

            } else if (i == len - 1 && newInterval[0] > a[1]) {//若插入区间左侧大于最后一个区间右侧，将插入区间加入数组
                int[] b = { newInterval[0], newInterval[1] };
                ans.add(a);
                ans.add(b);
                n += 2;
                break;
            }

            ans.add(a);
            i++;
            n++;

        }

        return ans.toArray(new int[n][]);

    }

}
