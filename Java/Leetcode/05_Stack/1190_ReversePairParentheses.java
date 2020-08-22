
import java.util.Deque;
import java.util.LinkedList;

class ReversePairParentheses {

    public static String reverseParentheses(String s) {

        Deque<Character> stack = new LinkedList<>();
        for (char c : s.toCharArray()) {
            if (c == ')') {
                StringBuilder tmp = new StringBuilder();
                while (stack.peek() != '(')
                    tmp.append(stack.pop());
                stack.pop();
                for (int i = 0; i < tmp.length(); i++)
                    stack.push(tmp.charAt(i));
            } else
                stack.push(c);
        }
        
        StringBuilder ans = new StringBuilder();
        while (!stack.isEmpty()) {
            ans.append(stack.pop());
        }

        return ans.reverse().toString();

    }
    
}