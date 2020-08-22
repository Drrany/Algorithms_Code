

import java.util.Deque;
import java.util.LinkedList;

class FarLand {

    public int maxDistance(int[][] grid) {

        int n = grid.length;
        Deque<int[]> q = new LinkedList<>();
        int count = 0;// 海洋数量
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.offer(new int[] { i, j });
                } else
                    count++;
            }
        }

        if (count == 0 || count == n * n)
            return -1;

        int depth = 0;
        while (!q.isEmpty() && count > 0) {

            depth++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int[] tmp = q.poll();
                int up = tmp[0] - 1, down = tmp[0] + 1;
                int left = tmp[1] - 1, right = tmp[1] + 1;

                if (up >= 0 && grid[up][tmp[1]] == 0) {
                    grid[up][tmp[1]] = depth;
                    q.offer(new int[] { up, tmp[1] });
                    count--;
                }

                if (down < n && grid[down][tmp[1]] == 0) {
                    grid[down][tmp[1]] = depth;
                    q.offer(new int[] { down, tmp[1] });
                    count--;
                }

                if (left >= 0 && grid[tmp[0]][left] == 0) {
                    grid[tmp[0]][left] = depth;
                    q.offer(new int[] { tmp[0], left });
                    count--;
                }

                if (right < n && grid[tmp[0]][right] == 0) {
                    grid[tmp[0]][right] = depth;
                    q.offer(new int[] { tmp[0], right });
                    count--;
                }
            }

        }

        return depth;

    }
    
}