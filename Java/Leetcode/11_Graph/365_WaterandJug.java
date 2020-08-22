
import java.util.Deque;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Set;

class WaterandJug {

    public boolean canMeasureWater(int x, int y, int z) {
        if (z < 0 || z > x + y)
            return false;

        Set<Integer> sum = new HashSet<>();
        Deque<Integer> q = new LinkedList<>();
        q.offer(0);
        while (!q.isEmpty()) {
            int n = q.poll();
            if (n + x <= x + y && sum.add(n + x))
                q.offer(n + x);

            if (n + y <= x + y && sum.add(n + y))
                q.offer(n + y);

            if (n - x >= 0 && sum.add(n - x))
                q.offer(n - x);

            if (n - y >= 0 && sum.add(n - y))
                q.offer(n - y);

            if (sum.contains(z))
                return true;
        }

        return false;

    }

}