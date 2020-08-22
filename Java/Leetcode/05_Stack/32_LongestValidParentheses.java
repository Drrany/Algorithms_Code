
import java.util.Deque;
import java.util.LinkedList;

class LongestValidParentheses {

    public int longestValidParentheses(String s) {

        Deque<Integer> stack = new LinkedList<>();
        int count = 0;
        stack.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(')
                stack.push(i);
            else {
                stack.pop();
                if (!stack.isEmpty())
                    count = Math.max(count, i - stack.peek());
                else 
                    stack.push(i);
            }
        }

        return count;
    }
    
}