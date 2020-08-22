
import java.util.Deque;
import java.util.LinkedList;

class DailyTemperatures {
    
    public int[] dailyTemperatures(int[] T) {

        int len = T.length;
        int[] ans = new int[len];
        Deque<Integer> s = new LinkedList<>();

        int i = 0;
        while (i < len) {
            while (!s.isEmpty() && T[s.peek()] < T[i])
                ans[s.peek()] = i - s.pop();
            s.push(i);
            i++;
        }

        while (!s.isEmpty())
            ans[s.pop()] = 0;

        return ans;

    }

}