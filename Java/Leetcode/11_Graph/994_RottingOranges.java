
import java.util.Deque;
import java.util.LinkedList;

class RottingOranges {

    public static int orangesRotting(int[][] grid) {

        if (grid.length < 1)
            return 0;

        int rows = grid.length;
        int columns = grid[0].length;
        Deque<int[]> q = new LinkedList<>();
        int onecount = 0, depth = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == 1)
                    onecount++;
                else if (grid[i][j] == 2)
                    q.offer(new int[] { i, j });
            }
        }

        while (onecount > 0 && !q.isEmpty()) {
            int n = q.size();
            depth++;
            for (int i = 0; i < n; i++) {
                int[] tmp = q.poll();

                int left = tmp[1] - 1, right = tmp[1] + 1;
                int up = tmp[0] - 1, down = tmp[0] + 1;

                if (left >= 0 && grid[tmp[0]][left] == 1) {
                    grid[tmp[0]][left] = 2;
                    q.offer(new int[] { tmp[0], left });
                }

                if (right < columns && grid[tmp[0]][right] == 1) {
                    grid[tmp[0]][right] = 2;
                    q.offer(new int[] { tmp[0], right });
                }

                if (down < rows && grid[down][tmp[1]] == 1) {
                    grid[down][tmp[1]] = 2;
                    q.offer(new int[] { down, tmp[1] });
                }

                if (up >= 0 && grid[up][tmp[1]] == 1) {
                    grid[up][tmp[1]] = 2;
                    q.offer(new int[] { up, tmp[1] });
                }

            }
            onecount -= q.size();

        }

        return onecount > 0 ? -1 : depth;

    }
    
}