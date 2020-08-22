
import java.util.Deque;
import java.util.LinkedList;

class AsteroidCollision {

    public int[] asteroidCollision(int[] asteroids) {

        Deque<Integer> s = new LinkedList<>();
        b1: for (int i : asteroids) {
            while (i < 0 && !s.isEmpty() && s.peek() > 0) {
                int tmp = s.peek();
                if (tmp <= -i)
                    s.pop();
                if (tmp >= -i)
                    continue b1;
            }
            s.push(i);
        }

        int len = s.size();
        int[] ans = new int[len];
        for (int i = len - 1; i >= 0; i--)
            ans[i] = s.pop();

        return ans;
    }

}