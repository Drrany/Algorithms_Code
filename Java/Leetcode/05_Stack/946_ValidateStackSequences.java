


import java.util.Deque;
import java.util.LinkedList;

class ValidateStackSequences {

    public boolean validateStackSequences(int[] pushed, int[] popped) {

        int len = pushed.length;

        Deque<Integer> s = new LinkedList<>();
        int j = 0;
        for (int i = 0; i < len; i++) {
            if (popped[j] == pushed[i]) {
                j++;
                while (!s.isEmpty() && j < len && s.peek() == popped[j]) {
                    s.pop();
                    j++;
                }
                continue;
            }
            s.push(pushed[i]);
        }

        return s.isEmpty();
    }
    
}