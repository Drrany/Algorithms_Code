
import java.util.Deque;
import java.util.LinkedList;

class RemoveKDigits {

    public static String removeKdigits(String num, int k) {

        if (num.length() <= k)
            return "0";

        Deque<Integer> s = new LinkedList<>();
        s.push(-1);
        for (char c : num.toCharArray()) {
            int n = (int) (c - '0');
            while(n < s.peek() && k > 0) {
                s.pop();
                k--;
            }
            s.push(n);
        }
        while (k > 0) {
            s.pop();
            k--;
        }

        StringBuilder ans = new StringBuilder();
        while (s.peek() != -1)
            ans.append(s.pop());
        int l = ans.length() - 1;
        while (l > 0 && ans.charAt(l) == '0')
            ans.deleteCharAt(l--);

        return ans.reverse().toString();
    }

}