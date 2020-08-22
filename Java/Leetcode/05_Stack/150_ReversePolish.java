
import java.util.Deque;
import java.util.LinkedList;

class ReversePolish {
    public int evalRPN(String[] tokens) {

        Deque<Integer> s = new LinkedList<>();

        int a = 0, b = 0;
        for (String sr : tokens) {
            switch (sr) {
                case "+":
                    a = s.pop();
                    b = s.pop();
                    s.push(a + b);
                    break;
                case "-":
                    a = s.pop();
                    b = s.pop();
                    s.push(b - a);
                    break;
                case "*":
                    a = s.pop();
                    b = s.pop();
                    s.push(a * b);
                    break;
                case "/":
                    a = s.pop();
                    b = s.pop();
                    s.push(b / a);
                    break;
                default:
                    s.push(Integer.parseInt(sr));
                    break;
            }

        }

        return s.pop();

    }

}