

import java.util.Deque;
import java.util.LinkedList;

class DecodeString {

    public static String decodeString(String s) {

        StringBuilder ans = new StringBuilder();
        Deque<String> st = new LinkedList<>();
        Deque<Integer> ct = new LinkedList<>();
        int count = 0;

        for (char c : s.toCharArray()) {

            if ((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z'))
                st.push(String.valueOf(c));
            else if (c == ']') {
                StringBuilder tmp = new StringBuilder();
                while (!st.peek().equals("["))
                    tmp.append(st.pop());
                st.pop();
                int times = ct.pop();
                while (times-- > 0)
                    st.push(tmp.toString());
            } else if (c == '[') {
                st.push(String.valueOf(c));
                ct.push(count);
                count = 0;
            } else
                count = count * 10 + (int) (c - '0');

        }

        while (!st.isEmpty())
            ans.append(st.pop());

        return ans.reverse().toString();

    }

}