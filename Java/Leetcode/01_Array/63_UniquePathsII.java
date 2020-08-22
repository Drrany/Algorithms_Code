package Leetcode;

class PathTwo {

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {

        if (obstacleGrid == null || obstacleGrid[0][0] == 1)
            return 0;

        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        boolean row_flag = false;
        boolean column_flag = false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (obstacleGrid[i][j] == 1) {

                    obstacleGrid[i][j] = 0;
                    if (i == 0)
                        row_flag = true;
                    if (j == 0)
                        column_flag = true;

                } else if (i == 0 || j == 0) {

                    if (row_flag && i == 0 || column_flag && j == 0)
                        obstacleGrid[i][j] = 0;
                    else
                        obstacleGrid[i][j] = 1;

                } else
                    obstacleGrid[i][j] = obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j];
            }
        }

        return obstacleGrid[m - 1][n - 1];

    }

}
