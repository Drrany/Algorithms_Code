

class MaxAreaofIsland {

    public static void main(String[] args) {
        int[][] grid = { { 1, 1, 0, 0, 0 }, { 1, 1, 0, 0, 0 }, { 0, 0, 0, 1, 1 }, { 0, 0, 0, 1, 1 } };

        int max = maxAreaOfIsland(grid);
        System.out.println(max);
    }

    public static int maxAreaOfIsland(int[][] grid) {

        if (grid == null || grid.length < 1)
            return 0;

        int rows = grid.length;
        int columns = grid[0].length;

        int maxarea = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] != 0) {
                    maxarea = Math.max(maxarea, reCur(i, j, grid, rows, columns));
                }
            }
        }

        return maxarea;

    }

    public static int reCur(int i, int j, int[][] grid, int rows, int columns) {

        if (i < 0 || j < 0 || i >= rows || j >= columns || grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;
        int num = 1;
        num += reCur(i - 1, j, grid, rows, columns);
        num += reCur(i + 1, j, grid, rows, columns);
        num += reCur(i, j - 1, grid, rows, columns);
        num += reCur(i, j + 1, grid, rows, columns);

        return num;

    }

}