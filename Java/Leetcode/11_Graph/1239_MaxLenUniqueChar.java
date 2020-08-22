
import java.util.Arrays;
import java.util.List;

class MaxLenUniqueChar {

    public int maxLength(List<String> arr) {

        return reCur(arr, 0, new int[26]);

    }

    public static int reCur(List<String> arr, int i, int[] times) {

        if (i >= arr.size())
            return 0;

        int next = reCur(arr, i + 1, Arrays.copyOf(times, 26));

        String tmp = arr.get(i);
        int ans = 0;
        for (char c : tmp.toCharArray()) {
            int index = c - 'a';
            if (times[index] != 0) {
                ans = 0;
                break;
            }
            times[index] = 1;
            ans++;
        }

        return Math.max(next, ans + reCur(arr, i + 1, times));

    }
    
}