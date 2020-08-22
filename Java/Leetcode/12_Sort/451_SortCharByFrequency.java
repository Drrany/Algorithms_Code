
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

class SortCharByFrequency {

    
    public String frequencySort(String s) {

        int len = s.length();
        Map<Character, Integer> times = new HashMap<>();
        StringBuilder ans = new StringBuilder();

        for (char c : s.toCharArray())
            times.put(c, times.getOrDefault(c, 0) + 1);

        ArrayList<Character>[] bo = new ArrayList[len + 1];

        for (char c : times.keySet()) {
            int m = times.get(c);
            if (bo[m] == null)
                bo[m] = new ArrayList<Character>();
            bo[m].add(c);
        }

        for (int i = len; i >= 0; i--) {
            if (bo[i] != null) {
                for (char c : bo[i]) {
                    for (int j = 0; j < i; j++)
                        ans.append(c);
                }

            }

        }

        return ans.toString();

    }


}