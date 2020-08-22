

import java.util.Arrays;

class Non_overlappingIntervals {

    
    public static int eraseOverlapIntervals(int[][] intervals) {

        int num = intervals.length;
        if (intervals == null || num < 1)
            return 0;

        Arrays.sort(intervals, (o1, o2) -> Integer.compare(o1[0], o2[0]));

        int count = 1;
        int minend = intervals[0][1];
        for (int i = 1; i < num; i++) {
            if (intervals[i][0] >= minend) {
                count++;
                minend = intervals[i][1]; 
            }else 
                minend = Math.min(minend, intervals[i][1]);
        }

        return num - count;

    }

}