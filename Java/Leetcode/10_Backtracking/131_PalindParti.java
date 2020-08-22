

import java.util.ArrayList;
import java.util.List;



class PalindPart {

    public static void main(String[] args) {
        partition("aab");
    }

    static List<List<String>> ans;
    static boolean[][] isp;

    public static List<List<String>> partition(String s) {

        ans = new ArrayList<>();
        int len = s.length();
        isp = new boolean[len][len];

        for (int right = 0; right < len; right++) {
            for (int left = 0; left <= right; left++) {
                if (s.charAt(right) == s.charAt(left) && (right - left < 2 || isp[right - 1][left + 1]))
                    isp[right][left] = true;
            }
        }

        reCur(s, 0, len, new ArrayList<String>());
        return ans;

    }

    public static void reCur(String s, int left, int len, List<String> par) {

        if (left == len) {
            ans.add(new ArrayList<>(par));
            return;
        }

        for (int i = left + 1; i <= len; i++) {

            if (isp[i - 1][left]) {
                par.add(s.substring(left, i));
                reCur(s, i, len, par);
                par.remove(par.size() - 1);
            }

        }

        return;
    }

}
