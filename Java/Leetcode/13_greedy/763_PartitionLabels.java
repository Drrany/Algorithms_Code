
import java.util.ArrayList;
import java.util.List;

class PartitionLabels {

    public static List<Integer> partitionLabels(String S) {

        List<Integer> ans = new ArrayList<>();
        int[] last = new int[26];
        // 终止位置

        for (int i = 0; i < S.length(); i++) {
            int n = S.charAt(i) - 'a';
            last[n] = i;
        }

        int i = 0, start = 0;
        while (i < S.length()) {

            int end = last[S.charAt(i) - 'a'];
            while (i < end) {
                end = Math.max(end, last[S.charAt(i) - 'a']);
                i++;
            }

            end++;
            i++;
            ans.add(end - start);
            start = end;
        }

        return ans;
    }

}