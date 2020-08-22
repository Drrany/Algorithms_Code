
import java.util.Deque;
import java.util.LinkedList;

class ParenthesesValid {

    public int minAddToMakeValid(String S) {

        Deque<Character> s = new LinkedList<>();
        for (Character c : S.toCharArray()) {

            if (c.equals(')') && !s.isEmpty() && s.peek() == '(')
                s.pop();
            else
                s.push(c);

        }

        return s.size();
    }

}