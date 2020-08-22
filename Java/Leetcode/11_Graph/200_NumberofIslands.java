

class NumberofIslands {

    public int numIslands(char[][] grid) {

        if (grid == null || grid.length < 1)
            return 0;

        int count = 0;
        int rows = grid.length;
        int columns = grid[0].length;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    replace1(grid, i, j, rows, columns);
                }
            }
        }

        return count;

    }

    public static void replace1(char[][] grid, int i, int j, int rows, int columns) {

        if (i < 0 || j < 0 || i >= rows || j >= columns || grid[i][j] == 'X' || grid[i][j] == '0')
            return;

        grid[i][j] = 'X';
        replace1(grid, i - 1, j, rows, columns);
        replace1(grid, i + 1, j, rows, columns);
        replace1(grid, i, j - 1, rows, columns);
        replace1(grid, i, j + 1, rows, columns);

        return;
    }

}