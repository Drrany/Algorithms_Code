
import java.util.Arrays;

class TaskScheduler {

    public static int leastInterval(char[] tasks, int n) {

        if (n == 0 || tasks.length <= 1)
            return tasks.length;

        int[] times = new int[26];

        for (char c : tasks)
            times[c - 'A']++;

        Arrays.sort(times);

        int count = (times[25] - 1) * (n + 1) + 1;
        int i = 24;
        while (i >= 0 && times[i] != 0 && times[i] == times[i + 1]) {
            count++;
            i--;
        }

        return Math.max(count, tasks.length);

    }

}