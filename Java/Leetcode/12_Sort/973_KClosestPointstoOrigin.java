
import java.util.PriorityQueue;
import java.util.Queue;

class KClosestPointstoOrigin {

    public int[][] kClosest(int[][] points, int K) {

        int[][] ans = new int[K][2];
        Queue<int[]> pq = new PriorityQueue<>(K, (o1,o2)->Integer.compare(o1[0] * o1[0] + o1[1] * o1[1], o2[0] * o2[0] + o2[1] * o2[1]));

        for (int[] po : points)
            pq.offer(po);

        for (int i = 0; i < K; i++)
            ans[i] = pq.poll();

        return ans;
    }
    
}