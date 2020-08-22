

import java.util.Map;
import java.util.HashMap;

class MinNumofFrogs {

    
    public static int minNumberOfFrogs(String croakOfFrogs) {

        Map<Character, Integer> sample = new HashMap<>();
        sample.put('c', 1);
        sample.put('r', 2);
        sample.put('o', 3);
        sample.put('a', 4);
        sample.put('k', 5);
        int[] count = new int[6];
        int max = 0;

        for (char c : croakOfFrogs.toCharArray()) {
            count[sample.get(c)]++;
            max = Math.max(max, count[1]);
            if (!(count[1] >= count[2] && count[2] >= count[3] && count[3] >= count[4] && count[4] >= count[5]))
                return -1;
            if (sample.get(c) == 5) {
                for (int i = 1; i < 6; i++)
                    count[i]--;
            }
        }

        int tmp = 0;
        for (int i : count) {
            tmp += i;
        }

        return tmp > 0 ? -1 : max;
    }
    
}