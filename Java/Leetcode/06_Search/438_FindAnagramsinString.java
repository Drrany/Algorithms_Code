
import java.util.ArrayList;
import java.util.List;

class FindAnagramsinString {

    public static List<Integer> findAnagrams(String s, String p) {

        List<Integer> ans = new ArrayList<>();
        int slen = s.length();
        int plen = p.length();
        int[] ptimes = new int[26];
        int[] stimes = new int[26];

        for (char c : p.toCharArray())
            ptimes[c - 'a']++;
        
        int left = 0, right = 0, total = plen;

        while (right < slen) {
            int r = s.charAt(right) - 'a';
            stimes[r]++;
            if (ptimes[r] >= stimes[r])
                total--;

            while (total == 0) {
                if (right - left + 1 == plen)
                    ans.add(left);
                int l = s.charAt(left) - 'a';
                stimes[l]--;
                if (ptimes[l] > stimes[l])
                    total++;
                left++;
            }

            right++;
        }

        return ans;

    }

}